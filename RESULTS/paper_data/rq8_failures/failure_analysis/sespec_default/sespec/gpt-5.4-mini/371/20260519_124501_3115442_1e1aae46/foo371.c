
/*@
  requires 0 <= z && z < p;
  requires value >= 0;
  assigns \nothing;
*/
int foo371(int value, int p, int z) {

    int result = 0;

    /*@
      loop invariant z == \at(z, Pre);
      loop invariant p == \at(p, Pre);
      loop invariant value == \at(value, Pre);
      loop assigns c, result;
    */
    for (int c = 1; c <= value; c++) {
        if ((c % p) == z) {
            result = c;
        }
    }

    return result;
}
