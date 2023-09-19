#include <stdio.h>
#include <stdint.h>

int main() {
   char c;
   char s[101];
   char sentence[101];
   scanf("%c", &c);
   scanf("%s", s);
   scanf("\n");
   scanf("%[^\n]s", sentence);

   printf("%c \n", c);
   printf("%s \n", s);
   printf("%s \n", sentence);
  
  return 0;
}
