#include <limits.h>

/*@logic integer divcount(integer n, integer d) =
    d <= 0 ? 0 : divcount(n, d - 1) + ((d != 0 && n % d == 0) ? 1 : 0);*/

/*@ requires (1 <= loop <= z + 1) && (0 <= result <= loop - 1) && (result == divcount(num, loop - 1)) && ((\forall integer k) && (z == (\at(z,Pre) >= 0 ? \at(z,Pre) : -\at(z,Pre))) && (num == \at(num,Pre)) && ((loop <= z + 1) ==> (0 <= result <= z)) && ((loop > z) ==> (result == divcount(num, z)));
    assigns \nothing;
*/
void check_A_implies_B(int i, int k, int num, int z) {
    /*@ assert (result == 0 || result >= 1) && (result == 0 || result >= 0) && (result == 0 || result > 0) && (result <= z) && (result <= z + 1) && (result <= loop) && (result <= loop - 1) && (result <= loop - 1 || result == loop) && (result <= loop - 1 || result == loop - 1) && (loop <= z + 1) && (loop - result <= z + 1) && (loop - result <= loop) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer i) && (\forall integer i) && (\forall integer i) && (\forall integer i) && (\forall integer i) && (\forall integer i) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (1 <= loop) && (1 <= loop - result) && (0 <= result) && (0 <= loop) && (0 <= loop - result) && (0 < loop); */
}

/*@ requires (result == 0 || result >= 1) && (result == 0 || result >= 0) && (result == 0 || result > 0) && (result <= z) && (result <= z + 1) && (result <= loop) && (result <= loop - 1) && (result <= loop - 1 || result == loop) && (result <= loop - 1 || result == loop - 1) && (loop <= z + 1) && (loop - result <= z + 1) && (loop - result <= loop) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer i) && (\forall integer i) && (\forall integer i) && (\forall integer i) && (\forall integer i) && (\forall integer i) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (1 <= loop) && (1 <= loop - result) && (0 <= result) && (0 <= loop) && (0 <= loop - result) && (0 < loop);
    assigns \nothing;
*/
void check_B_implies_A(int i, int k, int num, int z) {
    /*@ assert (1 <= loop <= z + 1) && (0 <= result <= loop - 1) && (result == divcount(num, loop - 1)) && ((\forall integer k) && (z == (\at(z,Pre) >= 0 ? \at(z,Pre) : -\at(z,Pre))) && (num == \at(num,Pre)) && ((loop <= z + 1) ==> (0 <= result <= z)) && ((loop > z) ==> (result == divcount(num, z))); */
}
