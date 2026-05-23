/*@ assigns \nothing; */
int unknown();

/*@
  assigns \nothing;
*/
void foo75(int y,int x1,int x2,int x3) {
  int c = 0;
  int z = 36 * y;

  /*@
    loop invariant 0 <= c <= 36;
    loop invariant z == 36*y + c;
    loop assigns c, z;
  */
  while (unknown()) {

    if ( c < 36 )
    {
    z  = z + 1;
    c  = c + 1;
    }
  }

  /*@ assert 0 <= c <= 36; */
  /*@ assert z == 36*y + c; */
}
