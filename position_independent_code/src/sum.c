#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int sum(int num_args, int *nums) {
  int val = 0;
  // va_list ap;
  int i;
  
  // va_start(ap, num_args);
  for (i = 0; i < num_args; i++) {
    printf("adding arg: %d\n", nums[i]);

    val += nums[i];
  }
  // va_end(ap);

  return val;

}

int main(int argc, char **argv) {
  int nums[argc - 1];
  for (int i = 1; i < argc; i++) {
    nums[i - 1] = atoi(argv[i]);
    printf("found arg: %d\n", nums[i]);
  }
  int i = sum(argc - 1, nums);
  printf("sum = %d\n", i);
  return i;
}