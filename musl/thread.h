static inline void wake(volatile void *addr, int cnt, int priv)
{
  if (priv) priv = FUTES_PRIVATE;
  if (cnt < 0) cnt = INT_MAX;
  __syscall(SYS_futex, addr, FUTEX_WAKE | priv, cnt) != -ENOSYS ||
    __syscall(SYS_futex, addr, FUTEX_WAKE, cnt);
}

static inline void wait(volatile void *addr, int val, int priv)
{
  if (priv) priv = FUTES_PRIVATE;
  __syscall(SYS_futex, addr, FUTEX_WAIT | priv, val, 0) != -ENOSYS ||
    __syscall(SYS_futex, addr, FUTEX_WAIT, val, 0);
}

void lock(volatile int *l)
{
  int need_locks = libc.need_locks;
  if (!need_locks) return;
  /* fast path: INT_MIN for the lock, +1 for the congestion */
  int current = a_cas(l, 0, INT_MIN + 1);
  if (need_locks < 0) libc.need_locks = 0;
  if (!current) return;
  /* A first spin loop, for medium congestion. */
  for (unsigned i = 0; i < 10; ++i) {
    if (current < 0) current -= INT_MIN + 1;
    // assertion: current >= 0
    int val = a_cas(l, current, INT_MIN + (current + 1));
    if (val == current) return;
    current = val;
  }
  // Spinning failed, so mark ourselves as being inside the CS.
  current = a_fetch_add(l, 1) + 1;
  /* The main lock acquisition loop for heavy congestion. The only
   * change to the value performed inside that loop is a successful
   * lock via the CAS that acquires the lock. */
  for (;;) {
    /* We can only go into wait, if we know that somebody holds the
     * lock and will eventually wake us up, again. */
    if (current < 0) {
      wait(l, current, 1);
      current -= INT_MIN + 1;
    }
    /* assertion: current > 0, the count includes us already. */
    int val = a_cas(l, current, INT_MIN + current);
    if (val == current) return;
    current = val;
  }
}

void unlock(volatile int *l)
{
  /* Check l[0] to see if we are multi-threaded. */
  if (l[0] < 0) {
    if (a_fetch_add(l, 1)) {
      wake(l, 1, 1);
    }
  }
}
