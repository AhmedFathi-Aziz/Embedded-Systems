#include <stdio.h>
#include <stdint.h>

int main() {
   char *a[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
   int n;
   scanf("%d", &n);
   if (n > 9)
      printf("Greater than 9");
   else
      printf("%s", a[--n]);
  return 0;
}
