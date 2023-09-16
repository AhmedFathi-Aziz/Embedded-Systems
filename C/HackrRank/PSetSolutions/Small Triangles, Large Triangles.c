#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};
typedef struct triangle triangle;
double area(triangle *object) {
  double p = (object->a + object->b + object->c) / 2.0;
  double out = sqrt(p * (p - object->a) * (p - object->b) * (p - object->c));
  return out;
}
void sort_by_area(triangle* tr, int n) {
  char flag;
  for (int i = 0; i < n - 1; i++) {
    flag = 0;
    for (int j = 0; j < n - i - 1; j++) {
      if (area(&tr[j]) > area(&tr[j + 1])) {
        triangle temp = tr[j];
        tr[j] = tr[j + 1];
        tr[j + 1] = temp;
        flag = 1;
      }
    }
    if (!flag)
      return;
  }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);

	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}