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

inline int run()
{
  int i = atoi("10");
  return 0;
}

void entry()
{
  run();
}