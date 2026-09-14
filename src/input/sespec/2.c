int foo2(int n);

int foo2(int n) {

        if (n < 1) {
          return 0;
        } else if (n == 1) {
          return 1;
        } else {
          return foo2(n - 1) + foo2(n - 2);
        }
}
