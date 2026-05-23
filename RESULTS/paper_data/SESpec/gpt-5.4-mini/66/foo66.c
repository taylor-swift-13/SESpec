
void foo66(int y) {

    int x;

    x = 4 * y;

    /*@
      loop invariant x == 4 * y;
      loop invariant y <= \at(y, Pre);
      loop invariant x % 4 == 0;
      loop invariant (4 * \at(y, Pre) > 0) ==> (x == 4 * y);
      loop invariant (4 * \at(y, Pre) > 0) ==> (0 <= y);
      loop invariant (4 * \at(y, Pre) > 0) ==> (0 <= x);
      loop invariant (!(4 * \at(y, Pre) > 0)) ==> ((x == 4 * \at(y, Pre)) && (y == \at(y, Pre)));
      loop assigns x, y;
    */
    while (x > 0) {
       x -= 4;
       y--;
    }
}
