
/*@
  logic integer cube(integer n) = n * n * n;
*/

/*@
  requires k >= 0;
  assigns \nothing;
  ensures \result == 0;
*/
int foo395(int k) {
    int y = 0;
    int x = 0;
    int c = 0;

    /*@
      loop invariant (0 < \at(k,Pre)) ==> (y == c);
      loop invariant (0 < \at(k,Pre)) ==> (c >= 0 && c <= k);
      loop invariant (!(0 < \at(k,Pre))) ==> ((c == 0) && (x == 0) && (y == 0) && (k == \at(k,Pre)));
      loop invariant k == \at(k,Pre);
      loop assigns c, y, x;
      loop variant k - c;
    */
    while (c < k) {
        c = c + 1;
        y = y + 1;
        x = y * y * y + x;
    }

    /*@
      ensures (0 < \at(k,Pre)) ==> (y == k);
      ensures (0 < \at(k,Pre)) ==> (x == \sum(1, k, cube));
      ensures (!(0 < \at(k,Pre))) ==> (x == 0 && y == 0 && c == 0);
      ensures k == \at(k,Pre);
    */
    return 0;
}
