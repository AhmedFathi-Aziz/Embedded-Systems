#include <stdio.h>
#include <stdint.h>

int main() {
   char a[101];
   scanf("%[^\n]s", a);
   printf("Hello, World! \n");
   printf("%s", a);
  
  return 0;
}
