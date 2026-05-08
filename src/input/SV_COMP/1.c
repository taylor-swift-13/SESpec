int foo1(int m, int n);

int foo1(int m, int n) {

    if (m == 0) {
      return n + 1;
    }
    if (n == 0) {
      return foo1(m - 1, 1);
    }
    return foo1(m - 1, foo1(m, n - 1));
}
