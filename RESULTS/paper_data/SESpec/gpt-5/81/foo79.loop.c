


int unknown();

void foo79(int y,int x1,int x2,int x3) {
  int c = 0;
  int z = 36 * y;

  /*@
    loop invariant z - c == 36 * \at(y,Pre);
    loop invariant c == 36 ==> z == 36 * \at(y,Pre) + 36;
    loop invariant c < 36 ==> z < 36 * \at(y,Pre) + 36;
    loop invariant c == 0 ==> z == 36 * \at(y,Pre);
    loop invariant z == 36 * \at(y,Pre) ==> c == 0;
    loop invariant z == 36 * \at(y,Pre) + c;
    loop invariant z == 36 * \at(y,Pre) + c;
    loop invariant 0 <= c <= 36;
    loop invariant c == z - 36 * \at(y,Pre);
    loop invariant 36 * \at(y,Pre) <= z <= 36 * \at(y,Pre) + 36;
    loop invariant x3 == \at(x3,Pre);
    loop invariant x2 == \at(x2,Pre);
    loop invariant x1 == \at(x1,Pre);
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
