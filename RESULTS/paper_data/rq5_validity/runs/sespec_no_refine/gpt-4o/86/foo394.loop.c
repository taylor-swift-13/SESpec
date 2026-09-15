
/*@
  logic integer sum_of_squares(integer n) =
    n <= 0 ? 0 : n * n + sum_of_squares(n - 1);
*/

/*@
  logic integer sum_upto(integer n) =
    n <= 0 ? 0 : n + sum_upto(n - 1);
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
    */
    while (c < k) {
        c = c + 1;
        y = y + 1;
        x = y * y + x;
    }
}
