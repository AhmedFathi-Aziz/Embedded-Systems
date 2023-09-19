#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void update(int *, int *);

int main() {
   int a, b;
   int *pa = &a,
       *pb = &b;
   scanf("%d %d", &a, &b);
   update(pa, pb);
   printf("%d\n%d", a, b);
  
  return 0;
}

void update(int *a, int *b) {
   int n = *a;
   *a += *b;
   *b = abs(n - *b);
}
