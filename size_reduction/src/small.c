#include <sys/syscall.h>

int atoi(char *str)
{
  int k = 0;
  while (*str != '\0')
  {
    k = (k << 3) + (k << 1) + (*str) - '0';
    str++;
  }
  return k;
}

int run(void)
{
  int i = atoi("10");
  return 0;
}

void exit(int code) {
  syscall(SYS_exit, code);
}
void entry()
{
  run();
  exit(0);
}