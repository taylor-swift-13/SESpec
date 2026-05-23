#include <limits.h>

/*@logic integer count_divs_checked(integer n, integer c) =
      c <= 1 ? 0 :
      count_divs_checked(n, c - 1) + (c <= n / c && n % c == 0 ? 1 : 0);*/

/*@ requires (2 <= c) && (0 <= result) && (result <= c - 2);
    assigns \nothing;
*/
void check_A_implies_B(int c, int k) {
    /*@ assert (c >= 2 ==> result < c + 1) && (result >= 0 && c >= 2) && (result == 0 || result >= 1) && (result == 0 || result > 0) && (result <= c) && (result <= c - 2) && (result <= c - 2 || result == c - 1) && (result <= c - 2 || result == 0) && (result <= c - 2 + 1) && (result <= c - 1) && (result <= c - 1 || result == c) && (result <= c - 1 || result == 0) && (result < c) && (result < c + 1) && (c >= 2 ==> result >= 0) && (c >= 2 ==> result <= c) && (c >= 2 ==> result <= c - 1) && (c >= 2 ==> result < c) && (c >= 2 ==> 0 <= result) && (c >= 2 && result >= 0) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (2 <= c) && (2 <= c ==> result >= 0) && (2 <= c - result) && (1 <= c) && (1 <= c - result) && (0 <= result) && (0 <= result && result <= c) && (0 <= result && 2 <= c) && (0 <= result && 0 <= c) && (0 <= c - result) && (0 < c); */
}

/*@ requires (c >= 2 ==> result < c + 1) && (result >= 0 && c >= 2) && (result == 0 || result >= 1) && (result == 0 || result > 0) && (result <= c) && (result <= c - 2) && (result <= c - 2 || result == c - 1) && (result <= c - 2 || result == 0) && (result <= c - 2 + 1) && (result <= c - 1) && (result <= c - 1 || result == c) && (result <= c - 1 || result == 0) && (result < c) && (result < c + 1) && (c >= 2 ==> result >= 0) && (c >= 2 ==> result <= c) && (c >= 2 ==> result <= c - 1) && (c >= 2 ==> result < c) && (c >= 2 ==> 0 <= result) && (c >= 2 && result >= 0) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (2 <= c) && (2 <= c ==> result >= 0) && (2 <= c - result) && (1 <= c) && (1 <= c - result) && (0 <= result) && (0 <= result && result <= c) && (0 <= result && 2 <= c) && (0 <= result && 0 <= c) && (0 <= c - result) && (0 < c);
    assigns \nothing;
*/
void check_B_implies_A(int c, int k) {
    /*@ assert (2 <= c) && (0 <= result) && (result <= c - 2); */
}
