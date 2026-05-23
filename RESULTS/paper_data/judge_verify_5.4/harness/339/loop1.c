#include <limits.h>

/*@ logic integer divcount(integer n, integer i) =
      i <= 0 ? 0 : divcount(n, i - 1) + (n % i == 0 ? 1 : 0); */

/*@ requires (1 <= index <= z + 1) && (0 <= result <= index - 1) && (result == divcount(num, index - 1)) && (z >= 0) && (num == \at(num,Pre)) && (z == (\at(z,Pre) < 0 ? -\at(z,Pre) : \at(z,Pre)));
    assigns \nothing;
*/
void check_A_implies_B(int index, int k, int num, int z) {
    /*@ assert (result == 0 || result <= z + 1); */
    /*@ assert (result > 0 ==> \exists integer k; 1 <= k < index && num % k == 0); */
    /*@ assert (result == 0 || result >= 1); */
    /*@ assert (result == 0 || result > 0); */
    /*@ assert (result == 0 || result <= z); */
    /*@ assert (result == 0 || result <= index); */
    /*@ assert (result == 0 || result <= index - 1); */
    /*@ assert (result == 0 ==> \forall integer k; 1 <= k < index ==> num % k != 0); */
    /*@ assert (result <= z); */
    /*@ assert (result <= z + 1); */
    /*@ assert (result <= index); */
    /*@ assert (result <= index - 1); */
    /*@ assert (result <= index - 1 || result == index); */
    /*@ assert (index <= z + 1); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (num % k == 0 || num % k != 0)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (num % k == 0 ==> result >= 1)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (num % k == 0 ==> result >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (num % k == 0 ==> result <= index)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (num % k != 0 || result >= 1)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (num % k != 0 || result >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (num % k != 0 || result <= index)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (num % k != 0 ==> result >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (num % k != 0 ==> result <= index)); */
    /*@ assert (\exists integer k; 1 <= k < index && num % k == 0 ==> result >= 1); */
    /*@ assert (\exists integer k; 1 <= k < index && num % k == 0 ==> result >= 0); */
    /*@ assert (\exists integer k; 1 <= k < index && num % k == 0 ==> result > 0); */
    /*@ assert (1 <= index); */
    /*@ assert (0 <= z); */
    /*@ assert (0 <= result); */
    /*@ assert (0 <= index); */
    /*@ assert (0 <= index - result); */
}

/*@ requires (result == 0 || result <= z + 1) && (result > 0 ==> \exists integer k; 1 <= k < index && num % k == 0) && (result == 0 || result >= 1) && (result == 0 || result > 0) && (result == 0 || result <= z) && (result == 0 || result <= index) && (result == 0 || result <= index - 1) && (result == 0 ==> \forall integer k; 1 <= k < index ==> num % k != 0) && (result <= z) && (result <= z + 1) && (result <= index) && (result <= index - 1) && (result <= index - 1 || result == index) && (index <= z + 1) && (\forall integer k; 1 <= k < index ==> (num % k == 0 || num % k != 0)) && (\forall integer k; 1 <= k < index ==> (num % k == 0 ==> result >= 1)) && (\forall integer k; 1 <= k < index ==> (num % k == 0 ==> result >= 0)) && (\forall integer k; 1 <= k < index ==> (num % k == 0 ==> result <= index)) && (\forall integer k; 1 <= k < index ==> (num % k != 0 || result >= 1)) && (\forall integer k; 1 <= k < index ==> (num % k != 0 || result >= 0)) && (\forall integer k; 1 <= k < index ==> (num % k != 0 || result <= index)) && (\forall integer k; 1 <= k < index ==> (num % k != 0 ==> result >= 0)) && (\forall integer k; 1 <= k < index ==> (num % k != 0 ==> result <= index)) && (\exists integer k; 1 <= k < index && num % k == 0 ==> result >= 1) && (\exists integer k; 1 <= k < index && num % k == 0 ==> result >= 0) && (\exists integer k; 1 <= k < index && num % k == 0 ==> result > 0) && (1 <= index) && (0 <= z) && (0 <= result) && (0 <= index) && (0 <= index - result);
    assigns \nothing;
*/
void check_B_implies_A(int index, int k, int num, int z) {
    /*@ assert (1 <= index <= z + 1); */
    /*@ assert (0 <= result <= index - 1); */
    /*@ assert (result == divcount(num, index - 1)); */
    /*@ assert (z >= 0); */
    /*@ assert (num == \at(num,Pre)); */
    /*@ assert (z == (\at(z,Pre) < 0 ? -\at(z,Pre) : \at(z,Pre))); */
}
