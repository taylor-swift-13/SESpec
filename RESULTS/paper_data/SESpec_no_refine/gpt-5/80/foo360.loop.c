
/*@ requires \true;
    ensures \result == 0 || \result == 1;
*/
int unknown();

void foo360(int y,int x1,int x2,int x3) {
  int c = 0;
  int z = 36 * y;

  /*@
    loop invariant c >= 0;
    loop invariant c <= 36;
    loop invariant z - c == 36 * \at(y,Pre);
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
