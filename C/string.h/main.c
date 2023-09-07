#include <stdio.h>
#include "string.h"
#include <string.h>
#include <errno.h>

char s1[101] = "--Hello - World! - World!";
char s2[101] = "";

int main() {
  unsigned int n = fstrxfrm(s2, s1, 100);
  printf("n = %i \n", n);
  printf("%s \n", s2);
  return 0;
}