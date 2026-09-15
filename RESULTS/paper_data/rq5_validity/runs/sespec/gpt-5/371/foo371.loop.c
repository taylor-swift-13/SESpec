
/* No additional predicates or logic functions are needed. */

int foo371(int value, int p, int z) {

    int result = 0;
        
    /*@
      loop invariant z == \at(z,Pre);
      loop invariant p == \at(p,Pre);
      loop invariant value == \at(value,Pre);
      loop invariant result != 0 ==> (result % p) == z;
      loop invariant result == 0 ==> \forall integer k; 1 <= k < c ==> (k % p) != z;
      loop invariant result != 0 ==> (\forall integer k; result < k < c ==> (k % p) != z);
      loop invariant (c <= \at(value,Pre)) ==> (result == 0 || (result % p) == z);
      loop assigns c, result;
    */
    for (int c = 1; c <= value; c++) {
        if ((c % p) == z) {
            result = c;
        }
    }
        
    return result;
}
