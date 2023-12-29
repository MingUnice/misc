#define EOF (-1)

static FILE *ofl_head;
static volatile int ofl_lock[1];

typedef struct _IO_FILE FILE;

struct _IO_FILE {
  unsigned flags;
  unsigned char *rpos, *rend;
  int (*close)(FILE *);
  unsigned char *wend, *wpos;
  unsigned char *mustbezero_1;
  unsigned char *wbase;
  size_t (*read)(FILE *, unsigned char *, size_t);
  size_t (*write)(FILE *, const unsigned char *, size_t);
  off_t (*seek)(FILE *, off_t, int);
  unsigned char *buf;
  size_t buf_size;
  FILE *prev, *next;
  int fd;
  int pipe_pid;
  long lockcount;
  short dummy3;
  signed char mode;
  signed char lbf;
  int lock;
  int waiters;
  void *cookie;
  off_t off;
  char *getln_buf;
  void *mustbezero_2;
  unsigned char *shend;
  off_t shlim, shcnt;
};

FILE *ofl_add(FILE *f)
{
  lock(ofl_lock);
  FILE **head = &ofl_head;
  f->next = *head;
  if (*head) (*head)->prev = f;
  *head = f;
  unlock(ofl_lock);
  return f;
}


FILE *fdopen(int fd, const char *mode)
{
  FILE *f;
  if (!strchr("rwa", *mode)) {
    errno = EINVAL;
    return 0;
  }
  if (!(f = malloc(sizeof(FILE) + 8 + 1024)))
    return 0;
  memset(f, 0, sizeof(FILE));
  if (!strchr(mode, '+')) f->flags = (*mode == 'r') ? F_NOWR : F_NORD;
  if (strchr(mode, 'e')) __syscall(SYS_fcntl, fd, F_SETFD, FD_CLOEXEC);
  if (*mode == 'a') {
    int flags = __syscall(SYS_fcntl, fd, F_GETFL);
    if (!(flags & O_APPEND))
      __syscall(SYS_fcntl, fd, F_SETFL, flags | O_APPEND);
    f->flags |= F_APP;
  }
  f->fd = fd;
  f->buf = (unsigned char *)f + sizeof *f + 8;
  f->buf_size = 1024;
  
  // line buffered
  f->lbf = EOF;
  if (!(f->flags & F_NOWR) && !__syscall(SYS_ioctl, fd, TIOCGWINSZ, &wsz))
    f->lbf = '\n';
  
  f->read = __stdio_read;
  f->write = __stdio_write;
  f->seek = __stdio_seek;
  f->close = __stdio_close;
  
  if (!libc.threaded) f->lock = -1;
  return ofl_add(f);
}

FILE *fopen(const char *restrict filename, const char *restrict mode)
{
  FILE *f;
  int fd;
  int flags;
  if (!strchr("rwa", *mode)) {
    errno = EINVAL;
    return 0;
  }
  flags = fmodeflags(mode);
  fd = sys_open(filename, flags, 0666);
  if (fd < 0) return 0;
  if (flags & O_CLOEXEC)
    __syscall(SYS_fcntl, fd, fd, F_SETFD, FD_CLOEXEC);
  f = fdopen(fd, mode);
}
