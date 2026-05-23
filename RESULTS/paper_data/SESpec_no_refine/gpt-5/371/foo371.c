
/*@
  predicate is_match(integer c, integer p, integer z) = (c % p) == z;
*/

/*@
  ensures last_match_up_to(value, p, z, \result);
  assigns \nothing;
*/
int foo371(int value, int p, int z) {

    int result = 0;

    /*@
      loop invariant z == \at(z,Pre);
      loop invariant p == \at(p,Pre);
      loop invariant value == \at(value,Pre);
      loop assigns c, result;
    */
    for (int c = 1; c <= value; c++) {
        if ((c % p) == z) {
            result = c;
        }
    }

    return result;
}
