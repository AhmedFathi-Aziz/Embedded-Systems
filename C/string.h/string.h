#ifndef _STRING_H_
#define _STRING_H_

void *fmemchr(const void *s, unsigned char c, unsigned int n);

void *fmemcpy(void *dest, const void *src, int n);

void *fmemmove(void *dest, const void *src, int n);

void *fmemset(void *s, unsigned char c, int n);

char *fstrcat(char *dest, const char *src);

char *fstrncat(char *dest, const char *src, unsigned int n);

char *fstrchr(const char *s, unsigned char c);

int fmemcmp(const void *s1, const void *s2, unsigned int n);

int fstrcmp(const char *s1, const char *s2);

int fstrncmp(const char *s1, const char *s2, unsigned int n);

int fstrcoll(const char *s1, const char *s2);

char *fstrcpy(char *dest, const char *src);

char *fstrncpy(char *dest, const char *src, unsigned int n);

unsigned int fstrcspn(const char *s1, const char *s2);

char *fstrerror(int errnum);

unsigned int fstrlen(const char *s);

char *fstrpbrk(const char *s1, const char *s2);

char *fstrrchr(const char *s, unsigned char c);

unsigned int fstrspn(const char *s1, const char *s2);

char *fstrstr(const char *haystack, const char *needle);

char *fstrtok(char *s, const char *delim);

unsigned int fstrxfrm(char *dest, const char *src, unsigned int n);

#endif