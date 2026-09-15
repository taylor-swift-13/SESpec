#include <limits.h>

/*@logic integer divcount(integer n, integer i) =
      i <= 0 ? 0 : divcount(n, i - 1) + (n % i == 0 ? 1 : 0);*/

/*@ requires (1 <= index <= z + 1) && (0 <= result <= index - 1) && (result == divcount(num, index - 1)) && (z >= 0) && (num == \at(num,Pre)) && (z == (\at(z,Pre) < 0 ? -\at(z,Pre) : \at(z,Pre)));
    assigns \nothing;
*/
void check_A_implies_B(int index, int k, int num, int z) {
    /*@ assert (result == 0 || result <= z + 1) && (result > 0 ==> \exists integer k) && (result == 0 || result >= 1) && (result == 0 || result > 0) && (result == 0 || result <= z) && (result == 0 || result <= index) && (result == 0 || result <= index - 1) && (result == 0 ==> \forall integer k) && (result <= z) && (result <= z + 1) && (result <= index) && (result <= index - 1) && (result <= index - 1 || result == index) && (index <= z + 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (1 <= index) && (0 <= z) && (0 <= result) && (0 <= index) && (0 <= index - result); */
}

/*@ requires (result == 0 || result <= z + 1) && (result > 0 ==> \exists integer k) && (result == 0 || result >= 1) && (result == 0 || result > 0) && (result == 0 || result <= z) && (result == 0 || result <= index) && (result == 0 || result <= index - 1) && (result == 0 ==> \forall integer k) && (result <= z) && (result <= z + 1) && (result <= index) && (result <= index - 1) && (result <= index - 1 || result == index) && (index <= z + 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (1 <= index) && (0 <= z) && (0 <= result) && (0 <= index) && (0 <= index - result);
    assigns \nothing;
*/
void check_B_implies_A(int index, int k, int num, int z) {
    /*@ assert (1 <= index <= z + 1) && (0 <= result <= index - 1) && (result == divcount(num, index - 1)) && (z >= 0) && (num == \at(num,Pre)) && (z == (\at(z,Pre) < 0 ? -\at(z,Pre) : \at(z,Pre))); */
}
