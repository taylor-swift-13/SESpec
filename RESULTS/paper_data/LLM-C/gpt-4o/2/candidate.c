/*@
    requires n >= 0;
    ensures \result >= 0;
    ensures \result == 0 ==> n == 0;
    ensures \result == 1 ==> n == 1 || n == 2;
    ensures \result == fibonacci(n - 1) + fibonacci(n - 2) ==> n > 1;
    assigns \nothing;
*/
int fibonacci(int n);

int fibonacci(int n) {

        if (n < 1) {
          return 0;
        } else if (n == 1) {
          return 1;
        } else {
          return fibonacci(n - 1) + fibonacci(n - 2);
        }
}
