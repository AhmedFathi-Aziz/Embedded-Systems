#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main() {  
   int n;
   scanf("%i", &n);
   int *a = malloc(n * sizeof(int));
   uint16_t i = 0;
   for (; i < n; i++)
      scanf("%i", &a[i]);
   int sum = 0;
   for (i = 0; i < n; i++)
      sum += a[i];
   printf("%i\n", sum);
   free(a);
   a = NULL;
   return 0;
}
