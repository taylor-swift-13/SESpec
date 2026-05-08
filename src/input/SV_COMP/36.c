int foo36_helper1(int m, int n, int c);
int foo36(int m, int n);

int foo36_helper1(int m, int n, int c) {

    if (n == 0) {
      return m;
    }

    if (c >= 150) {
      ;
    }

    if (n > 0) {
      return foo36_helper1(m + 1, n - 1, ++c);
    } else {
      return foo36_helper1(m - 1, n + 1, ++c);
    }
}

int foo36(int m, int n) {

    if (m < 0 || m >= 10000) {
      return -1;
    }
    if (n < 0 || n >= 10000) {
      return -1;
    }
    int c = 0;
    int result = foo36_helper1(m, n, c);
    return (result == m + n) ? 1 : 0;
}
