#include <limits.h>

/*@ logic integer count_divs_checked(integer n, integer c) =
      c <= 1 ? 0 :
      count_divs_checked(n, c - 1) + (c <= n / c && n % c == 0 ? 1 : 0); */

/*@ requires (2 <= c) && (0 <= result) && (result <= c - 2);
    assigns \nothing;
*/
void check_A_implies_B(int c, int k, int num) {
    /*@ assert (c >= 2 ==> result < c + 1); */
    /*@ assert (result >= 0 && c >= 2); */
    /*@ assert (result == 0 || result >= 1); */
    /*@ assert (result == 0 || result > 0); */
    /*@ assert (result <= c); */
    /*@ assert (result <= c - 2); */
    /*@ assert (result <= c - 2 || result == c - 1); */
    /*@ assert (result <= c - 2 || result == 0); */
    /*@ assert (result <= c - 2 + 1); */
    /*@ assert (result <= c - 1); */
    /*@ assert (result <= c - 1 || result == c); */
    /*@ assert (result <= c - 1 || result == 0); */
    /*@ assert (result < c); */
    /*@ assert (result < c + 1); */
    /*@ assert (c >= 2 ==> result >= 0); */
    /*@ assert (c >= 2 ==> result <= c); */
    /*@ assert (c >= 2 ==> result <= c - 1); */
    /*@ assert (c >= 2 ==> result < c); */
    /*@ assert (c >= 2 ==> 0 <= result); */
    /*@ assert (c >= 2 && result >= 0); */
    /*@ assert (\forall integer k; 2 <= k < c ==> num % k == 0 ==> result >= 1); */
    /*@ assert (\forall integer k; 2 <= k < c ==> num % k == 0 ==> result >= 0); */
    /*@ assert (\forall integer k; 2 <= k < c ==> num % k == 0 ==> result <= c); */
    /*@ assert (\forall integer k; 2 <= k < c ==> num % k == 0 ==> result <= c - 1); */
    /*@ assert (\forall integer k; 2 <= k < c ==> num % k != 0 || result >= 1); */
    /*@ assert (\forall integer k; 2 <= k < c ==> num % k != 0 || result >= 0); */
    /*@ assert (\forall integer k; 2 <= k < c ==> num % k != 0 ==> result >= 0); */
    /*@ assert (\forall integer k; 2 <= k < c ==> num % k != 0 ==> result == 0 || result > 0); */
    /*@ assert (\forall integer k; 2 <= k < c ==> (num % k == 0 ==> result >= 1)); */
    /*@ assert (\forall integer k; 2 <= k < c ==> (num % k == 0 ==> result >= 0)); */
    /*@ assert (\forall integer k; 2 <= k < c ==> (num % k == 0 ==> result > 0)); */
    /*@ assert (\forall integer k; 2 <= k < c ==> (num % k == 0 ==> result <= c)); */
    /*@ assert (\forall integer k; 2 <= k < c ==> (num % k == 0 ==> result <= c - 2)); */
    /*@ assert (\forall integer k; 2 <= k < c ==> (num % k == 0 ==> result <= c - 1)); */
    /*@ assert (\forall integer k; 2 <= k < c ==> (num % k != 0 || result >= 1)); */
    /*@ assert (\forall integer k; 2 <= k < c ==> (num % k != 0 || result >= 0)); */
    /*@ assert (\forall integer k; 2 <= k < c ==> (num % k != 0 || result > 0)); */
    /*@ assert (\forall integer k; 2 <= k < c ==> (num % k != 0 ==> result >= 0)); */
    /*@ assert (\forall integer k; 2 <= k < c && k <= num / k ==> num % k == 0 ==> result >= 0); */
    /*@ assert (\forall integer k; 2 <= k < c && k <= num / k ==> num % k != 0 || result >= 0); */
    /*@ assert (\forall integer k; 2 <= k < c && k <= num / k ==> (num % k == 0 ==> result >= 1)); */
    /*@ assert (\forall integer k; 2 <= k < c && k <= num / k ==> (num % k == 0 ==> result >= 0)); */
    /*@ assert (\forall integer k; 2 <= k < c && k <= num / k ==> (num % k == 0 ==> result > 0)); */
    /*@ assert (\forall integer k; 2 <= k < c && k <= num / k ==> (num % k == 0 ==> result <= c - 1)); */
    /*@ assert (\forall integer k; 2 <= k < c && k <= num / k ==> (num % k != 0) || (result > 0)); */
    /*@ assert (\forall integer k; 2 <= k < c && k <= num / k ==> (num % k != 0 || result >= 1)); */
    /*@ assert (\forall integer k; 2 <= k < c && k <= num / k ==> (num % k != 0 || result >= 0)); */
    /*@ assert (\forall integer k; 2 <= k < c && k <= num / k ==> (num % k != 0 || result > 0)); */
    /*@ assert (\exists integer k; 2 <= k < c && num % k == 0 ==> result >= 1); */
    /*@ assert (\exists integer k; 2 <= k < c && num % k == 0 ==> result >= 0); */
    /*@ assert (\exists integer k; 2 <= k < c && num % k == 0 ==> result > 0); */
    /*@ assert (2 <= c); */
    /*@ assert (2 <= c ==> result >= 0); */
    /*@ assert (2 <= c - result); */
    /*@ assert (1 <= c); */
    /*@ assert (1 <= c - result); */
    /*@ assert (0 <= result); */
    /*@ assert (0 <= result && result <= c); */
    /*@ assert (0 <= result && 2 <= c); */
    /*@ assert (0 <= result && 0 <= c); */
    /*@ assert (0 <= c - result); */
    /*@ assert (0 < c); */
}

/*@ requires (c >= 2 ==> result < c + 1) && (result >= 0 && c >= 2) && (result == 0 || result >= 1) && (result == 0 || result > 0) && (result <= c) && (result <= c - 2) && (result <= c - 2 || result == c - 1) && (result <= c - 2 || result == 0) && (result <= c - 2 + 1) && (result <= c - 1) && (result <= c - 1 || result == c) && (result <= c - 1 || result == 0) && (result < c) && (result < c + 1) && (c >= 2 ==> result >= 0) && (c >= 2 ==> result <= c) && (c >= 2 ==> result <= c - 1) && (c >= 2 ==> result < c) && (c >= 2 ==> 0 <= result) && (c >= 2 && result >= 0) && (\forall integer k; 2 <= k < c ==> num % k == 0 ==> result >= 1) && (\forall integer k; 2 <= k < c ==> num % k == 0 ==> result >= 0) && (\forall integer k; 2 <= k < c ==> num % k == 0 ==> result <= c) && (\forall integer k; 2 <= k < c ==> num % k == 0 ==> result <= c - 1) && (\forall integer k; 2 <= k < c ==> num % k != 0 || result >= 1) && (\forall integer k; 2 <= k < c ==> num % k != 0 || result >= 0) && (\forall integer k; 2 <= k < c ==> num % k != 0 ==> result >= 0) && (\forall integer k; 2 <= k < c ==> num % k != 0 ==> result == 0 || result > 0) && (\forall integer k; 2 <= k < c ==> (num % k == 0 ==> result >= 1)) && (\forall integer k; 2 <= k < c ==> (num % k == 0 ==> result >= 0)) && (\forall integer k; 2 <= k < c ==> (num % k == 0 ==> result > 0)) && (\forall integer k; 2 <= k < c ==> (num % k == 0 ==> result <= c)) && (\forall integer k; 2 <= k < c ==> (num % k == 0 ==> result <= c - 2)) && (\forall integer k; 2 <= k < c ==> (num % k == 0 ==> result <= c - 1)) && (\forall integer k; 2 <= k < c ==> (num % k != 0 || result >= 1)) && (\forall integer k; 2 <= k < c ==> (num % k != 0 || result >= 0)) && (\forall integer k; 2 <= k < c ==> (num % k != 0 || result > 0)) && (\forall integer k; 2 <= k < c ==> (num % k != 0 ==> result >= 0)) && (\forall integer k; 2 <= k < c && k <= num / k ==> num % k == 0 ==> result >= 0) && (\forall integer k; 2 <= k < c && k <= num / k ==> num % k != 0 || result >= 0) && (\forall integer k; 2 <= k < c && k <= num / k ==> (num % k == 0 ==> result >= 1)) && (\forall integer k; 2 <= k < c && k <= num / k ==> (num % k == 0 ==> result >= 0)) && (\forall integer k; 2 <= k < c && k <= num / k ==> (num % k == 0 ==> result > 0)) && (\forall integer k; 2 <= k < c && k <= num / k ==> (num % k == 0 ==> result <= c - 1)) && (\forall integer k; 2 <= k < c && k <= num / k ==> (num % k != 0) || (result > 0)) && (\forall integer k; 2 <= k < c && k <= num / k ==> (num % k != 0 || result >= 1)) && (\forall integer k; 2 <= k < c && k <= num / k ==> (num % k != 0 || result >= 0)) && (\forall integer k; 2 <= k < c && k <= num / k ==> (num % k != 0 || result > 0)) && (\exists integer k; 2 <= k < c && num % k == 0 ==> result >= 1) && (\exists integer k; 2 <= k < c && num % k == 0 ==> result >= 0) && (\exists integer k; 2 <= k < c && num % k == 0 ==> result > 0) && (2 <= c) && (2 <= c ==> result >= 0) && (2 <= c - result) && (1 <= c) && (1 <= c - result) && (0 <= result) && (0 <= result && result <= c) && (0 <= result && 2 <= c) && (0 <= result && 0 <= c) && (0 <= c - result) && (0 < c);
    assigns \nothing;
*/
void check_B_implies_A(int c, int k, int num) {
    /*@ assert (2 <= c); */
    /*@ assert (0 <= result); */
    /*@ assert (result <= c - 2); */
}
