#include <limits.h>

/*@ logic integer divcount(integer n, integer d) =
    d <= 0 ? 0 : divcount(n, d - 1) + ((d != 0 && n % d == 0) ? 1 : 0); */

/*@ requires (1 <= loop <= z + 1) && (0 <= result <= loop - 1) && (result == divcount(num, loop - 1)) && ((\forall integer k; 1 <= k < loop ==> (num % k == 0) ==> result >= 0)) && (z == (\at(z,Pre) >= 0 ? \at(z,Pre) : -\at(z,Pre))) && (num == \at(num,Pre)) && ((loop <= z + 1) ==> (0 <= result <= z)) && ((loop > z) ==> (result == divcount(num, z)));
    assigns \nothing;
*/
void check_A_implies_B(int i, int k, int num, int z) {
    /*@ assert (result == 0 || result >= 1); */
    /*@ assert (result == 0 || result >= 0); */
    /*@ assert (result == 0 || result > 0); */
    /*@ assert (result <= z); */
    /*@ assert (result <= z + 1); */
    /*@ assert (result <= loop); */
    /*@ assert (result <= loop - 1); */
    /*@ assert (result <= loop - 1 || result == loop); */
    /*@ assert (result <= loop - 1 || result == loop - 1); */
    /*@ assert (loop <= z + 1); */
    /*@ assert (loop - result <= z + 1); */
    /*@ assert (loop - result <= loop); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (num % k == 0 || num % k != 0)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (num % k == 0 ==> result >= 1)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (num % k == 0 ==> result >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (num % k == 0 ==> result <= loop)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (num % k == 0 ==> result <= loop - 1)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (num % k != 0 || result >= 1)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (num % k != 0 || result >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (num % k != 0 || result == result)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (num % k != 0 || result == 0 || result > 0)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (num % k != 0 || result <= loop)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (num % k != 0 || result <= loop - 1)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (num % k != 0 ==> result >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (num % k != 0 ==> result == result)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (num % k != 0 ==> result == 0 || result > 0)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (num % k != 0 ==> result <= loop)); */
    /*@ assert (\forall integer k; 1 <= k < loop ==> (num % k != 0 ==> result <= loop - 1)); */
    /*@ assert (\forall integer i; 1 <= i < loop ==> (num % i == 0 || num % i != 0)); */
    /*@ assert (\forall integer i; 1 <= i < loop ==> (num % i == 0 ==> result >= 1)); */
    /*@ assert (\forall integer i; 1 <= i < loop ==> (num % i != 0 || result == 0 || result > 0)); */
    /*@ assert (\forall integer i; 1 <= i < loop ==> (num % i != 0 || result <= loop - 1)); */
    /*@ assert (\forall integer i; 1 <= i < loop ==> (num % i != 0 ==> result >= 0)); */
    /*@ assert (\forall integer i; 1 <= i < loop ==> (num % i != 0 ==> result <= loop - 1)); */
    /*@ assert (\exists integer k; 1 <= k <= loop && num % k == 0 ==> result >= 0); */
    /*@ assert (\exists integer k; 1 <= k <= loop && num % k == 0 ==> result > 0); */
    /*@ assert (\exists integer k; 1 <= k < loop ==> (num % k == 0)); */
    /*@ assert (\exists integer k; 1 <= k < loop && num % k == 0 ==> result >= 1); */
    /*@ assert (\exists integer k; 1 <= k < loop && num % k == 0 ==> result >= 0); */
    /*@ assert (\exists integer k; 1 <= k < loop && num % k == 0 ==> result > 0); */
    /*@ assert (1 <= loop); */
    /*@ assert (1 <= loop - result); */
    /*@ assert (0 <= result); */
    /*@ assert (0 <= loop); */
    /*@ assert (0 <= loop - result); */
    /*@ assert (0 < loop); */
}

/*@ requires (result == 0 || result >= 1) && (result == 0 || result >= 0) && (result == 0 || result > 0) && (result <= z) && (result <= z + 1) && (result <= loop) && (result <= loop - 1) && (result <= loop - 1 || result == loop) && (result <= loop - 1 || result == loop - 1) && (loop <= z + 1) && (loop - result <= z + 1) && (loop - result <= loop) && (\forall integer k; 1 <= k < loop ==> (num % k == 0 || num % k != 0)) && (\forall integer k; 1 <= k < loop ==> (num % k == 0 ==> result >= 1)) && (\forall integer k; 1 <= k < loop ==> (num % k == 0 ==> result >= 0)) && (\forall integer k; 1 <= k < loop ==> (num % k == 0 ==> result <= loop)) && (\forall integer k; 1 <= k < loop ==> (num % k == 0 ==> result <= loop - 1)) && (\forall integer k; 1 <= k < loop ==> (num % k != 0 || result >= 1)) && (\forall integer k; 1 <= k < loop ==> (num % k != 0 || result >= 0)) && (\forall integer k; 1 <= k < loop ==> (num % k != 0 || result == result)) && (\forall integer k; 1 <= k < loop ==> (num % k != 0 || result == 0 || result > 0)) && (\forall integer k; 1 <= k < loop ==> (num % k != 0 || result <= loop)) && (\forall integer k; 1 <= k < loop ==> (num % k != 0 || result <= loop - 1)) && (\forall integer k; 1 <= k < loop ==> (num % k != 0 ==> result >= 0)) && (\forall integer k; 1 <= k < loop ==> (num % k != 0 ==> result == result)) && (\forall integer k; 1 <= k < loop ==> (num % k != 0 ==> result == 0 || result > 0)) && (\forall integer k; 1 <= k < loop ==> (num % k != 0 ==> result <= loop)) && (\forall integer k; 1 <= k < loop ==> (num % k != 0 ==> result <= loop - 1)) && (\forall integer i; 1 <= i < loop ==> (num % i == 0 || num % i != 0)) && (\forall integer i; 1 <= i < loop ==> (num % i == 0 ==> result >= 1)) && (\forall integer i; 1 <= i < loop ==> (num % i != 0 || result == 0 || result > 0)) && (\forall integer i; 1 <= i < loop ==> (num % i != 0 || result <= loop - 1)) && (\forall integer i; 1 <= i < loop ==> (num % i != 0 ==> result >= 0)) && (\forall integer i; 1 <= i < loop ==> (num % i != 0 ==> result <= loop - 1)) && (\exists integer k; 1 <= k <= loop && num % k == 0 ==> result >= 0) && (\exists integer k; 1 <= k <= loop && num % k == 0 ==> result > 0) && (\exists integer k; 1 <= k < loop ==> (num % k == 0)) && (\exists integer k; 1 <= k < loop && num % k == 0 ==> result >= 1) && (\exists integer k; 1 <= k < loop && num % k == 0 ==> result >= 0) && (\exists integer k; 1 <= k < loop && num % k == 0 ==> result > 0) && (1 <= loop) && (1 <= loop - result) && (0 <= result) && (0 <= loop) && (0 <= loop - result) && (0 < loop);
    assigns \nothing;
*/
void check_B_implies_A(int i, int k, int num, int z) {
    /*@ assert (1 <= loop <= z + 1); */
    /*@ assert (0 <= result <= loop - 1); */
    /*@ assert (result == divcount(num, loop - 1)); */
    /*@ assert ((\forall integer k; 1 <= k < loop ==> (num % k == 0) ==> result >= 0)); */
    /*@ assert (z == (\at(z,Pre) >= 0 ? \at(z,Pre) : -\at(z,Pre))); */
    /*@ assert (num == \at(num,Pre)); */
    /*@ assert ((loop <= z + 1) ==> (0 <= result <= z)); */
    /*@ assert ((loop > z) ==> (result == divcount(num, z))); */
}
