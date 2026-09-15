#include <limits.h>

/*@logic integer count_divisors(integer n, integer z) =
      z <= 0 ? 0 :
      count_divisors(n, z - 1) + ((n % z) == 0 ? 1 : 0);*/

/*@ requires (1 <= loop <= z + 1) && (0 <= result <= loop - 1) && (result == count_divisors(n, loop - 1)) && (\forall integer k) && (\forall integer k) && ((loop > z) ==> (result == count_divisors(n, z))) && ((loop > z) ==> (0 <= result <= z)) && ((loop > z) ==> (z == (\at(z,Pre) >= 0 ? \at(z,Pre) : -\at(z,Pre)))) && ((loop > z) ==> (n == \at(n,Pre)));
    assigns \nothing;
*/
void check_A_implies_B(int i, int k, int n, int z) {
    /*@ assert (\forall integer k) && (\forall integer i) && (\forall integer i) && (\forall integer i) && (\exists integer k) && (\exists integer k) && (result == 0 || result >= 1) && (result == 0 || result > 0) && (result <= z) && (result <= loop) && (result <= loop - 1) && (loop <= z + 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer i) && (\exists integer k) && (1 <= loop) && (0 <= z) && (0 <= result) && (0 <= loop); */
}

/*@ requires (\forall integer k) && (\forall integer i) && (\forall integer i) && (\forall integer i) && (\exists integer k) && (\exists integer k) && (result == 0 || result >= 1) && (result == 0 || result > 0) && (result <= z) && (result <= loop) && (result <= loop - 1) && (loop <= z + 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer i) && (\exists integer k) && (1 <= loop) && (0 <= z) && (0 <= result) && (0 <= loop);
    assigns \nothing;
*/
void check_B_implies_A(int i, int k, int n, int z) {
    /*@ assert (1 <= loop <= z + 1) && (0 <= result <= loop - 1) && (result == count_divisors(n, loop - 1)) && (\forall integer k) && (\forall integer k) && ((loop > z) ==> (result == count_divisors(n, z))) && ((loop > z) ==> (0 <= result <= z)) && ((loop > z) ==> (z == (\at(z,Pre) >= 0 ? \at(z,Pre) : -\at(z,Pre)))) && ((loop > z) ==> (n == \at(n,Pre))); */
}
