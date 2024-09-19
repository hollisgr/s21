#include "s21_strerror.h"

#include "s21_string.h"

char *s21_strerror(int errnum) {
  // return (char *)strerrors[errnum];
  const char **strerror;  // A pointer to the appropriate array of error strings

#if defined(__APPLE__)
  strerror = strerrors;
#elif defined(__linux__)
  strerror = strerrors;
#endif

  return (char *)strerror[errnum];
}
