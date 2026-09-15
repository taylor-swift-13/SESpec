#include <limits.h>
#include <stdlib.h>

/*@ logic integer count_odd_upto(integer n) =
    n <= 0 ? 0 : count_odd_upto(n - 1) + (((n - 1) % 2 != 0) ? 1 : 0); */
/*@ logic integer count_even_upto(integer n) =
    n <= 0 ? 0 : count_even_upto(n - 1) + (((n - 1) % 2 == 0) ? 1 : 0); */

/*@ requires (\forall integer k; 0 <= k < c ==> result[k] == k + 1);
    assigns \nothing;
*/
void check_A_implies_B(int b_len, int c, int j, int k, int result_len, int value) {
    /*@ assert (result_len == value); */
    /*@ assert (j == 0); */
    /*@ assert (j == 0 || j > 0); */
    /*@ assert (j <= c); */
    /*@ assert (c == j || c >= j); */
    /*@ assert (c == 0 || c >= 0); */
    /*@ assert (c == 0 || c > 0); */
    /*@ assert (b_len == value); */
    /*@ assert (\forall integer k; 0 <= k < c ==> result[k] > 0); */
    /*@ assert (\forall integer k; 0 <= k < c ==> result[k] == k + 1); */
    /*@ assert (0 <= j); */
    /*@ assert (0 <= c); */
}

/*@ requires (result_len == value) && (j == 0) && (j == 0 || j > 0) && (j <= c) && (c == j || c >= j) && (c == 0 || c >= 0) && (c == 0 || c > 0) && (b_len == value) && (\forall integer k; 0 <= k < c ==> result[k] > 0) && (\forall integer k; 0 <= k < c ==> result[k] == k + 1) && (0 <= j) && (0 <= c);
    assigns \nothing;
*/
void check_B_implies_A(int b_len, int c, int j, int k, int result_len, int value) {
    /*@ assert (\forall integer k; 0 <= k < c ==> result[k] == k + 1); */
}
