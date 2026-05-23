#include <limits.h>

/*@logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);*/
/*@logic integer copy_count(int* src, int* dst, integer lo, integer hi) =
    lo >= hi ? 0
             : copy_count(src, dst, lo, hi - 1) + (dst[hi - 1] == src[hi - 1] ? 1 : 0);*/

/*@ requires ((\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (iBegin <= k <= iEnd)) && ((\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (\forall integer j) && ((\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (\forall integer j) && ((!(\at(iEnd,Pre) - \at(iBegin,Pre) > 0)) ==> ((k == \at(iBegin,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))&&(iEnd == \at(iEnd,Pre))&&(iBegin == \at(iBegin,Pre))&&(b_len == \at(b_len,Pre))&&(b == \at(b,Pre)))) && (a_len == \at(a_len,Pre)) && (a == \at(a,Pre)) && (iEnd == \at(iEnd,Pre)) && (iBegin == \at(iBegin,Pre)) && (b_len == \at(b_len,Pre)) && (b == \at(b,Pre)) && ((\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (\forall integer j);
    assigns \nothing;
*/
void check_A_implies_B(int a, int a_len, int b, int b_len, int iBegin, int iEnd, int j, int k, int t, int u) {
    /*@ assert (\forall integer u) && (k == iBegin || k > iBegin) && (k == iBegin + (k - iBegin)) && (k - iBegin == 0 || k - iBegin > 0) && (iBegin <= k) && (\forall integer u) && (\forall integer u) && (\forall integer u) && (\forall integer u) && (\forall integer u) && (\forall integer u) && (\forall integer u) && (\forall integer u) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer j) && (\forall integer j) && (0 <= k - iBegin); */
}

/*@ requires (\forall integer u) && (k == iBegin || k > iBegin) && (k == iBegin + (k - iBegin)) && (k - iBegin == 0 || k - iBegin > 0) && (iBegin <= k) && (\forall integer u) && (\forall integer u) && (\forall integer u) && (\forall integer u) && (\forall integer u) && (\forall integer u) && (\forall integer u) && (\forall integer u) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer t) && (\forall integer j) && (\forall integer j) && (0 <= k - iBegin);
    assigns \nothing;
*/
void check_B_implies_A(int a, int a_len, int b, int b_len, int iBegin, int iEnd, int j, int k, int t, int u) {
    /*@ assert ((\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (iBegin <= k <= iEnd)) && ((\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (\forall integer j) && ((\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (\forall integer j) && ((!(\at(iEnd,Pre) - \at(iBegin,Pre) > 0)) ==> ((k == \at(iBegin,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))&&(iEnd == \at(iEnd,Pre))&&(iBegin == \at(iBegin,Pre))&&(b_len == \at(b_len,Pre))&&(b == \at(b,Pre)))) && (a_len == \at(a_len,Pre)) && (a == \at(a,Pre)) && (iEnd == \at(iEnd,Pre)) && (iBegin == \at(iBegin,Pre)) && (b_len == \at(b_len,Pre)) && (b == \at(b,Pre)) && ((\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (\forall integer j); */
}
