#ifndef __UTILS_H__
#define __UTILS_H__

#define container_of(ptr, type, member)                         \
  ({                                                            \
    const __typeof__(((type *)NULL)->member) *__ptr = (ptr);    \
    (type *)((char *)__ptr - offsetof(type, member));           \
  })

#define access_once(x) (*(__volatile__ __typeof__(x) *)&(x))

#endif
