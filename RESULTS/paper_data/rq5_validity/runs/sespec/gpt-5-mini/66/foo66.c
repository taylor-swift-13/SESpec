
/*@ 
  requires y >= 0;
*/
void foo66(int y) {

    int x;

    x = 4 * y;

    /*@
      loop invariant 0 <= y;
      loop invariant y <= \at(y,Pre);
      loop invariant 0 <= x <= 4 * \at(y,Pre);
      loop invariant x == 4 * y;
      loop invariant \forall integer k; 0 <= k <= \at(y,Pre) ==> y <= \at(y,Pre);
      loop invariant (4 * \at(y,Pre) > 0) ==> (x >= 0);
      loop invariant (4 * \at(y,Pre) > 0) ==> (y >= 0);
      loop invariant (!(4 * \at(y,Pre) > 0)) ==> ((x == 4 * \at(y,Pre)) && (y == \at(y,Pre)));
      loop assigns x, y;
    */
    while (x > 0) {
       x -= 4;
       y--;
    }

}
