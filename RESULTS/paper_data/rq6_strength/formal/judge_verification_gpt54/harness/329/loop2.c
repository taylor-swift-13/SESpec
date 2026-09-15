#include <limits.h>

/*@ logic integer cube_sum(integer n) =
    n <= 0 ? 0 : cube_sum(n - 1) + n * n * n; */
/*@ logic integer sum_upto(integer n) =
    n <= 0 ? 0 : sum_upto(n - 1) + n; */

/*@ requires (1 <= j <= diff + 1) && (max == sum_upto(j - 1)) && (0 <= max) && (max <= sum_upto(j - 1)) && (ret == cube_sum(diff)) && (diff == \at(diff,Pre)) && (ret - max == cube_sum(diff) - sum_upto(j - 1));
    assigns \nothing;
*/
void check_A_implies_B(int diff, int *j, int k, int ret) {
    /*@ assert (ret >= max || j <= diff + 1); */
    /*@ assert (ret >= 0 && max >= 0); */
    /*@ assert (ret == \sum(1, j-1, \lambda integer k; k*k*k) || ret >= 0); */
    /*@ assert (ret == \sum(1, j-1, \lambda integer k; k) || ret >= 0); */
    /*@ assert (ret == 0 || ret > 0); */
    /*@ assert (ret == (j-1) * j / 2 || ret >= 0); */
    /*@ assert (ret == (j-1) * j * (2*j-1) * (j-1) / 4 || ret >= 0); */
    /*@ assert (ret == (j - 1) * j * (j - 1) * j / 4 || ret >= 0); */
    /*@ assert (ret == (j - 1) * j * (2*j - 1) * (j - 1) / 4 || ret >= 0); */
    /*@ assert (ret == ((j - 1) * j) / 2 || ret >= 0); */
    /*@ assert (ret == ((j - 1) * j / 2) || ret >= 0); */
    /*@ assert (ret == ((j - 1) * j * (2*j - 1) * (j - 1)) / 4 || ret >= 0); */
    /*@ assert (ret - max >= 0 || j <= diff + 1); */
    /*@ assert (max == \sum(1, j-1, \lambda integer k; k) || max >= 0); */
    /*@ assert (max == 0 || max > 0); */
    /*@ assert (max == (j - 1) * j / 2 || max >= 0); */
    /*@ assert (max == ((j - 1) * j) / 2 || max >= 0); */
    /*@ assert (max == ((j - 1) * j / 2) || max >= 0); */
    /*@ assert (max <= ret || j <= diff + 1); */
    /*@ assert (j <= diff + 1 || ret >= 0); */
    /*@ assert (j <= diff + 1 || max >= 0); */
    /*@ assert (j <= diff + 1 || max <= ret); */
    /*@ assert (j <= diff + 1 || 0 <= ret - max); */
    /*@ assert (\forall integer k; 1 <= k < j ==> max >= k); */
    /*@ assert (\forall integer k; 1 <= k < j ==> max >= k - 1); */
    /*@ assert (\exists integer k; 1 <= k < j ==> ret >= k); */
    /*@ assert (1 <= j); */
    /*@ assert (1 <= j || j == 1); */
    /*@ assert (0 <= ret); */
    /*@ assert (0 <= ret - max || j <= diff + 1); */
    /*@ assert (0 <= max); */
    /*@ assert (0 <= j); */
}

/*@ requires (ret >= max || j <= diff + 1) && (ret >= 0 && max >= 0) && (ret == \sum(1, j-1, \lambda integer k; k*k*k) || ret >= 0) && (ret == \sum(1, j-1, \lambda integer k; k) || ret >= 0) && (ret == 0 || ret > 0) && (ret == (j-1) * j / 2 || ret >= 0) && (ret == (j-1) * j * (2*j-1) * (j-1) / 4 || ret >= 0) && (ret == (j - 1) * j * (j - 1) * j / 4 || ret >= 0) && (ret == (j - 1) * j * (2*j - 1) * (j - 1) / 4 || ret >= 0) && (ret == ((j - 1) * j) / 2 || ret >= 0) && (ret == ((j - 1) * j / 2) || ret >= 0) && (ret == ((j - 1) * j * (2*j - 1) * (j - 1)) / 4 || ret >= 0) && (ret - max >= 0 || j <= diff + 1) && (max == \sum(1, j-1, \lambda integer k; k) || max >= 0) && (max == 0 || max > 0) && (max == (j - 1) * j / 2 || max >= 0) && (max == ((j - 1) * j) / 2 || max >= 0) && (max == ((j - 1) * j / 2) || max >= 0) && (max <= ret || j <= diff + 1) && (j <= diff + 1 || ret >= 0) && (j <= diff + 1 || max >= 0) && (j <= diff + 1 || max <= ret) && (j <= diff + 1 || 0 <= ret - max) && (\forall integer k; 1 <= k < j ==> max >= k) && (\forall integer k; 1 <= k < j ==> max >= k - 1) && (\exists integer k; 1 <= k < j ==> ret >= k) && (1 <= j) && (1 <= j || j == 1) && (0 <= ret) && (0 <= ret - max || j <= diff + 1) && (0 <= max) && (0 <= j);
    assigns \nothing;
*/
void check_B_implies_A(int diff, int *j, int k, int ret) {
    /*@ assert (1 <= j <= diff + 1); */
    /*@ assert (max == sum_upto(j - 1)); */
    /*@ assert (0 <= max); */
    /*@ assert (max <= sum_upto(j - 1)); */
    /*@ assert (ret == cube_sum(diff)); */
    /*@ assert (diff == \at(diff,Pre)); */
    /*@ assert (ret - max == cube_sum(diff) - sum_upto(j - 1)); */
}
