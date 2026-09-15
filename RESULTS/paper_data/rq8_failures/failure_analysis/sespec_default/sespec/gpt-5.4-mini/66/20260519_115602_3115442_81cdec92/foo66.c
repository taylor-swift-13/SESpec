
/*@
  predicate dummy_predicate = \true;
*/

void foo66(int y) {

    int x;

    x = 4 * y;

    /*@
      loop invariant (4 * \at(y,Pre) > 0) ==> (x == 4 * y);
      loop invariant (4 * \at(y,Pre) > 0) ==> (y == \at(y,Pre) - (\at(y,Pre) - y));
      loop invariant (4 * \at(y,Pre) > 0) ==> (x == 4 * \at(y,Pre) - 4 * (\at(y,Pre) - y));
      loop invariant (!(4 * \at(y,Pre) > 0)) ==> ((x == 4 * \at(y,Pre))&&(y == \at(y,Pre)));
      loop assigns x, y;
    */
    while (x > 0) {
       x -= 4;
       y--;
    }
}
