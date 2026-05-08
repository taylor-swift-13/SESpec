int foo32_helper1(int n, int m);
int foo32_helper2(int n, int m);
int foo32_helper3(int n);
int foo32(int n, int m);

int foo32_helper1(int n, int m) {

    if (m < 0) {
      return foo32_helper1(n, -m);
    }
    if (m == 0) {
      return 0;
    }
    if (m == 1) {
      return 1;
    }
    return n + foo32_helper1(n, m - 1);
}

int foo32_helper2(int n, int m) {

    if (m < 0) {
      return foo32_helper2(n, -m);
    }
    if (n < 0) {
      return foo32_helper2(-n, m);
    }
    if (m == 0) {
      return 0;
    }
    if (n == 0) {
      return 1;
    }
    return foo32_helper2(n - m, m);
}

int foo32_helper3(int n) {

    return foo32(n, n - 1);
}

int foo32(int n, int m) {

    if (n <= 1) {
      return 0;
    } else if (n == 2) {
      return 1;
    } else {
      if (m <= 1) {
        return 1;
      } else {
        if (foo32_helper2(n, m) == 0) {
          return 0;
        }
        return foo32(n, m - 1);
      }
    }
}
