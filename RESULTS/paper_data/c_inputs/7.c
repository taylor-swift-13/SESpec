int foo7(int n, int m);

int foo7(int n, int m) {

    if (m < 0) {
      return foo7(n, -m);
    }
    if (m == 0) {
      return 0;
    }
    return n + foo7(n, m - 1);
}
