#include <limits.h>

/*@ logic integer fact(integer n) = n <= 1 ? 1 : n * fact(n - 1); */

/*@ requires (2 <= c) && (first == fact(c - 1)) && (first >= 1) && (number == \at(number,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int c, int first, int k, int number) {
    /*@ assert (number >= 2 ==> first >= 1); */
    /*@ assert (number >= 2 ==> c <= number + 1); */
    /*@ assert (number >= 0 || first == 1); */
    /*@ assert (number >= 0 || c == 2); */
    /*@ assert (number >= 0 ==> first >= 1); */
    /*@ assert (number >= 0 ==> first >= 0); */
    /*@ assert (number >= 0 ==> first > 0); */
    /*@ assert (number >= 0 ==> first == 1 || first > 1); */
    /*@ assert (number < 2 ==> first == 1); */
    /*@ assert (number < 0 || first >= 0); */
    /*@ assert (number < 0 ==> first == 1); */
    /*@ assert (first >= 0 ==> first / 10 <= first); */
    /*@ assert (first > 0 ==> first / 10 <= first); */
    /*@ assert (first > 0 ==> first % 10 < 10); */
    /*@ assert (first > 0 ==> c >= 2); */
    /*@ assert (first > 0 ==> 0 <= first % 10 < 10); */
    /*@ assert (first == 1 || first >= 2); */
    /*@ assert (first == 1 || first >= 1); */
    /*@ assert (first == 1 || first > 1); */
    /*@ assert (first == 1 || first > 0); */
    /*@ assert (first == 1 || c >= 2); */
    /*@ assert (first == 1 ==> first > 0); */
    /*@ assert (first == 1 ==> c == 2); */
    /*@ assert (first == 0 || first >= 1); */
    /*@ assert (first == 0 || first >= 0); */
    /*@ assert (first == 0 || first > 0); */
    /*@ assert (first == 0 || first % 10 < 10); */
    /*@ assert (first == 0 || 0 <= first); */
    /*@ assert (first <= first); */
    /*@ assert (first <= 1 || first >= 1); */
    /*@ assert (first <= 1 || first > 0); */
    /*@ assert (first / 10 <= first); */
    /*@ assert (first % 10 == first || first % 10 < 10); */
    /*@ assert (first % 10 < 10); */
    /*@ assert (c >= 2 ==> first >= 1); */
    /*@ assert (c >= 2 ==> first > 0); */
    /*@ assert (\forall integer k; 0 <= k < c ==> first >= k); */
    /*@ assert (\forall integer k; 0 <= k < c ==> first >= 1); */
    /*@ assert (2 <= c); */
    /*@ assert (1 <= first); */
    /*@ assert (1 <= first || first == 0); */
    /*@ assert (1 <= c); */
    /*@ assert (0 <= number || first == 1); */
    /*@ assert (0 <= number || 0 <= first); */
    /*@ assert (0 <= first); */
    /*@ assert (0 <= first || c <= number + 1); */
    /*@ assert (0 <= first / 10); */
    /*@ assert (0 <= first % 10); */
    /*@ assert (0 <= c); */
    /*@ assert (0 < first); */
}

/*@ requires (number >= 2 ==> first >= 1) && (number >= 2 ==> c <= number + 1) && (number >= 0 || first == 1) && (number >= 0 || c == 2) && (number >= 0 ==> first >= 1) && (number >= 0 ==> first >= 0) && (number >= 0 ==> first > 0) && (number >= 0 ==> first == 1 || first > 1) && (number < 2 ==> first == 1) && (number < 0 || first >= 0) && (number < 0 ==> first == 1) && (first >= 0 ==> first / 10 <= first) && (first > 0 ==> first / 10 <= first) && (first > 0 ==> first % 10 < 10) && (first > 0 ==> c >= 2) && (first > 0 ==> 0 <= first % 10 < 10) && (first == 1 || first >= 2) && (first == 1 || first >= 1) && (first == 1 || first > 1) && (first == 1 || first > 0) && (first == 1 || c >= 2) && (first == 1 ==> first > 0) && (first == 1 ==> c == 2) && (first == 0 || first >= 1) && (first == 0 || first >= 0) && (first == 0 || first > 0) && (first == 0 || first % 10 < 10) && (first == 0 || 0 <= first) && (first <= first) && (first <= 1 || first >= 1) && (first <= 1 || first > 0) && (first / 10 <= first) && (first % 10 == first || first % 10 < 10) && (first % 10 < 10) && (c >= 2 ==> first >= 1) && (c >= 2 ==> first > 0) && (\forall integer k; 0 <= k < c ==> first >= k) && (\forall integer k; 0 <= k < c ==> first >= 1) && (2 <= c) && (1 <= first) && (1 <= first || first == 0) && (1 <= c) && (0 <= number || first == 1) && (0 <= number || 0 <= first) && (0 <= first) && (0 <= first || c <= number + 1) && (0 <= first / 10) && (0 <= first % 10) && (0 <= c) && (0 < first);
    assigns \nothing;
*/
void check_B_implies_A(int c, int first, int k, int number) {
    /*@ assert (2 <= c); */
    /*@ assert (first == fact(c - 1)); */
    /*@ assert (first >= 1); */
    /*@ assert (number == \at(number,Pre)); */
}
