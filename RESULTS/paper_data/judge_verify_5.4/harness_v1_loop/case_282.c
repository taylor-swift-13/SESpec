#include <limits.h>

/*@logic integer divcount(integer n, integer low, integer high) =
    low >= high ? 0 : ((low != 0 && n % low == 0) ? 1 : 0) + divcount(n, low + 1, high);*/

/*@ requires (1 <= c) && (c <= num + 1) && (num == \at(num,Pre)) && (0 <= result) && (result <= c);
    assigns \nothing;
*/
void check_A_implies_B(int c, int k, int num) {
    /*@ assert (result >= 0 && result <= c) && (result >= 0 && c >= 1) && (result == 0 || result >= 1) && (result == 0 || result > 0) && (result == 0 || result == 1 || result > 1) && (result == 0 || result <= c) && (result <= num || result <= c - 1 + 1) && (result <= num || result <= c + 1) && (result <= num || 0 <= c) && (result <= c) && (result <= c - 1) && (result <= c - 1 + 1) && (result <= c + 1) && (result <= c && result >= 0) && (result <= c && c >= 1) && (result <= c && 0 <= result) && (result <= c && 0 <= c) && (result < c - 1 + 1) && (result < c + 1) && (result - c <= 0) && (result % 2 == result % 2) && (result % 2 == c % 2 || result % 2 != c % 2) && (result % 2 == 0 || result % 2 == 1) && (c >= 1 ==> result >= 0) && (c >= 1 ==> result <= c) && (c >= 1 && result >= 0) && (c <= num + 1 || result <= c - 1 + 1) && (c <= num + 1 || result <= c + 1) && (c - result <= num || result <= c + 1) && (c - result <= num || 0 <= c) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (1 <= c) && (1 <= c || result == 0) && (1 <= c - result) && (0 <= result) && (0 <= result && result <= c) && (0 <= result && 0 <= c) && (0 <= c) && (0 <= c || result <= c + 1) && (0 <= c || c <= num + 1) && (0 <= c - result) && (0 < c) && ((result % 2 == 0) || (result % 2 == 1)); */
}

/*@ requires (result >= 0 && result <= c) && (result >= 0 && c >= 1) && (result == 0 || result >= 1) && (result == 0 || result > 0) && (result == 0 || result == 1 || result > 1) && (result == 0 || result <= c) && (result <= num || result <= c - 1 + 1) && (result <= num || result <= c + 1) && (result <= num || 0 <= c) && (result <= c) && (result <= c - 1) && (result <= c - 1 + 1) && (result <= c + 1) && (result <= c && result >= 0) && (result <= c && c >= 1) && (result <= c && 0 <= result) && (result <= c && 0 <= c) && (result < c - 1 + 1) && (result < c + 1) && (result - c <= 0) && (result % 2 == result % 2) && (result % 2 == c % 2 || result % 2 != c % 2) && (result % 2 == 0 || result % 2 == 1) && (c >= 1 ==> result >= 0) && (c >= 1 ==> result <= c) && (c >= 1 && result >= 0) && (c <= num + 1 || result <= c - 1 + 1) && (c <= num + 1 || result <= c + 1) && (c - result <= num || result <= c + 1) && (c - result <= num || 0 <= c) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (1 <= c) && (1 <= c || result == 0) && (1 <= c - result) && (0 <= result) && (0 <= result && result <= c) && (0 <= result && 0 <= c) && (0 <= c) && (0 <= c || result <= c + 1) && (0 <= c || c <= num + 1) && (0 <= c - result) && (0 < c) && ((result % 2 == 0) || (result % 2 == 1));
    assigns \nothing;
*/
void check_B_implies_A(int c, int k, int num) {
    /*@ assert (1 <= c) && (c <= num + 1) && (num == \at(num,Pre)) && (0 <= result) && (result <= c); */
}
