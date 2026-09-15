
/*@
  requires n >= 0;
  assigns \nothing;
*/
int foo2(int n);

/*@ logic integer fib_rec(integer k) =
      k <= 0 ? 0 : (k == 1 ? 1 : fib_rec(k - 1) + fib_rec(k - 2)); */

/*@
  requires n >= 0;
  decreases n;
  assigns \nothing;
  ensures \result == fib_rec(n);
  ensures n == 0 ==> \result == 0;
  ensures n == 1 ==> \result == 1;
  ensures n >= 2 ==> \result == fib_rec(n - 1) + fib_rec(n - 2);
  ensures \result >= 0;
*/
int foo2(int n) {
        if (n < 1) {
          return 0;
        } else if (n == 1) {
          return 1;
        } else {
          return foo2(n - 1) + foo2(n - 2);
        }
}
