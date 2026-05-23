#include <limits.h>

/*@logic integer count_div(integer n, integer k) =
    k <= 0 ? 0 : count_div(n, k - 1) + ((n % k) == 0 ? 1 : 0);*/

/*@ requires (1 <= c <= \at(number,Pre) + 1) && (0 <= div <= c - 1) && (div == count_div(\at(number,Pre), c - 1)) && (number == \at(number,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int c, int div, int k, int number) {
    /*@ assert (div > 0 ==> c > 1) && (div == 0 || div >= 1) && (div == 0 || div >= 0) && (div == 0 || div > 0) && (div == 0 ==> c == 1) && (div <= c) && (div <= c - 1) && (div <= c - 1 || div == c) && (div <= c - 1 || c == 1) && (div <= c + 1) && (c == div + 1 || c > div) && (c == 1 + div || c > div) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (1 <= c) && (1 <= c - div) && (0 <= div) && (0 <= c) && (0 <= c - div); */
}

/*@ requires (div > 0 ==> c > 1) && (div == 0 || div >= 1) && (div == 0 || div >= 0) && (div == 0 || div > 0) && (div == 0 ==> c == 1) && (div <= c) && (div <= c - 1) && (div <= c - 1 || div == c) && (div <= c - 1 || c == 1) && (div <= c + 1) && (c == div + 1 || c > div) && (c == 1 + div || c > div) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (1 <= c) && (1 <= c - div) && (0 <= div) && (0 <= c) && (0 <= c - div);
    assigns \nothing;
*/
void check_B_implies_A(int c, int div, int k, int number) {
    /*@ assert (1 <= c <= \at(number,Pre) + 1) && (0 <= div <= c - 1) && (div == count_div(\at(number,Pre), c - 1)) && (number == \at(number,Pre)); */
}
