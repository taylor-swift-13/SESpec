#include <limits.h>

/*@ logic integer fact(integer n) = n <= 1 ? 1 : n * fact(n - 1); */

/*@ requires (0 <= result <= 9) && (first >= 0) && ((first > 0) ==> (result >= 0 && result <= 9)) && ((!(first > 0)) ==> (first == 0));
    assigns \nothing;
*/
void check_A_implies_B(int first, int k) {
    /*@ assert (result == first % 10 || result >= 0); */
    /*@ assert (result == 0 || result % 10 == result); */
    /*@ assert (first == 0 || first >= 0); */
    /*@ assert (first <= 1 || first > 0); */
    /*@ assert (result == 0 || result >= 0); */
    /*@ assert (result == 0 || result < 10); */
    /*@ assert (result == 0 || \exists integer k; 0 <= k < 10 && result == k); */
    /*@ assert (result == 0 || 0 <= result < 10); */
    /*@ assert (result == 0 || (0 <= result < 10)); */
    /*@ assert (result <= 9); */
    /*@ assert (result < 10); */
    /*@ assert (result % 10 == result); */
    /*@ assert (first >= 0 ==> result >= 0); */
    /*@ assert (first >= 0 ==> result < 10); */
    /*@ assert (first >= 0 ==> 0 <= result < 10); */
    /*@ assert (first > 0 || result >= 0); */
    /*@ assert (first > 0 || result < 10); */
    /*@ assert (first > 0 || 0 <= result < 10); */
    /*@ assert (first > 0 ==> result >= 0); */
    /*@ assert (first > 0 ==> result == first % 10 || result >= 0); */
    /*@ assert (first > 0 ==> result == first % 10 || result < 10); */
    /*@ assert (first > 0 ==> result < 10); */
    /*@ assert (first > 0 ==> 0 <= result < 10); */
    /*@ assert (first > 0 ==> 0 <= first % 10 < 10); */
    /*@ assert (first == 0 || result >= 0); */
    /*@ assert (first == 0 || result < 10); */
    /*@ assert (first == 0 || result % 10 == result); */
    /*@ assert (first == 0 || first >= 1); */
    /*@ assert (first == 0 || first > 0); */
    /*@ assert (first == 0 || 0 <= result); */
    /*@ assert (first == 0 || 0 <= result < 10); */
    /*@ assert (first == 0 || 0 <= first % 10 < 10); */
    /*@ assert (first == 0 ==> result == 0 || result < 10); */
    /*@ assert (first == 0 ==> result == 0 || 0 <= result < 10); */
    /*@ assert (first == 0 ==> result < 10); */
    /*@ assert (first == 0 ==> 0 <= result < 10); */
    /*@ assert (first <= first); */
    /*@ assert (first <= 1 || result < 10); */
    /*@ assert (first < 10 || result < 10); */
    /*@ assert (first / 10 <= first); */
    /*@ assert (first % 10 == first || first % 10 < 10); */
    /*@ assert (first % 10 < 10); */
    /*@ assert (\forall integer k; 0 <= k < 10 ==> result != 10 + k); */
    /*@ assert (\exists integer k; 0 <= k <= 9 && result == k); */
    /*@ assert (\exists integer k; 0 <= k < 10 && result == k); */
    /*@ assert (0 <= result); */
    /*@ assert (0 <= first); */
    /*@ assert (0 <= first / 10); */
    /*@ assert (0 <= first % 10); */
}

/*@ requires (result == first % 10 || result >= 0) && (result == 0 || result % 10 == result) && (first == 0 || first >= 0) && (first <= 1 || first > 0) && (result == 0 || result >= 0) && (result == 0 || result < 10) && (result == 0 || \exists integer k; 0 <= k < 10 && result == k) && (result == 0 || 0 <= result < 10) && (result == 0 || (0 <= result < 10)) && (result <= 9) && (result < 10) && (result % 10 == result) && (first >= 0 ==> result >= 0) && (first >= 0 ==> result < 10) && (first >= 0 ==> 0 <= result < 10) && (first > 0 || result >= 0) && (first > 0 || result < 10) && (first > 0 || 0 <= result < 10) && (first > 0 ==> result >= 0) && (first > 0 ==> result == first % 10 || result >= 0) && (first > 0 ==> result == first % 10 || result < 10) && (first > 0 ==> result < 10) && (first > 0 ==> 0 <= result < 10) && (first > 0 ==> 0 <= first % 10 < 10) && (first == 0 || result >= 0) && (first == 0 || result < 10) && (first == 0 || result % 10 == result) && (first == 0 || first >= 1) && (first == 0 || first > 0) && (first == 0 || 0 <= result) && (first == 0 || 0 <= result < 10) && (first == 0 || 0 <= first % 10 < 10) && (first == 0 ==> result == 0 || result < 10) && (first == 0 ==> result == 0 || 0 <= result < 10) && (first == 0 ==> result < 10) && (first == 0 ==> 0 <= result < 10) && (first <= first) && (first <= 1 || result < 10) && (first < 10 || result < 10) && (first / 10 <= first) && (first % 10 == first || first % 10 < 10) && (first % 10 < 10) && (\forall integer k; 0 <= k < 10 ==> result != 10 + k) && (\exists integer k; 0 <= k <= 9 && result == k) && (\exists integer k; 0 <= k < 10 && result == k) && (0 <= result) && (0 <= first) && (0 <= first / 10) && (0 <= first % 10);
    assigns \nothing;
*/
void check_B_implies_A(int first, int k) {
    /*@ assert (0 <= result <= 9); */
    /*@ assert (first >= 0); */
    /*@ assert ((first > 0) ==> (result >= 0 && result <= 9)); */
    /*@ assert ((!(first > 0)) ==> (first == 0)); */
}
