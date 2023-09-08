#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "string.h"

void *fmemchr(const void *s, unsigned char c, unsigned int n) {
  void *out = NULL;
  if (s) {
    const unsigned char *ps = (const unsigned char *)s;
    while (n--) {
      if (*ps == c) {
        out = (void *)ps;
        break;
      }
      ps++;
    }
  }
  return out;
}

int fmemcmp(const void *s1, const void *s2, unsigned int n) {
  int state = 0;
  if (s1 && s2) {
    if (s1 != s2) {
      const unsigned char *ps1 = (const unsigned char *)s1;
      const unsigned char *ps2 = (const unsigned char *)s2;
      while (n--) {
        if (*ps1 != *ps2) {
          if (*ps1 > *ps2)
            state = 1;
          else
            state = -1;
          break;
        }
        ps1++;
        ps2++;
      }
    }
  } else {
    if (s1)
      state = 1;
    else if (s2)
      state = -1;
  }
  return state;
}

void *fmemcpy(void *dest, const void *src, int n) {
  if (dest && src) {
    unsigned char *pdest = (unsigned char *)dest;
    const unsigned char *psrc = (const unsigned char *)src;
    while (n--) {
      *pdest++ = *psrc++;
    }
  }
  return dest;
}

void *fmemmove(void *dest, const void *src, int n) {
  if (dest && src) {
    unsigned char *buffer = malloc(sizeof(char) * n);
    for (int i = 0; i < n; i++)
      *(buffer + i) = *((const unsigned char *)src + i);
    
    for (int i = 0; i < n; i++)
      *((unsigned char *)dest + i) = *(buffer + i);

    free(buffer);
  }
  return dest;
}

void *fmemset(void *s, unsigned char c, int n) {
  if (s) {
    unsigned char *pdest = (unsigned char *)s;
    while (n--) {
      *pdest++ = c;
    }
  }
  return s;
}

char *fstrcat(char *dest, const char *src) {
  if (dest && src) {
    char *pdest = dest;
    while (*pdest)
      pdest++;
    while (*src)
      *pdest++ = *src++;
    *pdest = '\0';
  }
  return dest;
}

char *fstrncat(char *dest, const char *src, unsigned int n) {
  if (dest && src) {
    char *pdest = dest;
    while (*pdest)
      pdest++;
    while (*src && n--) {
      *pdest++ = *src++;
    }
    *pdest = '\0';
  }
  return dest;
}

char *fstrchr(const char *s, unsigned char c) {
  char *out = NULL;
  if (s) {
    while (*s) {
      if (*s == c) {
        out = (char *)s;
        break;
      }
      s++;
    }
  }
  return out;
}

int fstrcmp(const char *s1, const char *s2) {
  int state = 0;
  if (s1 && s2) {
    if (s1 != s2) {
      const char *ps1 = s1;
      const char *ps2 = s2;

      while (*ps1 != '\0' && *ps2 != '\0') {
        if (*ps1 != *ps2) {
          if (*ps1 > *ps2)
            state = 1;
          else
            state = -1;
          break;
        }
        ps1++;
        ps2++;
      }
      if (!state) {
        if (*ps1 != '\0')
          state = 1;
        else if (*ps2 != '\0')
          state = -1;
      }
    }
  } else {
    if (s1)
      state = 1;
    else if (s2)
      state = -1;
  }
  return state;
}

int fstrncmp(const char *s1, const char *s2, unsigned int n) {
  int state = 0;
  if (s1 && s2) {
    const char *ps1 = s1;
    const char *ps2 = s2;
    while (n--) {
      if (*ps1 != *ps2) {
        if (*ps1 > *ps2)
          state = 1;
        else
          state = -1;
        break;
      }
      ps1++;
      ps2++;
    }
  } else {
    if (s1)
      state = 1;
    else if (s2)
      state = -1;
  }
  return state;
}

int fstrcoll(const char *s1, const char *s2) {
  int state = 0;
  if (s1 && s2) {
    if (s1 != s2) {
      const char *ps1 = s1;
      const char *ps2 = s2;

      while (*ps1 != '\0' && *ps2 != '\0') {
        if (*ps1 != *ps2) {
          if (*ps1 > *ps2)
            state = 1;
          else
            state = -1;
          break;
        }
        ps1++;
        ps2++;
      }
      if (!state) {
        if (*ps1 != '\0')
          state = 1;
        else if (*ps2 != '\0')
          state = -1;
      }
    }
  } else {
    if (s1)
      state = 1;
    else if (s2)
      state = -1;
  }
  return state;
}

char *fstrcpy(char *dest, const char *src) {
  if (dest && src) {
    char *pdest = dest;
    while (*src != '\0') {
      *pdest++ = *src++;
    }
    *pdest = '\0';
  }
  return dest;
}

char *fstrncpy(char *dest, const char *src, unsigned int n) {
  if (dest && src) {
    char *pdest = dest;
    while (*src != '\0' && n--) {
      *pdest++ = *src++;
    }
    while (n--) {
      *pdest = '\0';
    }
  }
  return dest;
}

unsigned int fstrcspn(const char *s1, const char *s2) {
  unsigned int len = 0;
  if (s1 && s2) {
    const char *ps1 = s1;
    while (*ps1 != '\0') {
      char found = 0;
      const char *ps2 = s2;
      while (*ps2 != '\0') {
        if (*ps1 == *ps2) {
          found = 1;
          break;
        }
        ps2++;
      }
      if (found)
        break;
      len++;
      ps1++;
    }
  }
  return len;
}

char *fstrerror(int errnum) {
  switch (errnum) {
    case 0:
      return "No error";
    case EPERM:
      return "Operation not permitted";
    case ENOENT:
      return "No such file or directory";
    case EIO:
      return "Input/output error";
    case EINVAL:
      return "Invalid argument";
    case EACCES:
      return "Permission denied";
    case EEXIST:
      return "File exists";
    // Add more error codes as needed
    default:
      return "Unknown error";
  }
}

unsigned int fstrlen(const char *s) {
  unsigned int len = 0;
  if (s) {
    const char *ps = s;
    while (*ps++ != '\0')
      len++;
  }
  return len;
}

char *fstrpbrk(const char *s1, const char *s2) {
  char *pointer = NULL;
  if (s1 && s2) {
    const char *ps1 = s1;
    char found = 0;
    while (*ps1 != '\0') {
      const char *ps2 = s2;
      while (*ps2 != '\0') {
        if (*ps1 == *ps2) {
          found = 1;
          break;
        }
        ps2++;
      }
      if (found) {
        pointer = (char *)ps1;
        break;
      }
      ps1++;
    }
  }
  return pointer;
}

char *fstrrchr(const char *s, unsigned char c) {
  char *pointer = NULL;
  if (s) {
    const char *ps = s;
    while (*ps != '\0') {
      if (*ps == c)
        pointer = (char *)ps;
      ps++;
    }
  }
  return pointer;
}

unsigned int fstrspn(const char *s1, const char *s2) {
  unsigned int len = 0;
  if (s1 && s2) {
    const char *ps1 = s1;
    while (*ps1 != '\0') {
      const char *ps2 = s2;
      char found = 0;
      while (*ps2 != '\0') {
        if (*ps1 == *ps2) {
          found = 1;
          break;
        }
        ps2++;
      }
      if (!found) {
        break;
      }
      len++;
      ps1++;
    }
  }
  return len;
}

char *fstrstr(const char *haystack, const char *needle) {
  char *pointer = NULL;
  if (haystack && needle) {
    const char *phaystack = haystack;
    while (*phaystack != '\0') {
      const char *iterator = phaystack;
      const char *pneedle = needle;
      while (*pneedle != '\0' && *iterator == *pneedle) {
        iterator++;
        pneedle++;
      }
      if (*pneedle == '\0') {
        pointer = (char *)phaystack;
        break;
      }
      phaystack++;
    }
  }
  return pointer;
}

char *fstrtok(char *s, const char *delim) {
  static char *nextToken = NULL;
  if (s != NULL)
    nextToken = s;
  else if (nextToken == NULL)
    return NULL;

  nextToken += fstrspn(nextToken, delim);
    // skip leading delimiters
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

unsigned int fstrxfrm(char *dest, const char *src, unsigned int n) {
  unsigned int len = 0;
  if (dest && src) {
    char *pdest = dest;
    const char *psrc = src;
    
    while (*psrc != '\0' && n--)
      *pdest++ = *psrc++,
      len++;
    *pdest = '\0';
  }
  return len;
}