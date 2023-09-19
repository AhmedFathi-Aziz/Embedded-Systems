#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main() {
   int a, b;
   float n, m;
   scanf("%d %d", &a, &b);
   scanf("%f %f", &n, &m);

   printf("%d %d \n", a + b, a - b);
   printf("%.1f %.1f \n", n + m, n - m);
  
  return 0;
}
