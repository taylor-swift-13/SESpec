int foo22(int n);

int foo22(int n) {

        if (n < 1) {
          return 0;
        } else if (n == 1) {
          return 1;
        } else {
          return foo22(n - 1) + foo22(n - 2);
        }
}
