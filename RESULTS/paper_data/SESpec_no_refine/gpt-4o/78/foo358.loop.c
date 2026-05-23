
/*@
  logic integer initial_z(integer y) = 36 * y;
*/

/*@
  logic integer initial_c() = 0;
*/

/*@
  logic integer initial_y(integer y) = y;
*/

void foo358(int y) {
  int c = 0;
  int z = 36 * y;

  /*@
    loop invariant 0 <= c <= 36;
    loop invariant z == initial_z(y) + c;
    loop invariant y == initial_y(y);
    loop assigns z, c;
  */
  while (unknown()) {
    if (c < 36) {
      z = z + 1;
      c = c + 1;
    }
  }
}
