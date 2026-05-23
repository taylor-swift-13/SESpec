
/*@
  logic integer sum_of_squares(integer n) =
    n <= 0 ? 0 : n * n + sum_of_squares(n - 1);
*/

/*@
  requires k == \at(k, Pre);
  assigns c, y, x;
  ensures (k > 0) ==> (c == k && y == k && x == sum_of_squares(k));
  ensures (k <= 0) ==> (c == 0 && y == 0 && x == 0);
*/
int foo394(int k) {
    int y = 0;
    int x = 0;
    int c = 0;

    /*@
      loop invariant (0 < \at(k,Pre)) ==> (y == c);
      loop invariant (!(0 < \at(k,Pre))) ==> ((c == 0) && (x == 0) && (y == 0) && (k == \at(k,Pre)));
      loop invariant k == \at(k,Pre);
      loop assigns c, y, x;
      loop variant k - c;
    */
    while (c < k) {
        c = c + 1;
        y = y + 1;
        x = y * y + x;
    }
}
