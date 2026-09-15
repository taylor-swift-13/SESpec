#include <limits.h>

/*@ logic integer count_divisors(integer n, integer i) =
    i <= 0 ? 0 : count_divisors(n, i - 1) + ((n % i == 0) ? 1 : 0); */

/*@ requires (1 <= index) && (index >= 1) && (0 <= div) && (div <= index - 1) && (div == count_divisors(number, index - 1)) && (number == \at(number,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int div, int index, int k, int number) {
    /*@ assert (number >= 0 ==> index >= 1); */
    /*@ assert (number >= 0 ==> index <= number + 1); */
    /*@ assert (number >= 0 ==> div <= number); */
    /*@ assert (number >= 0 ==> div <= index); */
    /*@ assert (number >= 0 ==> div <= index - 1); */
    /*@ assert (number >= 0 ==> div <= index - 1 + 1); */
    /*@ assert (number >= 0 ==> div <= index + 1); */
    /*@ assert (number >= 0 ==> 0 <= div <= index); */
    /*@ assert (number < 0 || div >= 0); */
    /*@ assert (number < 0 || div <= number); */
    /*@ assert (index > 1 ==> div >= 1); */
    /*@ assert (index > 1 ==> div >= 0); */
    /*@ assert (index == 1 ==> div == 0); */
    /*@ assert (div >= 0 && index >= 1); */
    /*@ assert (div > 0 ==> index >= 1); */
    /*@ assert (div > 0 ==> index > 1); */
    /*@ assert (div == 0 || div >= 1); */
    /*@ assert (div == 0 || div > 0); */
    /*@ assert (div == 0 ==> index == 1); */
    /*@ assert (div == 0 ==> index <= 1); */
    /*@ assert (div <= number || 0 <= index); */
    /*@ assert (div <= index); */
    /*@ assert (div <= index - 1); */
    /*@ assert (div <= index - 1 + 1); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (number % k == 0 || number % k != 0)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (number % k == 0 ==> div >= 1)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (number % k == 0 ==> div >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (number % k == 0 ==> div <= index)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (number % k != 0 || div >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (number % k != 0 ==> div >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < index && number % k == 0 ==> div >= 1); */
    /*@ assert (\forall integer k; 1 <= k < index && number % k == 0 ==> div >= 0); */
    /*@ assert (\forall integer k; 1 <= k < index && number % k != 0 ==> div >= 0); */
    /*@ assert (\exists integer k; 1 <= k <= index && number % k == 0 ==> div >= 1); */
    /*@ assert (\exists integer k; 1 <= k < index && number % k == 0 ==> div >= 1); */
    /*@ assert (\exists integer k; 1 <= k < index && number % k == 0 ==> div >= 0); */
    /*@ assert (1 <= index); */
    /*@ assert (1 <= index || div == 0); */
    /*@ assert (1 <= index - div); */
    /*@ assert (0 <= index); */
    /*@ assert (0 <= index || index <= number + 1); */
    /*@ assert (0 <= index - div); */
    /*@ assert (0 <= div); */
    /*@ assert (0 < index); */
}

/*@ requires (number >= 0 ==> index >= 1) && (number >= 0 ==> index <= number + 1) && (number >= 0 ==> div <= number) && (number >= 0 ==> div <= index) && (number >= 0 ==> div <= index - 1) && (number >= 0 ==> div <= index - 1 + 1) && (number >= 0 ==> div <= index + 1) && (number >= 0 ==> 0 <= div <= index) && (number < 0 || div >= 0) && (number < 0 || div <= number) && (index > 1 ==> div >= 1) && (index > 1 ==> div >= 0) && (index == 1 ==> div == 0) && (div >= 0 && index >= 1) && (div > 0 ==> index >= 1) && (div > 0 ==> index > 1) && (div == 0 || div >= 1) && (div == 0 || div > 0) && (div == 0 ==> index == 1) && (div == 0 ==> index <= 1) && (div <= number || 0 <= index) && (div <= index) && (div <= index - 1) && (div <= index - 1 + 1) && (\forall integer k; 1 <= k < index ==> (number % k == 0 || number % k != 0)) && (\forall integer k; 1 <= k < index ==> (number % k == 0 ==> div >= 1)) && (\forall integer k; 1 <= k < index ==> (number % k == 0 ==> div >= 0)) && (\forall integer k; 1 <= k < index ==> (number % k == 0 ==> div <= index)) && (\forall integer k; 1 <= k < index ==> (number % k != 0 || div >= 0)) && (\forall integer k; 1 <= k < index ==> (number % k != 0 ==> div >= 0)) && (\forall integer k; 1 <= k < index && number % k == 0 ==> div >= 1) && (\forall integer k; 1 <= k < index && number % k == 0 ==> div >= 0) && (\forall integer k; 1 <= k < index && number % k != 0 ==> div >= 0) && (\exists integer k; 1 <= k <= index && number % k == 0 ==> div >= 1) && (\exists integer k; 1 <= k < index && number % k == 0 ==> div >= 1) && (\exists integer k; 1 <= k < index && number % k == 0 ==> div >= 0) && (1 <= index) && (1 <= index || div == 0) && (1 <= index - div) && (0 <= index) && (0 <= index || index <= number + 1) && (0 <= index - div) && (0 <= div) && (0 < index);
    assigns \nothing;
*/
void check_B_implies_A(int div, int index, int k, int number) {
    /*@ assert (1 <= index); */
    /*@ assert (index >= 1); */
    /*@ assert (0 <= div); */
    /*@ assert (div <= index - 1); */
    /*@ assert (div == count_divisors(number, index - 1)); */
    /*@ assert (number == \at(number,Pre)); */
}
