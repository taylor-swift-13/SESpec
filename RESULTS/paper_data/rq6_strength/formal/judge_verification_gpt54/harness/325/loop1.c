#include <limits.h>

/*@ logic integer leading_digit(integer n) =
      n < 10 ? n : leading_digit(n / 10); */
/*@ logic integer fact(integer n) =
      n <= 1 ? 1 : n * fact(n - 1); */

/*@ requires (2 <= j) && (first == fact(j - 1)) && (1 <= first) && (num == \at(num,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int first, int j, int k, int num) {
    /*@ assert (j == j); */
    /*@ assert (j <= num || 0 <= first); */
    /*@ assert (j <= num + 1 || first <= 1); */
    /*@ assert (j <= num + 1 || 0 <= first); */
    /*@ assert (j <= num + 1 || 0 <= first % 10); */
    /*@ assert (first == 1 || first > 1); */
    /*@ assert (first == 1 ==> j == 2); */
    /*@ assert (first == 0 || first > 0); */
    /*@ assert (first <= num || first >= 1); */
    /*@ assert (first <= num || first > num); */
    /*@ assert (first <= num || 0 <= first); */
    /*@ assert (first <= 1 || 0 <= first); */
    /*@ assert (first % 10 == first - 10 * (first / 10)); */
    /*@ assert (first % 10 < 10); */
    /*@ assert (first % 1 == 0); */
    /*@ assert (\forall integer k; 0 <= k < j ==> first >= 1); */
    /*@ assert (\exists integer k; k >= 0 && first == k); */
    /*@ assert (2 <= j); */
    /*@ assert (1 <= j); */
    /*@ assert (1 <= first); */
    /*@ assert (0 <= j); */
    /*@ assert (0 <= first); */
    /*@ assert (0 <= first % 10); */
    /*@ assert (0 <= first % 10 || j <= num); */
    /*@ assert (0 <= first % 10 || first <= num); */
    /*@ assert (0 <= first % 10 || first <= 1); */
    /*@ assert (0 <= first % 10 || 0 <= first); */
    /*@ assert (0 < first); */
    /*@ assert (0 < first); */
    /*@ assert (0 < first); */
    /*@ assert (0 < first); */
    /*@ assert (0 < first); */
    /*@ assert (0 < first); */
    /*@ assert (0 < first); */
    /*@ assert (0 < first); */
    /*@ assert (0 < first); */
}

/*@ requires (j == j) && (j <= num || 0 <= first) && (j <= num + 1 || first <= 1) && (j <= num + 1 || 0 <= first) && (j <= num + 1 || 0 <= first % 10) && (first == 1 || first > 1) && (first == 1 ==> j == 2) && (first == 0 || first > 0) && (first <= num || first >= 1) && (first <= num || first > num) && (first <= num || 0 <= first) && (first <= 1 || 0 <= first) && (first % 10 == first - 10 * (first / 10)) && (first % 10 < 10) && (first % 1 == 0) && (\forall integer k; 0 <= k < j ==> first >= 1) && (\exists integer k; k >= 0 && first == k) && (2 <= j) && (1 <= j) && (1 <= first) && (0 <= j) && (0 <= first) && (0 <= first % 10) && (0 <= first % 10 || j <= num) && (0 <= first % 10 || first <= num) && (0 <= first % 10 || first <= 1) && (0 <= first % 10 || 0 <= first) && (0 < first) && (0 < first) && (0 < first) && (0 < first) && (0 < first) && (0 < first) && (0 < first) && (0 < first) && (0 < first);
    assigns \nothing;
*/
void check_B_implies_A(int first, int j, int k, int num) {
    /*@ assert (2 <= j); */
    /*@ assert (first == fact(j - 1)); */
    /*@ assert (1 <= first); */
    /*@ assert (num == \at(num,Pre)); */
}
