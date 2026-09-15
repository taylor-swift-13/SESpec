/*@ assigns \nothing; */
int unknown();

/*@ 
  assigns \nothing;
  ensures 0 <= c <= 36;
  ensures z - c == 36*y;
*/
void foo72(int y) {
  int c = 0;
  int z = 36 * y;

  /*@ 
    loop invariant 0 <= c <= 36;
    loop invariant z - c == 36*y;
    loop assigns c, z;
  */
  while (unknown()) {

    if ( c < 36 )
    {
    z  = z + 1;
    c  = c + 1;
    }
  }

}
