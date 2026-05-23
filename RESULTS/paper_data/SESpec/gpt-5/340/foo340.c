


/*@
  assigns \nothing;
  ensures z >= 0 ==> \result >= 0;
  ensures z < 0 ==> \result >= 0;
  ensures z == 0 ==> \result == 0;
  ensures \forall integer d; d < 1 ==> \true;
  ensures \forall integer d; d > (z >= 0 ? z : -z) ==> \true;
*/
int foo340(int n, int z) {

    if (z < 0) {
        z = -z;
    }
    int result = 0;

    /*@
      loop invariant 1 <= loop <= z + 1;
      loop invariant n == \at(n,Pre);
      loop invariant result >= 0;
      loop invariant result <= loop - 1;
      loop invariant \forall integer d; 1 <= d < loop ==> ((n % d == 0) || (n % d != 0));
      loop invariant \forall integer d; (1 <= d && d < loop && (n % d == 0)) ==> (0 <= d && d <= z);
      loop invariant \forall integer t; 1 <= t < loop ==> result >= 0;
      loop invariant \forall integer k; 1 <= k < loop ==> 
                      ((n % k == 0) ==> result >= 1) || ((n % k != 0) ==> result >= 0);
      loop invariant (loop <= \at(z,Pre)) ==> (loop >= 1 && loop <= z);
      loop invariant (loop <= \at(z,Pre)) ==> (result >= 0 && result <= loop - 1);
      loop assigns loop, result;
    */
    for (int loop = 1; loop <= z; loop++) {
        if (n % loop == 0) {
            result = result + 1;
        }
    }

    return result;
}
