/*@
    requires n >= 0;
    ensures \result >= 0;
*/
int fibonacci(int n);

 /*@
    requires n >= 0;
    ensures n == 0 ==> \result == 0;
    ensures n == 1 ==> \result == 1;
    ensures n >= 2 ==> \result == fibonacci(n - 1) + fibonacci(n - 2);
*/
int fibonacci(int n) {

        if (n < 1) {
          return 0;
        } else if (n == 1) {
          return 1;
        } else {
          return fibonacci(n - 1) + fibonacci(n - 2);
        }
}
