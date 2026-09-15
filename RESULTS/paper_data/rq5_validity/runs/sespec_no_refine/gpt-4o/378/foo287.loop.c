
/*@
  logic integer sum_of_odds(integer l, integer r) =
    (l > r) ? 0 : (l % 2 != 0 ? l : 0) + sum_of_odds(l + 1, r);
*/

/*@
  requires l <= r;
  ensures \result == sum_of_odds(l, r);
*/
int foo287(int l, int r) {

    int sum = 0;

    /*@
      loop invariant l <= i <= r + 1;
      loop invariant r == \at(r,Pre);
      loop invariant l == \at(l,Pre);
      loop assigns i, sum;
    */
    for (int i = l; i <= r; i++) {
        if (i % 2 != 0) {
            sum += i;
        }
    }

    return sum;
}
