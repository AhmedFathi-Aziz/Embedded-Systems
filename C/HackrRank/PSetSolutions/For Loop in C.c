#include <stdio.h>
#include <stdint.h>

int main() {
  char *number[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
  int a, b;
  scanf("%d %d", &a, &b);
  for ( ; a <= b; a++) {
     if (a > 9) {
        if (a % 2)
           printf("odd\n");
        else
           printf("even\n");
     }
     else
        printf("%s\n", number[a - 1]);
  }
  return 0;
}
