#include "string.h"

void *fmemchr(const void *s, unsigned char c, size_t n) {
  assert(s != NULL);
  assert(n);
  const unsigned char *ps = s;
  void *out = NULL;
  while (n--) {
    if (*ps == c) {
      out = (void *)ps;
      break;
    }
    ps++;
  }
  return out;
}

void *fmemcpy(void *dest, const void *src, size_t n) {
  assert(dest != NULL);
  assert(src != NULL);
  assert(n);
  unsigned char *pdest = dest;
  unsigned char *psrc = (void *)src;
  while (n--) {
    *pdest++ = *psrc++;
  }
  
  return dest;
}

void *fmemmove(void *dest, const void *src, size_t n) {
  assert(dest != NULL);
  assert(src != NULL);
  assert(n);
  unsigned char *psrc = (void *)src;
  unsigned char *pdest = dest;
  psrc += n;
  pdest += n;
  while (n--) {
    *--pdest = *--psrc;
  }
  return dest;
}

int fmemcmp(const void *s1, const void *s2, size_t n) {
  assert(s1 != NULL);
  assert(s2 != NULL);
  assert(n);
  int out = 0;
  if (s1 != s2) {
    const unsigned char *ps1 = s1;
    const unsigned char *ps2 = s2;
    while (n--) {
      if (*ps1 != *ps2) {
        out = (*ps1 - *ps2);
        break;
      }
      ps1++;
      ps2++;
    }
  }
  return out;
}

void *fmemset(void *s, unsigned char c, size_t n) {
  assert(s != NULL);
  unsigned char *pdest = s;
  while (n--) {
    *pdest++ = c;
  }
  return s;
}

char *fstrcat(char *dest, const char *src) {
  assert(dest != NULL);
  assert(src != NULL);
  char *pdest = dest;
  while (*pdest)
    pdest++;
  while (*src)
    *pdest++ = *src++;
  *pdest = '\0';

  return dest;
}

char *fstrncat(char *dest, const char *src, size_t n) {
  assert(dest != NULL);
  assert(src != NULL);
  char *pdest = dest;
  while (*pdest)
    pdest++;
  while (*src && n--) {
    *pdest++ = *src++;
  }
  *pdest = '\0';
  
  return dest;
}

char *fstrchr(const char *s, unsigned char c) {
  assert(s != NULL);
  char *out = NULL;
  while (*s) {
    if (*s == c) {
      out = (char *)s;
      break;
    }
    s++;
  }
  
  return out;
}

int fstrcmp(const char *s1, const char *s2) {
  assert(s1 != NULL);
  assert(s2 != NULL);
  int out = 0;
  if (s1 != s2) {
    const char *ps1 = s1;
    const char *ps2 = s2;
    while (*ps1 != '\0' && *ps2 != '\0') {
      if (*ps1 != *ps2) {
        out = (*ps1 - *ps2);
        break;
      }
      ps1++;
      ps2++;
    }
    if (out == 0 && ((*ps1 == '\0' && *ps2 != '\0') ||
      (*ps1 != '\0' && *ps2 == '\0'))) {
      out = *ps1 ? 1 : -1;
    } // helper function [TODO]
  }
  return out;
}

int fstrncmp(const char *s1, const char *s2, size_t n) {
  int out = 0;
  const char *ps1 = s1;
  const char *ps2 = s2;
  // helper function [check the '\0' after n bytes]
  while (n--) {
    if (*ps1 != *ps2) {
      out = (*ps1 - *ps2);
      break;
    }
    ps1++;
    ps2++;
  }
  return out;
}

int fstrcoll(const char *s1, const char *s2) {
  fstrcmp(s1, s2);
  // implement string collation [TODO]
}

char *fstrcpy(char *dest, const char *src) {
  assert(dest != NULL);
  assert(src != NULL);
  char *pdest = dest;
  while (*src != '\0') {
    *pdest++ = *src++;
  }
  *pdest = '\0';
  return dest;
}

char *fstrncpy(char *dest, const char *src, size_t n) {
  assert(dest != NULL);
  assert(src != NULL);
  assert(n);
  char *pdest = dest;
  size_t i = 0;
  for (; i < n && *src != '\0'; i++)
    *pdest++ = *src++;
  for (; i < n; i++)
    *pdest++ = '\0';
  return dest;
}

size_t fstrcspn(const char *s1, const char *s2) {
  assert(s1 != NULL);
  assert(s2 != NULL);
  unsigned char freq[] = { [UCHAR_MAX + 1] = 0 };
  const unsigned char *i = (const unsigned char *)s2;
  while (*i)
    freq[*i++] = 1;
  for (i = (const unsigned char *)s1; !freq[*i] && *i != '\0'; i++); 
  return (size_t)(i - (const unsigned char *)s1);
}

char *fstrerror(int errnum) {
  char *errors[8] = {
    "No error",
    "Operation not permitted",
    "No such file or directory",
    "Input/output error",
    "Invalid argument",
    "Permission denied",
    "File exists",
    "Unknown error"
  };
  char *out = NULL;
  switch (errnum) {
    case 0:
      out = errors[0];
      break;
    case EPERM:
      out = errors[1];
      break;
    case ENOENT:
      out = errors[2];
      break;
    case EIO:
      out = errors[3];
      break;
    case EINVAL:
      out = errors[4];
      break;
    case EACCES:
      out = errors[5];
      break;
    case EEXIST:
      out = errors[6];
      break;
    // Add more error codes as needed [TODO]
    default:
      out = errors[7];
      break;
  }
  return out;
}

size_t fstrlen(const char *s) {
  assert(s != NULL);
  size_t len = 0;
  const char *ps = s;
  while (*ps++ != '\0')
    len++;
  return len;
}

char *fstrpbrk(const char *s1, const char *s2) {
  assert(s1 != NULL);
  assert(s2 != NULL);
  char *out = NULL;
  const char *ps1 = s1;
  while (*ps1 != '\0') {
    if (fstrchr(s2, *(unsigned char *)ps1)) {
      out = (char *)ps1;
      break;
    }
    ps1++;
  }
  return out;
}

char *fstrrchr(const char *s, unsigned char c) {
  assert(s != NULL);
  char *out = NULL;
  const char *ps = s;
  while (*ps != '\0') {
    if (*ps == c)
      out = (char *)ps;
    ps++;
  }
  return out;
}

size_t fstrspn(const char *s1, const char *s2) {
  assert(s1 != NULL);
  assert(s2 != NULL);
  size_t out = 0;
  const char *ps1 = s1;
  while (*ps1 != '\0') {
    if (!fstrchr(s2, *(unsigned char *)ps1)) {
      break;
    }
    out++;
    ps1++;
  }
  return out;
}

char *fstrstr(const char *haystack, const char *needle) {
  assert(haystack != NULL);
  assert(needle != NULL);
  char *out = NULL;
  const char *phaystack = haystack;
  while (*phaystack != '\0') {
    const char *iterator = phaystack;
    const char *pneedle = needle;
    for (; *pneedle != '\0' && *iterator == *pneedle; iterator++, pneedle++);
    if (*pneedle == '\0') {
      out = (char *)phaystack;
      break;
    }
    phaystack++;
  }
  return out;
}

char *fstrtok(char *s, const char *delim) {
  assert(s != NULL);
  static char *nextToken = NULL;
  if (s != NULL)
    nextToken = s;
  else if (nextToken == NULL)
    return NULL;

  nextToken += fstrspn(nextToken, delim);
  if (*nextToken == '\0') {
    nextToken = NULL;
    return NULL;
  }
  char *token = nextToken;
  nextToken = fstrpbrk(token, delim);
  if (nextToken != NULL) {
    *nextToken = '\0';
      // replace the delim with null terminator
    nextToken++;
      // move to the next character after the delim
  }
  return token;
}

size_t fstrxfrm(char *dest, const char *src, size_t n) {
  // [TODO]
  assert(dest != NULL);
  assert(src != NULL);
  size_t src_len = fstrlen(src);
  if (!n)
    return src_len;
  size_t out = 0;
  char *pdest = dest;
  const char *psrc = src;
  while (*psrc != '\0' && n--) {
    *pdest++ = *psrc++,
    out++;
  }
  *pdest = '\0';
  return out;
}