#include <limits.h>

/*@logic integer count_divisors(integer n, integer i) =
    i <= 0 ? 0 : count_divisors(n, i - 1) + ((n % i == 0) ? 1 : 0);*/

/*@ requires (1 <= index) && (index >= 1) && (0 <= div) && (div <= index - 1) && (div == count_divisors(number, index - 1)) && (number == \at(number,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int div, int index, int k, int number) {
    /*@ assert (number >= 0 ==> index >= 1) && (number >= 0 ==> index <= number + 1) && (number >= 0 ==> div <= number) && (number >= 0 ==> div <= index) && (number >= 0 ==> div <= index - 1) && (number >= 0 ==> div <= index - 1 + 1) && (number >= 0 ==> div <= index + 1) && (number >= 0 ==> 0 <= div <= index) && (number < 0 || div >= 0) && (number < 0 || div <= number) && (index > 1 ==> div >= 1) && (index > 1 ==> div >= 0) && (index == 1 ==> div == 0) && (div >= 0 && index >= 1) && (div > 0 ==> index >= 1) && (div > 0 ==> index > 1) && (div == 0 || div >= 1) && (div == 0 || div > 0) && (div == 0 ==> index == 1) && (div == 0 ==> index <= 1) && (div <= number || 0 <= index) && (div <= index) && (div <= index - 1) && (div <= index - 1 + 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (1 <= index) && (1 <= index || div == 0) && (1 <= index - div) && (0 <= index) && (0 <= index || index <= number + 1) && (0 <= index - div) && (0 <= div) && (0 < index); */
}

/*@ requires (number >= 0 ==> index >= 1) && (number >= 0 ==> index <= number + 1) && (number >= 0 ==> div <= number) && (number >= 0 ==> div <= index) && (number >= 0 ==> div <= index - 1) && (number >= 0 ==> div <= index - 1 + 1) && (number >= 0 ==> div <= index + 1) && (number >= 0 ==> 0 <= div <= index) && (number < 0 || div >= 0) && (number < 0 || div <= number) && (index > 1 ==> div >= 1) && (index > 1 ==> div >= 0) && (index == 1 ==> div == 0) && (div >= 0 && index >= 1) && (div > 0 ==> index >= 1) && (div > 0 ==> index > 1) && (div == 0 || div >= 1) && (div == 0 || div > 0) && (div == 0 ==> index == 1) && (div == 0 ==> index <= 1) && (div <= number || 0 <= index) && (div <= index) && (div <= index - 1) && (div <= index - 1 + 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (1 <= index) && (1 <= index || div == 0) && (1 <= index - div) && (0 <= index) && (0 <= index || index <= number + 1) && (0 <= index - div) && (0 <= div) && (0 < index);
    assigns \nothing;
*/
void check_B_implies_A(int div, int index, int k, int number) {
    /*@ assert (1 <= index) && (index >= 1) && (0 <= div) && (div <= index - 1) && (div == count_divisors(number, index - 1)) && (number == \at(number,Pre)); */
}
