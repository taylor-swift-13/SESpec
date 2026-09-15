
/*@
  logic integer initial_z(integer y) = 36 * y;
*/

/*@
  logic integer initial_c() = 0;
*/

void foo357(int y) {
  int c = 0;
  int z = 36 * y;

  /*@
    loop invariant c >= 0;
    loop invariant c <= 36;
    loop invariant z == initial_z(y) + c;
    loop invariant y == \at(y,Pre);
    loop assigns z, c;
  */
  while (unknown()) {
    if (c < 36) {
      z = z + 1;
      c = c + 1;
    }
  }
}
