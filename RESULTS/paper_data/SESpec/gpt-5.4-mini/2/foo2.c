
/*@
  requires n >= 0;
  decreases n;
  assigns \nothing;
*/
int foo2(int n);

/*@
  logic integer foo2_spec(integer n) =
    n < 1 ? 0 :
    n == 1 ? 1 :
    foo2_spec(n - 1) + foo2_spec(n - 2);
*/

/*@
  requires n >= 0;
  decreases n;
  assigns \nothing;
  ensures n < 1 ==> \result == 0;
  ensures n == 1 ==> \result == 1;
  ensures n > 1 ==> \result == foo2_spec(n);
  ensures \result == 0 || \result == 1 || \result > 1;
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
