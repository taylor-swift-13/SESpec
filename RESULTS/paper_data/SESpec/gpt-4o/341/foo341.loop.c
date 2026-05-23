
/*@
  logic integer count_divisors(integer num, integer limit) =
    limit <= 0 ? 0 : (num % limit == 0 ? 1 : 0) + count_divisors(num, limit - 1);
*/

/*@
  requires (\at(z,Pre) >= 0 && z == \at(z,Pre) && num == \at(num,Pre)) || (\at(z,Pre) < 0 && z == -\at(z,Pre) && num == \at(num,Pre));
  ensures \result == count_divisors(num, z);
*/
int foo341(int num, int z) {

    if (z < 0) {
        z = -z;
    }
    int result = 0;

    /*@
      loop invariant 1 <= loop <= z + 1;
      loop invariant result == count_divisors(num, loop - 1);
      loop invariant \forall integer k; 1 <= k < loop ==> (num % k == 0 ==> count_divisors(num, k) == count_divisors(num, k - 1) + 1);
      loop invariant \forall integer k; 1 <= k < loop ==> (num % k != 0 ==> count_divisors(num, k) == count_divisors(num, k - 1));
      loop invariant z == \at(z,Pre);
      loop invariant num == \at(num,Pre);
      loop assigns loop, result;
    */
    for (int loop = 1; loop <= z; loop++) {
        if (num % loop == 0) {
            result = result + 1;
        }
    }

    return result;
}
