int foo22_c2(int n);


int foo22_c2(int n) {

        if (n < 1) {
          return 0;
        } else if (n == 1) {
          return 1;
        } else {
          return foo22_c2(n - 1) + foo22_c2(n - 2);
        }
}