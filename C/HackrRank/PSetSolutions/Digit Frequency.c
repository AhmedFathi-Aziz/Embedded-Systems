#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int main() { 
   char s[1001];
   scanf("%s", s);
   
   char freq[] = { [UCHAR_MAX] = 0 };
   char *ps = s;
   while (*ps) {
      freq[*ps++ - 48]++;
   }
   uint8_t i = 0;
   for (; i < 10; i++)
      printf("%d ", freq[i]);
   return 0;
}
