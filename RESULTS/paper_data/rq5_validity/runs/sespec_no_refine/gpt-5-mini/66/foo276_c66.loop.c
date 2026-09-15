
/* No additional predicate or logic function required */

/*@
  requires \true; // Precondition described in the problem statement: (x == 4 * \at(y,Pre)) * (y == \at(y,Pre))
*/
void foo276_c66(int y) {

    int x;

    x = 4 * y;

    /*@
      loop invariant (4 * \at(y,Pre) > 0) ==> (x == 4 * y);
      loop invariant (4 * \at(y,Pre) > 0) ==> (y <= \at(y,Pre));
      loop invariant (4 * \at(y,Pre) > 0) ==> (x >= 0);
      loop invariant (!(4 * \at(y,Pre) > 0)) ==> ((x == 4 * \at(y,Pre))&&(y == \at(y,Pre)));
      loop assigns x, y;
    */
    while (x > 0) {
       x -= 4;
       y--;
    }
}
