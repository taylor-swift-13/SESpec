#include <limits.h>

/*@ logic integer count_div(integer n, integer k) =
    k <= 0 ? 0 : count_div(n, k - 1) + ((n % k) == 0 ? 1 : 0); */

/*@ requires (1 <= c <= \at(number,Pre) + 1) && (0 <= div <= c - 1) && (div == count_div(\at(number,Pre), c - 1)) && (number == \at(number,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int c, int div, int k, int number) {
    /*@ assert (div > 0 ==> c > 1); */
    /*@ assert (div == 0 || div >= 1); */
    /*@ assert (div == 0 || div >= 0); */
    /*@ assert (div == 0 || div > 0); */
    /*@ assert (div == 0 ==> c == 1); */
    /*@ assert (div <= c); */
    /*@ assert (div <= c - 1); */
    /*@ assert (div <= c - 1 || div == c); */
    /*@ assert (div <= c - 1 || c == 1); */
    /*@ assert (div <= c + 1); */
    /*@ assert (c == div + 1 || c > div); */
    /*@ assert (c == 1 + div || c > div); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (number % k == 0 || number % k != 0)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (number % k == 0 ==> div >= 1)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (number % k == 0 ==> div >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (number % k == 0 ==> div <= c)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (number % k != 0 ==> div >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (number % k != 0 ==> div <= c)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (number % k != 0 ==> div <= c - 1)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> ((number % k == 0) ==> div >= 1)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> ((number % k != 0) ==> div >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < c && number % k == 0 ==> div >= 1); */
    /*@ assert (\exists integer k; 1 <= k <= c ==> (number % k == 0)); */
    /*@ assert (\exists integer k; 1 <= k <= c && number % k == 0); */
    /*@ assert (\exists integer k; 1 <= k <= c && number % k == 0 ==> div >= 1); */
    /*@ assert (\exists integer k; 1 <= k <= c && number % k == 0 ==> div >= 0); */
    /*@ assert (\exists integer k; 1 <= k <= c && number % k == 0 ==> div > 0); */
    /*@ assert (\exists integer k; 1 <= k < c && number % k == 0 ==> div >= 1); */
    /*@ assert (\exists integer k; 1 <= k < c && number % k == 0 ==> div >= 0); */
    /*@ assert (\exists integer k; 1 <= k < c && number % k == 0 ==> div > 0); */
    /*@ assert (1 <= c); */
    /*@ assert (1 <= c - div); */
    /*@ assert (0 <= div); */
    /*@ assert (0 <= c); */
    /*@ assert (0 <= c - div); */
}

/*@ requires (div > 0 ==> c > 1) && (div == 0 || div >= 1) && (div == 0 || div >= 0) && (div == 0 || div > 0) && (div == 0 ==> c == 1) && (div <= c) && (div <= c - 1) && (div <= c - 1 || div == c) && (div <= c - 1 || c == 1) && (div <= c + 1) && (c == div + 1 || c > div) && (c == 1 + div || c > div) && (\forall integer k; 1 <= k < c ==> (number % k == 0 || number % k != 0)) && (\forall integer k; 1 <= k < c ==> (number % k == 0 ==> div >= 1)) && (\forall integer k; 1 <= k < c ==> (number % k == 0 ==> div >= 0)) && (\forall integer k; 1 <= k < c ==> (number % k == 0 ==> div <= c)) && (\forall integer k; 1 <= k < c ==> (number % k != 0 ==> div >= 0)) && (\forall integer k; 1 <= k < c ==> (number % k != 0 ==> div <= c)) && (\forall integer k; 1 <= k < c ==> (number % k != 0 ==> div <= c - 1)) && (\forall integer k; 1 <= k < c ==> ((number % k == 0) ==> div >= 1)) && (\forall integer k; 1 <= k < c ==> ((number % k != 0) ==> div >= 0)) && (\forall integer k; 1 <= k < c && number % k == 0 ==> div >= 1) && (\exists integer k; 1 <= k <= c ==> (number % k == 0)) && (\exists integer k; 1 <= k <= c && number % k == 0) && (\exists integer k; 1 <= k <= c && number % k == 0 ==> div >= 1) && (\exists integer k; 1 <= k <= c && number % k == 0 ==> div >= 0) && (\exists integer k; 1 <= k <= c && number % k == 0 ==> div > 0) && (\exists integer k; 1 <= k < c && number % k == 0 ==> div >= 1) && (\exists integer k; 1 <= k < c && number % k == 0 ==> div >= 0) && (\exists integer k; 1 <= k < c && number % k == 0 ==> div > 0) && (1 <= c) && (1 <= c - div) && (0 <= div) && (0 <= c) && (0 <= c - div);
    assigns \nothing;
*/
void check_B_implies_A(int c, int div, int k, int number) {
    /*@ assert (1 <= c <= \at(number,Pre) + 1); */
    /*@ assert (0 <= div <= c - 1); */
    /*@ assert (div == count_div(\at(number,Pre), c - 1)); */
    /*@ assert (number == \at(number,Pre)); */
}
