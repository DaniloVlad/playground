int atoi(char *str)
{
  int k = 0;
  while (*str)
  {
    k = (k << 3) + (k << 1) + (*str) - '0';
    str++;
  }
  return k;
}

int run()
{
  int i = atoi("10");
  return 0;
}

void entry()
{
  run();
  exit(10);
}