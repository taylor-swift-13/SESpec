/*@ axiomatic Unknown {
      logic integer unknown();
    }
*/

/*@ assigns \nothing;
    ensures \result == unknown();
*/
int unknown();

void foo73(int y) {
  int c = 0;
  int z = 36 * y;

  /*@ loop invariant 0 <= c <= 36;
      loop invariant z == 36*y + c;
      loop assigns c, z;
      loop variant 36 - c;
  */
  while (unknown()) {

    if ( c < 36 )
    {
    z  = z + 1;
    c  = c + 1;
    }
  }

}
