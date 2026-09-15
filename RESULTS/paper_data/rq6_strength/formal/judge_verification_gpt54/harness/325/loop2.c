#include <limits.h>

/*@ logic integer leading_digit(integer n) =
      n < 10 ? n : leading_digit(n / 10); */
/*@ logic integer fact(integer n) =
      n <= 1 ? 1 : n * fact(n - 1); */

/*@ requires (0 <= first) && (0 <= result <= 9) && (result == 0 || result > 0);
    assigns \nothing;
*/
void check_A_implies_B(int first, int k, int num) {
    /*@ assert (first <= 1 || 0 <= first); */
    /*@ assert (result >= 0 && result <= 9); */
    /*@ assert (result == 0 || result >= 1); */
    /*@ assert (result == 0 || result >= 0); */
    /*@ assert (result == 0 || result > 0); */
    /*@ assert (result == 0 || result < 10); */
    /*@ assert (result == 0 || result % 10 == result); */
    /*@ assert (result == 0 || (result >= 0 && result < 10)); */
    /*@ assert (result == 0 || (\exists integer k; 0 <= k < 10 && result == k)); */
    /*@ assert (result == 0 || (0 <= result && result < 10)); */
    /*@ assert (result <= 9); */
    /*@ assert (result < 10); */
    /*@ assert (result < 10 && result >= 0); */
    /*@ assert (result % 10 == result); */
    /*@ assert (first >= 0 ==> result == 0 || result > 0); */
    /*@ assert (first >= 0 ==> result == 0 || (\exists integer k; 0 <= k < 10 && result == k)); */
    /*@ assert (first >= 0 ==> result <= 9); */
    /*@ assert (first >= 0 ==> result < 10); */
    /*@ assert (first >= 0 ==> 0 <= result <= 9); */
    /*@ assert (first >= 0 ==> 0 <= result < 10); */
    /*@ assert (first > 0 ==> result >= 0); */
    /*@ assert (first > 0 ==> result >= 0 && result < 10); */
    /*@ assert (first > 0 ==> result == first % 10 || result < 10); */
    /*@ assert (first > 0 ==> result < 10); */
    /*@ assert (first > 0 ==> 0 <= result); */
    /*@ assert (first > 0 ==> 0 <= result <= 9); */
    /*@ assert (first > 0 ==> 0 <= result < 10); */
    /*@ assert (first == 0 || result >= 0); */
    /*@ assert (first == 0 || result < 10); */
    /*@ assert (first == 0 || first > 0); */
    /*@ assert (first == 0 || 0 <= result <= 9); */
    /*@ assert (first == 0 ==> result == 0 || result < 10); */
    /*@ assert (first == 0 ==> result < 10); */
    /*@ assert (first <= num || first > num); */
    /*@ assert (first < 10 || first >= 10); */
    /*@ assert (first % 10 == first - 10 * (first / 10)); */
    /*@ assert (first % 10 < 10); */
    /*@ assert (0 <= result); */
    /*@ assert (0 <= first); */
    /*@ assert (0 <= first % 10); */
}

/*@ requires (first <= 1 || 0 <= first) && (result >= 0 && result <= 9) && (result == 0 || result >= 1) && (result == 0 || result >= 0) && (result == 0 || result > 0) && (result == 0 || result < 10) && (result == 0 || result % 10 == result) && (result == 0 || (result >= 0 && result < 10)) && (result == 0 || (\exists integer k; 0 <= k < 10 && result == k)) && (result == 0 || (0 <= result && result < 10)) && (result <= 9) && (result < 10) && (result < 10 && result >= 0) && (result % 10 == result) && (first >= 0 ==> result == 0 || result > 0) && (first >= 0 ==> result == 0 || (\exists integer k; 0 <= k < 10 && result == k)) && (first >= 0 ==> result <= 9) && (first >= 0 ==> result < 10) && (first >= 0 ==> 0 <= result <= 9) && (first >= 0 ==> 0 <= result < 10) && (first > 0 ==> result >= 0) && (first > 0 ==> result >= 0 && result < 10) && (first > 0 ==> result == first % 10 || result < 10) && (first > 0 ==> result < 10) && (first > 0 ==> 0 <= result) && (first > 0 ==> 0 <= result <= 9) && (first > 0 ==> 0 <= result < 10) && (first == 0 || result >= 0) && (first == 0 || result < 10) && (first == 0 || first > 0) && (first == 0 || 0 <= result <= 9) && (first == 0 ==> result == 0 || result < 10) && (first == 0 ==> result < 10) && (first <= num || first > num) && (first < 10 || first >= 10) && (first % 10 == first - 10 * (first / 10)) && (first % 10 < 10) && (0 <= result) && (0 <= first) && (0 <= first % 10);
    assigns \nothing;
*/
void check_B_implies_A(int first, int k, int num) {
    /*@ assert (0 <= first); */
    /*@ assert (0 <= result <= 9); */
    /*@ assert (result == 0 || result > 0); */
}
