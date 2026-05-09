/*@
  logic integer fact(integer n) =
    n <= 0 ? 1 : n * fact(n - 1);
*/

/*@
  requires n >= 0;
  decreases n;
  ensures \result == fact(n);
*/
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}
