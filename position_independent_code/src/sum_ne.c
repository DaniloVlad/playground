int sum(int num_args, int *nums) {
  int val = 0;
  // va_list ap;
  int i;
  
  // va_start(ap, num_args);
  for (i = 0; i < num_args; i++) {
    val += nums[i];
  }
  // va_end(ap);

  return val;
}