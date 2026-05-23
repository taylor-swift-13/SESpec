#include <limits.h>

/*@ logic integer cube_sum(integer n) =
    n <= 0 ? 0 : cube_sum(n - 1) + n * n * n; */
/*@ logic integer tri_sum(integer n) =
    n <= 0 ? 0 : tri_sum(n - 1) + n; */

/*@ requires (1 <= j <= diff + 1) && (max == 0) && (diff == \at(diff,Pre)) && (result >= 0) && (result == cube_sum(j - 1));
    assigns \nothing;
*/
void check_A_implies_B(int diff, int *j, int k) {
    /*@ assert (result >= max || j <= diff + 1); */
    /*@ assert (result >= max || diff < 0); */
    /*@ assert (result >= 0 && max >= 0); */
    /*@ assert (result == 0 || result > 0); */
    /*@ assert (result == 0 || max == 0 || result >= max); */
    /*@ assert (result == ((j - 1) * j * (j - 1) * j) / 4); */
    /*@ assert (result - max >= 0 || diff < 0); */
    /*@ assert (max == 0); */
    /*@ assert (max == 0 || max > 0); */
    /*@ assert (max <= result); */
    /*@ assert (max <= result || j <= diff + 1); */
    /*@ assert (max <= result || diff < 0); */
    /*@ assert (j == 1 || j > 1); */
    /*@ assert (j <= diff + 1 || diff < 0); */
    /*@ assert (j <= diff + 1 || 0 <= j); */
    /*@ assert (j <= diff + 1 ==> result >= max); */
    /*@ assert (j - 1 <= diff || diff < 0); */
    /*@ assert (diff >= 0 ==> result >= max); */
    /*@ assert (diff >= 0 ==> result >= max || j <= diff + 1); */
    /*@ assert (diff >= 0 ==> result >= 0); */
    /*@ assert (diff >= 0 ==> result >= 0 && max >= 0); */
    /*@ assert (diff >= 0 ==> result - max >= 0); */
    /*@ assert (diff >= 0 ==> max >= 0); */
    /*@ assert (diff >= 0 ==> max <= result); */
    /*@ assert (diff >= 0 ==> max <= result || j - 1 <= diff); */
    /*@ assert (diff >= 0 ==> j >= 1); */
    /*@ assert (diff >= 0 ==> j <= diff + 1); */
    /*@ assert (diff >= 0 ==> j - 1 <= diff); */
    /*@ assert (diff >= 0 ==> 1 <= j); */
    /*@ assert (diff >= 0 ==> 1 <= j <= diff + 1); */
    /*@ assert (diff >= 0 ==> 0 <= j); */
    /*@ assert (diff >= 0 ==> 0 <= j <= diff + 1); */
    /*@ assert (diff < 0 ==> j == 1); */
    /*@ assert (\forall integer k; 1 <= k < j ==> result >= max); */
    /*@ assert (\forall integer k; 1 <= k < j ==> result >= max || diff < 0); */
    /*@ assert (\forall integer k; 1 <= k < j ==> result >= 0); */
    /*@ assert (\forall integer k; 1 <= k < j ==> max >= 0); */
    /*@ assert (\forall integer k; 1 <= k < j ==> max == 0); */
    /*@ assert (\forall integer k; 1 <= k < j ==> max <= result); */
    /*@ assert (1 <= j); */
    /*@ assert (0 <= result); */
    /*@ assert (0 <= result - max); */
    /*@ assert (0 <= result && 0 <= max); */
    /*@ assert (0 <= max); */
    /*@ assert (0 <= j); */
    /*@ assert (0 < j); */
    /*@ assert (0 < j); */
    /*@ assert (0 < j); */
    /*@ assert (0 < j); */
    /*@ assert (0 < j); */
    /*@ assert (0 < j); */
    /*@ assert (0 < j); */
    /*@ assert (0 < j); */
    /*@ assert (0 < j); */
    /*@ assert (0 < j); */
    /*@ assert (0 < j); */
    /*@ assert (0 < j); */
}

/*@ requires (result >= max || j <= diff + 1) && (result >= max || diff < 0) && (result >= 0 && max >= 0) && (result == 0 || result > 0) && (result == 0 || max == 0 || result >= max) && (result == ((j - 1) * j * (j - 1) * j) / 4) && (result - max >= 0 || diff < 0) && (max == 0) && (max == 0 || max > 0) && (max <= result) && (max <= result || j <= diff + 1) && (max <= result || diff < 0) && (j == 1 || j > 1) && (j <= diff + 1 || diff < 0) && (j <= diff + 1 || 0 <= j) && (j <= diff + 1 ==> result >= max) && (j - 1 <= diff || diff < 0) && (diff >= 0 ==> result >= max) && (diff >= 0 ==> result >= max || j <= diff + 1) && (diff >= 0 ==> result >= 0) && (diff >= 0 ==> result >= 0 && max >= 0) && (diff >= 0 ==> result - max >= 0) && (diff >= 0 ==> max >= 0) && (diff >= 0 ==> max <= result) && (diff >= 0 ==> max <= result || j - 1 <= diff) && (diff >= 0 ==> j >= 1) && (diff >= 0 ==> j <= diff + 1) && (diff >= 0 ==> j - 1 <= diff) && (diff >= 0 ==> 1 <= j) && (diff >= 0 ==> 1 <= j <= diff + 1) && (diff >= 0 ==> 0 <= j) && (diff >= 0 ==> 0 <= j <= diff + 1) && (diff < 0 ==> j == 1) && (\forall integer k; 1 <= k < j ==> result >= max) && (\forall integer k; 1 <= k < j ==> result >= max || diff < 0) && (\forall integer k; 1 <= k < j ==> result >= 0) && (\forall integer k; 1 <= k < j ==> max >= 0) && (\forall integer k; 1 <= k < j ==> max == 0) && (\forall integer k; 1 <= k < j ==> max <= result) && (1 <= j) && (0 <= result) && (0 <= result - max) && (0 <= result && 0 <= max) && (0 <= max) && (0 <= j) && (0 < j) && (0 < j) && (0 < j) && (0 < j) && (0 < j) && (0 < j) && (0 < j) && (0 < j) && (0 < j) && (0 < j) && (0 < j) && (0 < j);
    assigns \nothing;
*/
void check_B_implies_A(int diff, int *j, int k) {
    /*@ assert (1 <= j <= diff + 1); */
    /*@ assert (max == 0); */
    /*@ assert (diff == \at(diff,Pre)); */
    /*@ assert (result >= 0); */
    /*@ assert (result == cube_sum(j - 1)); */
}
