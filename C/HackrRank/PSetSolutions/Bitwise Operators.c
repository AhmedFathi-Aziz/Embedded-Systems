#include <stdio.h>
#include <stdint.h>

void calculate_the_maximum(int , int);
void update(int, int, int *);

int main() {
   int n, k;
   scanf("%d %d", &n, &k);
   calculate_the_maximum(n, k);
  
  return 0;
}

void calculate_the_maximum(int n, int k) {
   int and = 0,
       or = 0,
       xor = 0,
       val = 0;
   for (int i = 1; i < n; i++) {
      for (int j = i + 1; j <= n; j++) {
         val = (i & j);
         update(val, k, &and); 
         val = (i | j);
         update(val, k, &or);
         val = (i ^ j);
         update(val, k, &xor);
      }
   }
   printf("%d\n%d\n%d\n", and, or, xor);
}

void update(int val, int k, int *ans) {
   if (val < k)
      if (*ans < val)
         *ans = val; 
}
