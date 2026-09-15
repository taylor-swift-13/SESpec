#include <limits.h>

/*@ logic integer count_divisors(integer n, integer z) =
      z <= 0 ? 0 :
      count_divisors(n, z - 1) + ((n % z) == 0 ? 1 : 0); */

/*@ requires (1 <= loop <= z + 1) && (0 <= result <= loop - 1) && (result == count_divisors(n, loop - 1)) && (\forall integer k; 1 <= k < loop ==> (n % k == 0 || n % k != 0)) && (\forall integer k; 1 <= k < loop ==> (n % k == 0 ==> result >= 1)) && ((loop > z) ==> (result == count_divisors(n, z))) && ((loop > z) ==> (0 <= result <= z)) && ((loop > z) ==> (z == (\at(z,Pre) >= 0 ? \at(z,Pre) : -\at(z,Pre)))) && ((loop > z) ==> (n == \at(n,Pre)));
    assigns \nothing;
*/
void check_A_implies_B(int i, int k, int n, int z) {
    /*@ assert (\forall integer k; 1 <= k < loop ==> (n % k != 0 || result == result)); */
    /*@ assert (\forall integer i; 1 <= i < loop ==> (n % i == 0 || n % i != 0)); */
    /*@ assert (\forall integer i; 1 <= i < loop ==> (n % i == 0 ==> result >= 1)); */
    /*@ assert (\forall integer i; 1 <= i < loop ==> (n % i != 0 ==> result >= 0)); */
    /*@ assert (\exists integer k; 1 <= k < loop && n % k == 0 ==> result >= 0); */
    /*@ assert (\exists integer k; 1 <= k < loop && n % k == 0 ==> result > 0); */
    /*@ assert (result == 0 || result >= 1); */
    /*@ assert (result == 0 || result > 0); */
    /*@ assert (result <= z); */
    /*@ assert (result <= loop); */
    /*@ assert (result <= loop - 1); */
    /*@ assert (loop <= z + 1); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> result >= 0); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (n % k == 0 || n % k != 0)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (n % k == 0 ==> result >= 1)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (n % k == 0 ==> result >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (n % k == 0 ==> result <= loop)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (n % k == 0 ==> result <= loop - 1)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (n % k != 0 || result >= 1)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (n % k != 0 || result >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (n % k != 0 || result <= loop)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (n % k != 0 ==> result >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (n % k != 0 ==> result == result)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (n % k != 0 ==> result <= loop)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (n % k != 0 ==> result <= loop - 1)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> ((n % k == 0) ==> result >= 1)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> ((n % k == 0) ==> result >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> ((n % k == 0) ==> result <= loop)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> ((n % k == 0) ==> result <= loop - 1)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> ((n % k != 0) || (result >= 0))); */
    /*@ assert (\forall integer i; 1 <= i < loop ==> (n % i != 0 || result >= 1)); */
    /*@ assert (\exists integer k; 1 <= k < loop && n % k == 0 ==> result >= 1); */
    /*@ assert (1 <= loop); */
    /*@ assert (0 <= z); */
    /*@ assert (0 <= result); */
    /*@ assert (0 <= loop); */
}

/*@ requires (\forall integer k; 1 <= k < loop ==> (n % k != 0 || result == result)) && (\forall integer i; 1 <= i < loop ==> (n % i == 0 || n % i != 0)) && (\forall integer i; 1 <= i < loop ==> (n % i == 0 ==> result >= 1)) && (\forall integer i; 1 <= i < loop ==> (n % i != 0 ==> result >= 0)) && (\exists integer k; 1 <= k < loop && n % k == 0 ==> result >= 0) && (\exists integer k; 1 <= k < loop && n % k == 0 ==> result > 0) && (result == 0 || result >= 1) && (result == 0 || result > 0) && (result <= z) && (result <= loop) && (result <= loop - 1) && (loop <= z + 1) && (\forall integer k; 1 <= k < loop ==> result >= 0) && (\forall integer k; 1 <= k < loop ==> (n % k == 0 || n % k != 0)) && (\forall integer k; 1 <= k < loop ==> (n % k == 0 ==> result >= 1)) && (\forall integer k; 1 <= k < loop ==> (n % k == 0 ==> result >= 0)) && (\forall integer k; 1 <= k < loop ==> (n % k == 0 ==> result <= loop)) && (\forall integer k; 1 <= k < loop ==> (n % k == 0 ==> result <= loop - 1)) && (\forall integer k; 1 <= k < loop ==> (n % k != 0 || result >= 1)) && (\forall integer k; 1 <= k < loop ==> (n % k != 0 || result >= 0)) && (\forall integer k; 1 <= k < loop ==> (n % k != 0 || result <= loop)) && (\forall integer k; 1 <= k < loop ==> (n % k != 0 ==> result >= 0)) && (\forall integer k; 1 <= k < loop ==> (n % k != 0 ==> result == result)) && (\forall integer k; 1 <= k < loop ==> (n % k != 0 ==> result <= loop)) && (\forall integer k; 1 <= k < loop ==> (n % k != 0 ==> result <= loop - 1)) && (\forall integer k; 1 <= k < loop ==> ((n % k == 0) ==> result >= 1)) && (\forall integer k; 1 <= k < loop ==> ((n % k == 0) ==> result >= 0)) && (\forall integer k; 1 <= k < loop ==> ((n % k == 0) ==> result <= loop)) && (\forall integer k; 1 <= k < loop ==> ((n % k == 0) ==> result <= loop - 1)) && (\forall integer k; 1 <= k < loop ==> ((n % k != 0) || (result >= 0))) && (\forall integer i; 1 <= i < loop ==> (n % i != 0 || result >= 1)) && (\exists integer k; 1 <= k < loop && n % k == 0 ==> result >= 1) && (1 <= loop) && (0 <= z) && (0 <= result) && (0 <= loop);
    assigns \nothing;
*/
void check_B_implies_A(int i, int k, int n, int z) {
    /*@ assert (1 <= loop <= z + 1); */
    /*@ assert (0 <= result <= loop - 1); */
    /*@ assert (result == count_divisors(n, loop - 1)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (n % k == 0 || n % k != 0)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (n % k == 0 ==> result >= 1)); */
    /*@ assert ((loop > z) ==> (result == count_divisors(n, z))); */
    /*@ assert ((loop > z) ==> (0 <= result <= z)); */
    /*@ assert ((loop > z) ==> (z == (\at(z,Pre) >= 0 ? \at(z,Pre) : -\at(z,Pre)))); */
    /*@ assert ((loop > z) ==> (n == \at(n,Pre))); */
}
