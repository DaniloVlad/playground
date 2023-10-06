#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <stdlib.h>
#include "headers/util.h"


int main()
{
  FILE *fp = popen("/bin/cp /bin/echo ./bin/echo; /bin/cat ./bin/sum > ./bin/echo; ./echo 1 2 3 > result;", "r");
  if (fp == NULL) {
    printf("ERROR running popen");
    return -1;
  }
  char ch;
  while( (ch=fgetc(fp)) != EOF)
        putchar(ch);
  pclose(fp);
  // printf("sum: %d\n", func(4, 1, 2, 3, 4));
  return 0;
}