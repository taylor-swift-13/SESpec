// Linear recursion on a counter. The spec couples a `decreases n`
// termination measure with a `logic integer fact` definition so the
// `ensures \result == fact(n)` postcondition is checkable.

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
