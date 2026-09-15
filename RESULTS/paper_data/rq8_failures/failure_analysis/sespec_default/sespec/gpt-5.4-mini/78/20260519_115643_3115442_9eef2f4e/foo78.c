
/*@ 
  logic integer foo78_c0(integer y0) = 0;
*/

/*@ 
  logic integer foo78_z0(integer y0) = 36 * y0;
*/

void foo78(int y) {
  int c = 0;
  int z = 36 * y;

  /*@
    loop invariant 0 <= c <= 36;
    loop invariant z == 36 * y + c;
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
