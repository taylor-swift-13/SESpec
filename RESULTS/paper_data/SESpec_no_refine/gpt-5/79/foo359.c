
int unknown();

void foo359(int y,int x1,int x2,int x3) {
  int c = 0;
  int z = 36 * y;

  /*@
    loop invariant z - c == 36 * y;
    loop invariant 0 <= c <= 36;
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
