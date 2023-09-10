#ifndef _STRING_H_
#define _STRING_H_

#define	__need_size_t
#define	__need_NULL
#include <stddef.h>

#include <errno.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void *fmemchr(const void *s, unsigned char c, size_t n);

void *fmemcpy(void *dest, const void *src, size_t n);

void *fmemmove(void *dest, const void *src, size_t n);

int fmemcmp(const void *s1, const void *s2, size_t n);

void *fmemset(void *s, unsigned char c, size_t n);

char *fstrcat(char *dest, const char *src);

char *fstrncat(char *dest, const char *src, size_t n);

char *fstrchr(const char *s, unsigned char c);

int fstrcmp(const char *s1, const char *s2);

int fstrncmp(const char *s1, const char *s2, size_t n);

int fstrcoll(const char *s1, const char *s2);

char *fstrcpy(char *dest, const char *src);

char *fstrncpy(char *dest, const char *src, size_t n);

size_t fstrcspn(const char *s1, const char *s2);

char *fstrerror(int errnum);

size_t fstrlen(const char *s);

char *fstrpbrk(const char *s1, const char *s2);

char *fstrrchr(const char *s, unsigned char c);

size_t fstrspn(const char *s1, const char *s2);

char *fstrstr(const char *haystack, const char *needle);

char *fstrtok(char *s, const char *delim);

size_t fstrxfrm(char *dest, const char *src, size_t n);

#endif