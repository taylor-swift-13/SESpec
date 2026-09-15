
/*@
  logic integer max_value(integer n, integer x, integer y) =
    \exists integer i; 1 <= i <= n && (i % x == y) && (\forall integer j; 1 <= j <= n && j != i ==> (j % x != y));
*/

/*@
  logic integer max_up_to(integer i, integer x, integer y) =
    \exists integer m; m == 0 || (1 <= m <= i && (m % x == y) && (\forall integer j; 1 <= j <= i && j != m ==> (j % x != y)));
*/

/*@
  requires n >= 0;
  requires x > 0;
  requires y >= 0 && y < x;
  assigns \result;
  ensures valid_max(\result, n, x, y);
*/
int foo292(int n, int x, int y) {

    int max = 0;

    /*@
      loop invariant 1 <= i <= n + 1;
      loop invariant valid_max(max, i - 1, x, y);
      loop invariant y == \at(y,Pre);
      loop invariant x == \at(x,Pre);
      loop invariant n == \at(n,Pre);
      loop assigns i, max;
    */
    for (int i = 1; i <= n; i++) {
        if ((i % x) == y) {
            max = i;
        }
    }

    /*@
      ensures valid_max(max, n, x, y);
    */
    return max;
}
