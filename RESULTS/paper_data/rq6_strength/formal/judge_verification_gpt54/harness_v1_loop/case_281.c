#include <limits.h>

/*@logic integer count_divisors_upto(integer num, integer n) =
    n <= 0 ? 0 :
    count_divisors_upto(num, n - 1) + (n <= num && num % n == 0 ? 1 : 0);*/

/*@ requires (num == \at(num,Pre)) && (0 <= result) && (1 <= index) && (result == count_divisors_upto(num, index - 1)) && (result <= index - 1);
    assigns \nothing;
*/
void check_A_implies_B(int index, int k, int num) {
    /*@ assert (result >= 0 && result <= index) && (result >= 0 && result <= index - 1) && (result >= 0 && index >= 1) && (result == 0 || result >= 1) && (result == 0 || result >= 0) && (result == 0 || result > 0) && (result <= index) && (result <= index - 1) && (result <= index - 1 + 1) && (result <= index + 1) && (result < index) && (result - index <= 0) && (result % 2 == result % 2) && (result % 2 == 0 || result % 2 == 1) && (index == result || index > result) && (index == result + 1 || index > result) && (index - result <= index) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (1 <= index) && (1 <= index - result) && (0 <= result) && (0 <= index) && (0 <= index - result) && (0 < index); */
}

/*@ requires (result >= 0 && result <= index) && (result >= 0 && result <= index - 1) && (result >= 0 && index >= 1) && (result == 0 || result >= 1) && (result == 0 || result >= 0) && (result == 0 || result > 0) && (result <= index) && (result <= index - 1) && (result <= index - 1 + 1) && (result <= index + 1) && (result < index) && (result - index <= 0) && (result % 2 == result % 2) && (result % 2 == 0 || result % 2 == 1) && (index == result || index > result) && (index == result + 1 || index > result) && (index - result <= index) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (1 <= index) && (1 <= index - result) && (0 <= result) && (0 <= index) && (0 <= index - result) && (0 < index);
    assigns \nothing;
*/
void check_B_implies_A(int index, int k, int num) {
    /*@ assert (num == \at(num,Pre)) && (0 <= result) && (1 <= index) && (result == count_divisors_upto(num, index - 1)) && (result <= index - 1); */
}
