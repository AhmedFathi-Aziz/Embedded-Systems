#include <stdio.h>
#include <stdint.h>

int max_of_four(int, int, int, int);

int main() {
   int a,
       b,
       c,
       d;
   scanf("%d %d %d %d", &a, &b, &c, &d);
   printf("%d \n", max_of_four(a, b, c, d)); 
  return 0;
}

int max_of_four(int a, int b, int c, int d) {
   int answer = a;
   if (answer < b)
      answer = b;
   if (answer < c)
      answer = c;
   if (answer < d)
      answer = d;
   return answer;
}
