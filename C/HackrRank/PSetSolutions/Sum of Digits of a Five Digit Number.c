#include <stdio.h>
#include <stdint.h>

int main() {
   int n;
   scanf("%d", &n);
   int answer = 0;
   while (n) {
      answer += n % 10;
      n /= 10;
   }
   printf("%d\n", answer);
  
  return 0;
}
