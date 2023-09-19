#include <stdio.h>
#include <stdint.h>

int grid[2000][2000];

int main() {
   int n;
   scanf("%d", &n);
   int m = 2 * n - 1;
   
   int rb = 0, cb = 0,
       rt = 0, ct = 0;
   for (int i = 0; i < m; i++) {
      rb = m - (i + 1);
      cb = i;
      rt = (i - 1) + 1;
      ct = i;
      while (ct < m - i)
          grid[rt][ct++] = n,
          grid[rb][cb++] = n;

      rt = i;
      ct = m - (i + 1);
      rb = i;
      cb = i;
      while (rt < m - i)
         grid[rt++][ct] = n,
         grid[rb++][cb] = n;

      n--;
   }

   for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++)
         printf("%d ", grid[i][j]);
      printf("\n");
   }
   
  
  return 0;
}
