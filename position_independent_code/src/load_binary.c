#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <stdlib.h>

int hex_dump(char *description, void *ptr, int len)
{
  if (len <= 0)
  {
    return -1;
  }

  if (description != NULL && strlen(description) > 0)
  {
    printf("%s\n", description);
  }

  unsigned char buff[17];
  unsigned char *str = ptr;
  int i = 0;
  for (i = 0; i < len; i++) {
    if (i % 16 == 0) {
      if (i != 0) {
        printf("  %s\n", buff);
      }
      printf("  %04x", i);
    }

    char val;
    if (str[i] > 32 && str[i] < 127) {
       val = str[i];
    }
    else {
      val = '.';
    }
    printf(" %02x", str[i]);
    buff[i % 16] = val;
    buff[i + 1] = '\0';
  }

  printf(" |");
  printf("  %s\n", buff);
  printf("dumped %d bytes\n", i);
  return 0;
}


int main()
{
  FILE *fp = popen("/bin/cp /bin/echo ./echo; /bin/cat ./bin/sum > ./echo; ./echo 1 2 3      > result;", "r");
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