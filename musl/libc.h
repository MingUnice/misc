struct libc {
  char can_do_threads;
  char threaded;
  char secure;
  volatile signed char need_locks;
  int threads_minus_1;
  size_t *auxv;
  struct tls_module *tls_head;
  size_t tls_size, tls_align, tls_cnt;
  size_t page_size;
  struct __locale_struct global_locale;
};
