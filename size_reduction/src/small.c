#include "headers/small.h"

int atoi(char *str)
{
  int res = 0;

  for (int i = 0; str[i] != '\0'; ++i)
    res = res * 10 + str[i] - '0';

  return res;
}

int run()
{
  char *str = "10\0";
  int i = atoi(str);
  return 0;
}

void entry() {
  run();
}