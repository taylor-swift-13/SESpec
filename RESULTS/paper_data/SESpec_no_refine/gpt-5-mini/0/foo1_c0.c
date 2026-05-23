int foo1_c0(int m, int n);


int foo1_c0(int m, int n) {

    if (m == 0) {
      return n + 1;
    }
    if (n == 0) {
      return foo1_c0(m - 1, 1);
    }
    return foo1_c0(m - 1, foo1_c0(m, n - 1));
}