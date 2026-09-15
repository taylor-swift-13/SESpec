#include <limits.h>

/*@ logic integer sum_cubes(integer n) =
      n <= 0 ? 0 : sum_cubes(n - 1) + n * n * n; */

/*@ requires (c >= 1) && (diff == \at(diff,Pre)) && (max == 0) && (result >= 0) && (result == sum_cubes(c - 1)) && ((c <= \at(diff,Pre)) ==> (result == sum_cubes(c - 1))) && ((c <= \at(diff,Pre)) ==> (result >= 0)) && ((!(c <= \at(diff,Pre))) ==> ((max == 0)&&(result >= 0)&&(diff == \at(diff,Pre))));
    assigns \nothing;
*/
void check_A_implies_B(int *c, int diff, int *k) {
    /*@ assert (result >= max || diff < 0); */
    /*@ assert (result >= max || c <= diff + 1); */
    /*@ assert (result == max * max || result >= max); */
    /*@ assert (result == 0 || result >= max); */
    /*@ assert (result == 0 || result >= 0); */
    /*@ assert (result == 0 || result > max); */
    /*@ assert (result == 0 || result > 0); */
    /*@ assert (result == (c - 1) * c * (2 * c - 1) * (c - 1) / 4 || result >= 0); */
    /*@ assert (result == (c - 1) * c * (2 * c - 1) * (2 * c - 1) / 4 || result >= 0); */
    /*@ assert (result - max >= 0 || c <= diff + 1); */
    /*@ assert (max == 0); */
    /*@ assert (max == 0 || max >= c - 1); */
    /*@ assert (max == (c - 1) * c / 2 || max >= 0); */
    /*@ assert (max <= result); */
    /*@ assert (max <= result || c <= diff + 1); */
    /*@ assert (max <= c * (c - 1) / 2); */
    /*@ assert (diff >= 0 ==> result >= max); */
    /*@ assert (diff >= 0 ==> result >= 0); */
    /*@ assert (diff >= 0 ==> max >= 0); */
    /*@ assert (diff >= 0 ==> max <= c * (c - 1) / 2); */
    /*@ assert (diff >= 0 ==> c >= 1); */
    /*@ assert (diff >= 0 ==> c <= diff + 1); */
    /*@ assert (\forall integer k; 1 <= k < c ==> result >= max); */
    /*@ assert (\forall integer k; 1 <= k < c ==> result >= k*k); */
    /*@ assert (\forall integer k; 1 <= k < c ==> result >= k * k); */
    /*@ assert (\forall integer k; 1 <= k < c ==> max <= result); */
    /*@ assert (\exists integer k; 0 <= k < c && result >= k * k); */
    /*@ assert (\exists integer k; 0 <= k < c && result >= k * k * k); */
    /*@ assert (\exists integer k; 0 <= k < c && max == k * (k + 1) / 2); */
    /*@ assert (1 <= c); */
    /*@ assert (0 <= result); */
    /*@ assert (0 <= result - max); */
    /*@ assert (0 <= max); */
    /*@ assert (0 <= c); */
    /*@ assert ((c - 1) * c * (2 * c - 1) / 6 <= result); */
}

/*@ requires (result >= max || diff < 0) && (result >= max || c <= diff + 1) && (result == max * max || result >= max) && (result == 0 || result >= max) && (result == 0 || result >= 0) && (result == 0 || result > max) && (result == 0 || result > 0) && (result == (c - 1) * c * (2 * c - 1) * (c - 1) / 4 || result >= 0) && (result == (c - 1) * c * (2 * c - 1) * (2 * c - 1) / 4 || result >= 0) && (result - max >= 0 || c <= diff + 1) && (max == 0) && (max == 0 || max >= c - 1) && (max == (c - 1) * c / 2 || max >= 0) && (max <= result) && (max <= result || c <= diff + 1) && (max <= c * (c - 1) / 2) && (diff >= 0 ==> result >= max) && (diff >= 0 ==> result >= 0) && (diff >= 0 ==> max >= 0) && (diff >= 0 ==> max <= c * (c - 1) / 2) && (diff >= 0 ==> c >= 1) && (diff >= 0 ==> c <= diff + 1) && (\forall integer k; 1 <= k < c ==> result >= max) && (\forall integer k; 1 <= k < c ==> result >= k*k) && (\forall integer k; 1 <= k < c ==> result >= k * k) && (\forall integer k; 1 <= k < c ==> max <= result) && (\exists integer k; 0 <= k < c && result >= k * k) && (\exists integer k; 0 <= k < c && result >= k * k * k) && (\exists integer k; 0 <= k < c && max == k * (k + 1) / 2) && (1 <= c) && (0 <= result) && (0 <= result - max) && (0 <= max) && (0 <= c) && ((c - 1) * c * (2 * c - 1) / 6 <= result);
    assigns \nothing;
*/
void check_B_implies_A(int *c, int diff, int *k) {
    /*@ assert (c >= 1); */
    /*@ assert (diff == \at(diff,Pre)); */
    /*@ assert (max == 0); */
    /*@ assert (result >= 0); */
    /*@ assert (result == sum_cubes(c - 1)); */
    /*@ assert ((c <= \at(diff,Pre)) ==> (result == sum_cubes(c - 1))); */
    /*@ assert ((c <= \at(diff,Pre)) ==> (result >= 0)); */
    /*@ assert ((!(c <= \at(diff,Pre))) ==> ((max == 0)&&(result >= 0)&&(diff == \at(diff,Pre)))); */
}
