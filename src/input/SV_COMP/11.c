int foo11_helper1(int n);
int foo11(int n);

int foo11_helper1(int n) {

        if (n == 0) {
          return 0;
        } else if (n == 1) {
          return 1;
        } else {
          return foo11(n - 1);
        }
}

int foo11(int n) {

        if (n == 0) {
          return 1;
        } else if (n == 1) {
          return 0;
        } else {
          return foo11_helper1(n - 1);
        }
}
