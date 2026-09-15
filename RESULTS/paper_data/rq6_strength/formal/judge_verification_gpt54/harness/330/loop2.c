#include <limits.h>

/*@ logic integer cube_sum(integer n) =
    n <= 0 ? 0 : cube_sum(n - 1) + n * n * n; */
/*@ logic integer tri_sum(integer n) =
    n <= 0 ? 0 : tri_sum(n - 1) + n; */

/*@ requires (1 <= j <= diff + 1) && (diff == \at(diff,Pre)) && (0 <= max) && (max == tri_sum(j - 1));
    assigns \nothing;
*/
void check_A_implies_B(int diff, int *j, int k) {
    /*@ assert (diff >= 0 ==> 0 <= j <= diff + 1); */
    /*@ assert (result >= max || j <= diff + 1); */
    /*@ assert (result >= 0 && max >= 0); */
    /*@ assert (result == 0 || result > 0); */
    /*@ assert (max == 0 || max > 0); */
    /*@ assert (max == (j - 1) * j / 2); */
    /*@ assert (max == (j * (j - 1)) / 2); */
    /*@ assert (max == ((j - 1) * j) / 2); */
    /*@ assert (max <= result || j <= diff + 1); */
    /*@ assert (max <= result || j - 1 <= diff); */
    /*@ assert (j == 1 || j > 1); */
    /*@ assert (j <= diff + 1 || max <= result); */
    /*@ assert (j - 1 <= diff || max <= result); */
    /*@ assert (diff >= 0 ==> result >= 0); */
    /*@ assert (diff >= 0 ==> result >= 0 && max >= 0); */
    /*@ assert (diff >= 0 ==> max >= 0); */
    /*@ assert (diff >= 0 ==> j >= 1); */
    /*@ assert (diff >= 0 ==> j >= 1 && j <= diff + 1); */
    /*@ assert (diff >= 0 ==> j <= diff + 1); */
    /*@ assert (diff >= 0 ==> j - 1 <= diff); */
    /*@ assert (diff >= 0 ==> 1 <= j); */
    /*@ assert (diff >= 0 ==> 1 <= j <= diff + 1); */
    /*@ assert (diff < 0 ==> j == 1); */
    /*@ assert (\forall integer k; 1 <= k < j ==> result >= 0); */
    /*@ assert (\forall integer k; 1 <= k < j ==> result >= 0 && max >= 0); */
    /*@ assert (\forall integer k; 1 <= k < j ==> max >= 0); */
    /*@ assert (1 <= j); */
    /*@ assert (0 <= result); */
    /*@ assert (0 <= result && 0 <= max); */
    /*@ assert (0 <= max); */
    /*@ assert (0 <= j); */
}

/*@ requires (diff >= 0 ==> 0 <= j <= diff + 1) && (result >= max || j <= diff + 1) && (result >= 0 && max >= 0) && (result == 0 || result > 0) && (max == 0 || max > 0) && (max == (j - 1) * j / 2) && (max == (j * (j - 1)) / 2) && (max == ((j - 1) * j) / 2) && (max <= result || j <= diff + 1) && (max <= result || j - 1 <= diff) && (j == 1 || j > 1) && (j <= diff + 1 || max <= result) && (j - 1 <= diff || max <= result) && (diff >= 0 ==> result >= 0) && (diff >= 0 ==> result >= 0 && max >= 0) && (diff >= 0 ==> max >= 0) && (diff >= 0 ==> j >= 1) && (diff >= 0 ==> j >= 1 && j <= diff + 1) && (diff >= 0 ==> j <= diff + 1) && (diff >= 0 ==> j - 1 <= diff) && (diff >= 0 ==> 1 <= j) && (diff >= 0 ==> 1 <= j <= diff + 1) && (diff < 0 ==> j == 1) && (\forall integer k; 1 <= k < j ==> result >= 0) && (\forall integer k; 1 <= k < j ==> result >= 0 && max >= 0) && (\forall integer k; 1 <= k < j ==> max >= 0) && (1 <= j) && (0 <= result) && (0 <= result && 0 <= max) && (0 <= max) && (0 <= j);
    assigns \nothing;
*/
void check_B_implies_A(int diff, int *j, int k) {
    /*@ assert (1 <= j <= diff + 1); */
    /*@ assert (diff == \at(diff,Pre)); */
    /*@ assert (0 <= max); */
    /*@ assert (max == tri_sum(j - 1)); */
}
