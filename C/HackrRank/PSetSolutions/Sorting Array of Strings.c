#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
  return strcmp(a, b) > 0;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
  return strcmp(a, b) < 0;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
  char afreq[250] = {0};
  char bfreq[250] = {0};
  int n = 0, m = 0;
  const char *i = a;
  while (*i) {
    if (!afreq[*i]) {
      afreq[*i]++;
      n++;
    }
    i++;
  }
  const char *j = b;
  while (*j) {
    if (!bfreq[*j]) {
      bfreq[*j]++;
      m++;
    }
    j++;
  }
  if (n != m) {
    return n > m;
  }
  return strcmp(a, b) > 0;
}

int sort_by_length(const char* a, const char* b) {
  int n = strlen(a);
  int m = strlen(b);
  if (n != m) {
    return n > m;
  }
  return strcmp(a, b) > 0;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < len - i - 1; j++) {
      if (cmp_func(arr[j], arr[j + 1])) {
        char *temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}