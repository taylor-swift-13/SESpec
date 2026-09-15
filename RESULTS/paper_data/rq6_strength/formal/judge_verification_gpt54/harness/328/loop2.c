#include <limits.h>

/*@ logic integer sum_cubes(integer n) =
      n <= 0 ? 0 : sum_cubes(n - 1) + n * n * n; */

/*@ requires (c >= 1) && (diff == \at(diff,Pre)) && (result >= 0) && (max >= 0) && (max == ((c - 1) * c) / 2) && ((c <= diff) ==> (max == ((c - 1) * c) / 2));
    assigns \nothing;
*/
void check_A_implies_B(int *c, int diff, int *k) {
    /*@ assert (diff < 0 ==> c == 1); */
    /*@ assert (result >= max || c <= diff + 1); */
    /*@ assert (result == 0 || result > 0); */
    /*@ assert (result == (c - 1) * c * (2 * c - 1) * (c - 1) / 4 || result >= 0); */
    /*@ assert (result - max >= 0 || c <= diff + 1); */
    /*@ assert (max == c * (c - 1) / 2); */
    /*@ assert (max == (c - 1) * c / 2); */
    /*@ assert (max <= result || c <= diff + 1); */
    /*@ assert (max <= c * (c - 1) / 2); */
    /*@ assert (diff >= 0 ==> result >= 0); */
    /*@ assert (diff >= 0 ==> max >= 0); */
    /*@ assert (diff >= 0 ==> max <= c * (c - 1) / 2); */
    /*@ assert (diff >= 0 ==> c >= 1); */
    /*@ assert (diff >= 0 ==> c <= diff + 1); */
    /*@ assert (\forall integer k; 1 <= k < c ==> max >= k); */
    /*@ assert (\exists integer k; 0 <= k < c && result >= k * k * k); */
    /*@ assert (\exists integer k; 0 <= k < c && max == k * (k + 1) / 2); */
    /*@ assert (1 <= c); */
    /*@ assert (0 <= result); */
    /*@ assert (0 <= result - max || c <= diff + 1); */
    /*@ assert (0 <= max); */
    /*@ assert (0 <= c); */
}

/*@ requires (diff < 0 ==> c == 1) && (result >= max || c <= diff + 1) && (result == 0 || result > 0) && (result == (c - 1) * c * (2 * c - 1) * (c - 1) / 4 || result >= 0) && (result - max >= 0 || c <= diff + 1) && (max == c * (c - 1) / 2) && (max == (c - 1) * c / 2) && (max <= result || c <= diff + 1) && (max <= c * (c - 1) / 2) && (diff >= 0 ==> result >= 0) && (diff >= 0 ==> max >= 0) && (diff >= 0 ==> max <= c * (c - 1) / 2) && (diff >= 0 ==> c >= 1) && (diff >= 0 ==> c <= diff + 1) && (\forall integer k; 1 <= k < c ==> max >= k) && (\exists integer k; 0 <= k < c && result >= k * k * k) && (\exists integer k; 0 <= k < c && max == k * (k + 1) / 2) && (1 <= c) && (0 <= result) && (0 <= result - max || c <= diff + 1) && (0 <= max) && (0 <= c);
    assigns \nothing;
*/
void check_B_implies_A(int *c, int diff, int *k) {
    /*@ assert (c >= 1); */
    /*@ assert (diff == \at(diff,Pre)); */
    /*@ assert (result >= 0); */
    /*@ assert (max >= 0); */
    /*@ assert (max == ((c - 1) * c) / 2); */
    /*@ assert ((c <= diff) ==> (max == ((c - 1) * c) / 2)); */
}
