
int unknown(void);

void foo81(int y,int x1,int x2,int x3) {
  int c = 0;
  int z = 36 * y;

  /*@ 
    loop assigns c, z;
    loop invariant 0 <= c;
    loop invariant c <= 36;
    loop invariant z == 36 * y + c;
  */
  while (unknown()) {

    if ( c < 36 )
    {
      z  = z + 1;
      c  = c + 1;
    }
  }
}
