#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main() {
   int n, *a, i;
   scanf("%d", &n);
   a = malloc(n * sizeof(int));
   for (i = 0; i < n; i++)
      scanf("%d", &a[i]);

   int num = 0;
   for (i = 0; i < n / 2; i++) {
      num = a[i];
      a[i] = a[n - i - 1];
      a[n - i - 1] = num;
   }
   for (i = 0; i < n; i++)
      printf("%d ", a[i]);
   return 0;
}
