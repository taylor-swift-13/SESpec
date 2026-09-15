
/*@
  logic integer dummy_logic = 0;
*/

int unknown();

/*@
*/
void foo357(int y) {
  int c = 0;
  int z = 36 * y;

  /*@
    loop invariant 0 <= c <= 36;
    loop invariant z + c == 36 * y;
    loop invariant y == \at(y,Pre);
    loop assigns z, c;
  */
  while (unknown()) {

    if ( c < 36 )
    {
      z  = z + 1;
      c  = c + 1;
    }
  }
}
