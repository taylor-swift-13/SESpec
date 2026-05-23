
/*@
  requires value >= 0;
  requires p > 0;
  requires z >= 0 && z < p;
  assigns \nothing;
  ensures \result == 0 || (\result % p == z && \result <= value);
  ensures \forall integer k; 1 <= k <= value ==> ((k % p == z) ==> \result >= k);
*/
int foo371(int value, int p, int z) {

    int result = 0;

    /*@
      loop invariant 1 <= c <= value + 1;
      loop invariant result == 0 || (result % p == z && result <= c - 1);
      loop invariant \forall integer k; 1 <= k < c ==> ((k % p == z) ==> result >= k);
      loop invariant z == \at(z, Pre);
      loop invariant p == \at(p, Pre);
      loop invariant value == \at(value, Pre);
      loop assigns result;
    */
    for (int c = 1; c <= value; c++) {
        if ((c % p) == z) {
            result = c;
        }
    }

    return result;
}
