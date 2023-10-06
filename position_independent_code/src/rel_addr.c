int add(int a) {
  return 1 + a;
}

int add_2(int a) {
  int b = add(a);
  return add(b);
}

int main() {
  add_2(3);
  return 0;
}