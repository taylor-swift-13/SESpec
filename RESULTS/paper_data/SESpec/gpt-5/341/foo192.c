
/*@ logic integer count_divisors_upto(integer num, integer k) =
      k <= 0 ? 0 :
      count_divisors_upto(num, k - 1) + ((k != 0 && num % k == 0) ? 1 : 0);
*/

/*@
  assigns \nothing;
  ensures (\old(z) >= 0 ==> \result == count_divisors_upto(num, \old(z)))
       && (\old(z) < 0 ==> \result == count_divisors_upto(num, -\old(z)));
*/
int foo192(int num, int z) {

    if (z < 0) {
        z = -z;
    }
    int result = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */

    /*@
      loop invariant 1 <= loop <= z + 1;
      loop invariant z >= 0;
      loop invariant 0 <= result <= loop - 1;
      loop invariant result == count_divisors_upto(num, loop - 1);
      loop assigns loop, result;
    */
    for (int loop = 1; loop <= z; loop++) {
        if (num % loop == 0) {
            result = result + 1;
        }
    }

    return result;
}
