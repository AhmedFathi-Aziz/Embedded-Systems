#include <stdio.h>
#include <string.h>

char message[101] = "zzzzzzzzzz";
const char source[101] = "abcdfathi";

int main() {
  size_t p= strxfrm(message, source,1111);
  printf("%li \n", p);
  // printf("%c \n", *p);
  return 0;
}