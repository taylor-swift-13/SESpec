#include <limits.h>

/*@ logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0); */
/*@ logic integer copy_count(int* src, int* dst, integer lo, integer hi) =
    lo >= hi ? 0
             : copy_count(src, dst, lo, hi - 1) + (dst[hi - 1] == src[hi - 1] ? 1 : 0); */

/*@ requires ((\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (iBegin <= k <= iEnd)) && ((\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (\forall integer j; k <= j < iEnd ==> a[j] == \at(a[j],Pre))) && ((\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (\forall integer j; 0 <= j < a_len ==> (j < iBegin || j >= iEnd) ==> a[j] == \at(a[j],Pre))) && ((!(\at(iEnd,Pre) - \at(iBegin,Pre) > 0)) ==> ((k == \at(iBegin,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))&&(iEnd == \at(iEnd,Pre))&&(iBegin == \at(iBegin,Pre))&&(b_len == \at(b_len,Pre))&&(b == \at(b,Pre)))) && (a_len == \at(a_len,Pre)) && (a == \at(a,Pre)) && (iEnd == \at(iEnd,Pre)) && (iBegin == \at(iBegin,Pre)) && (b_len == \at(b_len,Pre)) && (b == \at(b,Pre)) && ((\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (\forall integer j; 0 <= j < a_len ==> (j < iBegin || j >= k) ==> a[j] == \at(a[j],Pre)));
    assigns \nothing;
*/
void check_A_implies_B(int *a, int a_len, int *b, int b_len, int iBegin, int iEnd, int j, int k, int t, int u) {
    /*@ assert (\forall integer u; 0 <= u < iBegin || k <= u < a_len ==> a[u] == a[u]); */
    /*@ assert (k == iBegin || k > iBegin); */
    /*@ assert (k == iBegin + (k - iBegin)); */
    /*@ assert (k - iBegin == 0 || k - iBegin > 0); */
    /*@ assert (iBegin <= k); */
    /*@ assert (\forall integer u; k <= u < iEnd ==> a[u] == a[u]); */
    /*@ assert (\forall integer u; iEnd <= u < a_len ==> a[u] == a[u]); */
    /*@ assert (\forall integer u; iBegin <= u < iEnd ==> (u < k ==> a[u] == b[u]) || (u >= k ==> a[u] == a[u])); */
    /*@ assert (\forall integer u; 0 <= u < iBegin || iEnd <= u < b_len ==> a[u] == a[u]); */
    /*@ assert (\forall integer u; 0 <= u < iBegin || iEnd <= u < a_len ==> a[u] == a[u]); */
    /*@ assert (\forall integer u; 0 <= u < iBegin ==> a[u] == a[u]); */
    /*@ assert (\forall integer u; 0 <= u < b_len ==> (u < k ==> a[u] == b[u]) || (u >= k ==> a[u] == a[u])); */
    /*@ assert (\forall integer u; 0 <= u < b_len ==> (u < iBegin || u >= k ==> a[u] == a[u])); */
    /*@ assert (\forall integer t; k <= t < iEnd ==> a[t] == a[t]); */
    /*@ assert (\forall integer t; iEnd <= t < a_len ==> a[t] == a[t]); */
    /*@ assert (\forall integer t; iBegin <= t < iEnd ==> (t < k ==> a[t] == b[t]) || (t >= k ==> a[t] == a[t])); */
    /*@ assert (\forall integer t; 0 <= t < iBegin || iEnd <= t < a_len ==> a[t] == a[t]); */
    /*@ assert (\forall integer t; 0 <= t < iBegin ==> a[t] == a[t]); */
    /*@ assert (\forall integer t; 0 <= t < b_len ==> (t < iBegin || t >= k ==> a[t] == a[t])); */
    /*@ assert (\forall integer j; k <= j < iEnd ==> a[j] == a[j]); */
    /*@ assert (\forall integer j; 0 <= j < iBegin ==> a[j] == a[j]); */
    /*@ assert (0 <= k - iBegin); */
}

/*@ requires (\forall integer u; 0 <= u < iBegin || k <= u < a_len ==> a[u] == a[u]) && (k == iBegin || k > iBegin) && (k == iBegin + (k - iBegin)) && (k - iBegin == 0 || k - iBegin > 0) && (iBegin <= k) && (\forall integer u; k <= u < iEnd ==> a[u] == a[u]) && (\forall integer u; iEnd <= u < a_len ==> a[u] == a[u]) && (\forall integer u; iBegin <= u < iEnd ==> (u < k ==> a[u] == b[u]) || (u >= k ==> a[u] == a[u])) && (\forall integer u; 0 <= u < iBegin || iEnd <= u < b_len ==> a[u] == a[u]) && (\forall integer u; 0 <= u < iBegin || iEnd <= u < a_len ==> a[u] == a[u]) && (\forall integer u; 0 <= u < iBegin ==> a[u] == a[u]) && (\forall integer u; 0 <= u < b_len ==> (u < k ==> a[u] == b[u]) || (u >= k ==> a[u] == a[u])) && (\forall integer u; 0 <= u < b_len ==> (u < iBegin || u >= k ==> a[u] == a[u])) && (\forall integer t; k <= t < iEnd ==> a[t] == a[t]) && (\forall integer t; iEnd <= t < a_len ==> a[t] == a[t]) && (\forall integer t; iBegin <= t < iEnd ==> (t < k ==> a[t] == b[t]) || (t >= k ==> a[t] == a[t])) && (\forall integer t; 0 <= t < iBegin || iEnd <= t < a_len ==> a[t] == a[t]) && (\forall integer t; 0 <= t < iBegin ==> a[t] == a[t]) && (\forall integer t; 0 <= t < b_len ==> (t < iBegin || t >= k ==> a[t] == a[t])) && (\forall integer j; k <= j < iEnd ==> a[j] == a[j]) && (\forall integer j; 0 <= j < iBegin ==> a[j] == a[j]) && (0 <= k - iBegin);
    assigns \nothing;
*/
void check_B_implies_A(int *a, int a_len, int *b, int b_len, int iBegin, int iEnd, int j, int k, int t, int u) {
    /*@ assert ((\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (iBegin <= k <= iEnd)); */
    /*@ assert ((\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (\forall integer j; k <= j < iEnd ==> a[j] == \at(a[j],Pre))); */
    /*@ assert ((\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (\forall integer j; 0 <= j < a_len ==> (j < iBegin || j >= iEnd) ==> a[j] == \at(a[j],Pre))); */
    /*@ assert ((!(\at(iEnd,Pre) - \at(iBegin,Pre) > 0)) ==> ((k == \at(iBegin,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))&&(iEnd == \at(iEnd,Pre))&&(iBegin == \at(iBegin,Pre))&&(b_len == \at(b_len,Pre))&&(b == \at(b,Pre)))); */
    /*@ assert (a_len == \at(a_len,Pre)); */
    /*@ assert (a == \at(a,Pre)); */
    /*@ assert (iEnd == \at(iEnd,Pre)); */
    /*@ assert (iBegin == \at(iBegin,Pre)); */
    /*@ assert (b_len == \at(b_len,Pre)); */
    /*@ assert (b == \at(b,Pre)); */
    /*@ assert ((\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (\forall integer j; 0 <= j < a_len ==> (j < iBegin || j >= k) ==> a[j] == \at(a[j],Pre))); */
}
