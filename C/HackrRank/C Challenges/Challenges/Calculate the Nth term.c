#include <stdio.h>
#include <stdint.h>

int find_nth_term(int, int, int, int);
int memo[101];

int main() {
   int n;
   int a, b, c;
   scanf("%d %d %d %d", &n, &a, &b, &c);
   memo[1] = a;
   memo[2] = b;
   memo[3] = c;
   printf("%d\n", find_nth_term(n, a, b, c));
  
  return 0;
}

int find_nth_term(int n, int a, int b, int c) {
   if (memo[n])
     return memo[n]; 
   int answer = find_nth_term(n - 3, a, b, c) +
          find_nth_term(n - 2, a, b, c) +
          find_nth_term(n - 1, a, b, c);
   memo[n] = answer;
   return answer;
}
