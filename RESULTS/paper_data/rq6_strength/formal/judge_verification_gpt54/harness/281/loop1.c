#include <limits.h>

/*@ logic integer count_divisors_upto(integer num, integer n) =
    n <= 0 ? 0 :
    count_divisors_upto(num, n - 1) + (n <= num && num % n == 0 ? 1 : 0); */

/*@ requires (num == \at(num,Pre)) && (0 <= result) && (1 <= index) && (result == count_divisors_upto(num, index - 1)) && (result <= index - 1);
    assigns \nothing;
*/
void check_A_implies_B(int index, int k, int num) {
    /*@ assert (result >= 0 && result <= index); */
    /*@ assert (result >= 0 && result <= index - 1); */
    /*@ assert (result >= 0 && index >= 1); */
    /*@ assert (result == 0 || result >= 1); */
    /*@ assert (result == 0 || result >= 0); */
    /*@ assert (result == 0 || result > 0); */
    /*@ assert (result <= index); */
    /*@ assert (result <= index - 1); */
    /*@ assert (result <= index - 1 + 1); */
    /*@ assert (result <= index + 1); */
    /*@ assert (result < index); */
    /*@ assert (result - index <= 0); */
    /*@ assert (result % 2 == result % 2); */
    /*@ assert (result % 2 == 0 || result % 2 == 1); */
    /*@ assert (index == result || index > result); */
    /*@ assert (index == result + 1 || index > result); */
    /*@ assert (index - result <= index); */
    /*@ assert (\forall integer k; 1 <= k < index ==> num % k != 0 || result >= 1); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (num % k == 0 || num % k != 0)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (num % k == 0 ==> result >= 1)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (num % k == 0 ==> result >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (num % k == 0 ==> result <= index)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (num % k == 0 ==> result <= index - 1)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (num % k != 0 || result >= 1)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (num % k != 0 || result >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (num % k != 0 || result <= index)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (num % k != 0 || result <= index - 1)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (num % k != 0 ==> result >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < index && num % k == 0 ==> result >= 1); */
    /*@ assert (\exists integer k; 1 <= k < index && num % k == 0 ==> result >= 1); */
    /*@ assert (\exists integer k; 1 <= k < index && num % k == 0 ==> result >= 0); */
    /*@ assert (1 <= index); */
    /*@ assert (1 <= index - result); */
    /*@ assert (0 <= result); */
    /*@ assert (0 <= index); */
    /*@ assert (0 <= index - result); */
    /*@ assert (0 < index); */
}

/*@ requires (result >= 0 && result <= index) && (result >= 0 && result <= index - 1) && (result >= 0 && index >= 1) && (result == 0 || result >= 1) && (result == 0 || result >= 0) && (result == 0 || result > 0) && (result <= index) && (result <= index - 1) && (result <= index - 1 + 1) && (result <= index + 1) && (result < index) && (result - index <= 0) && (result % 2 == result % 2) && (result % 2 == 0 || result % 2 == 1) && (index == result || index > result) && (index == result + 1 || index > result) && (index - result <= index) && (\forall integer k; 1 <= k < index ==> num % k != 0 || result >= 1) && (\forall integer k; 1 <= k < index ==> (num % k == 0 || num % k != 0)) && (\forall integer k; 1 <= k < index ==> (num % k == 0 ==> result >= 1)) && (\forall integer k; 1 <= k < index ==> (num % k == 0 ==> result >= 0)) && (\forall integer k; 1 <= k < index ==> (num % k == 0 ==> result <= index)) && (\forall integer k; 1 <= k < index ==> (num % k == 0 ==> result <= index - 1)) && (\forall integer k; 1 <= k < index ==> (num % k != 0 || result >= 1)) && (\forall integer k; 1 <= k < index ==> (num % k != 0 || result >= 0)) && (\forall integer k; 1 <= k < index ==> (num % k != 0 || result <= index)) && (\forall integer k; 1 <= k < index ==> (num % k != 0 || result <= index - 1)) && (\forall integer k; 1 <= k < index ==> (num % k != 0 ==> result >= 0)) && (\forall integer k; 1 <= k < index && num % k == 0 ==> result >= 1) && (\exists integer k; 1 <= k < index && num % k == 0 ==> result >= 1) && (\exists integer k; 1 <= k < index && num % k == 0 ==> result >= 0) && (1 <= index) && (1 <= index - result) && (0 <= result) && (0 <= index) && (0 <= index - result) && (0 < index);
    assigns \nothing;
*/
void check_B_implies_A(int index, int k, int num) {
    /*@ assert (num == \at(num,Pre)); */
    /*@ assert (0 <= result); */
    /*@ assert (1 <= index); */
    /*@ assert (result == count_divisors_upto(num, index - 1)); */
    /*@ assert (result <= index - 1); */
}
