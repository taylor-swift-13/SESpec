int isOdd(int n);
int isEven(int n);

int isOdd(int n) {

        if (n == 0) {
          return 0;
        } else if (n == 1) {
          return 1;
        } else {
          return isEven(n - 1);
        }
}

int isEven(int n) {

        if (n == 0) {
          return 1;
        } else if (n == 1) {
          return 0;
        } else {
          return isOdd(n - 1);
        }
}
