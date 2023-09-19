#include <stdio.h>
#include <stdint.h>

char *tokens(char *s, char c);

int main() {
  char *sen = malloc(1001 * sizeof(char));
  scanf("%[^\n]s", sen);
  char *token = tokens(sen, ' ');
  while (token != NULL) {
    printf("%s\n", token);
    token = tokens(NULL, ' ');
  }
  return 0;
}

char *tokens(char *s, char c) {
  static char *nextToken = NULL;
  if (s != NULL)  
    nextToken = s;
  else if (nextToken == NULL)
    return nextToken;

  char *token = nextToken;

  char *ptoken = token;
  int found = 0;
  while (*ptoken != '\0') {
    if (*ptoken == c) {
      nextToken = ptoken;
      found = 1;
      break;
    }
    ptoken++;
  }
  if (!found)
    nextToken = NULL;

  if (nextToken != NULL) {
    *nextToken = '\0';
    ++nextToken;
  }
  return token;
}
