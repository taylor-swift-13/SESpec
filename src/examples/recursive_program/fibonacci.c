// Binary recursion. Same `decreases n` + matching `logic integer fib`
// pattern as factorial; both recursive calls reduce the measure so the
// termination obligation discharges.

/*@
  logic integer fib(integer n) =
    n <= 0 ? 0 : (n == 1 ? 1 : fib(n - 1) + fib(n - 2));
*/

/*@
  requires n >= 0;
  decreases n;
  ensures \result == fib(n);
*/
int fibonacci(int n) {
    if (n < 2) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
