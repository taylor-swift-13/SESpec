#include <limits.h>

/*@ requires (0 <= low <= a_len) && (-1 <= high < a_len) && (low <= high + 1) && (x == \at(x,Pre)) && (a_len == \at(a_len,Pre)) && (a == \at(a,Pre)) && (\forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre)) && (\forall integer i, j; 0 <= i <= j < a_len ==> a[i] <= a[j]) && ((low <= high) ==> (\forall integer k; low <= k <= high ==> (a[k] == x || a[k] < x || a[k] > x))) && ((0 <= \at(a_len,Pre) - 1) ==> (low <= high + 1)) && ((0 <= \at(a_len,Pre) - 1) ==> (((high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= low <= a_len))) && ((0 <= \at(a_len,Pre) - 1) ==> (((high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (-1 <= high < a_len))) && ((!(0 <= \at(a_len,Pre) - 1)) ==> ((high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))));
    assigns \nothing;
*/
void check_A_implies_B(int *a, int a_len, int high, int i, int j, int k, int low, int x) {
    /*@ assert (low == 0 || high == a_len - 1 || a[low - 1] < a[high + 1]); */
    /*@ assert (low == 0 || a[low - 1] < x); */
    /*@ assert (low <= a_len || high + 1 <= a_len); */
    /*@ assert (high == a_len - 1 || a[high + 1] >= x); */
    /*@ assert (high < a_len); */
    /*@ assert (high + 1 <= a_len); */
    /*@ assert (high + 1 <= a_len || low <= high + 1); */
    /*@ assert (high + 1 <= a_len || 0 <= high + 1); */
    /*@ assert (0 <= low); */
    /*@ assert (0 <= low || high < 0); */
    /*@ assert (-1 <= high || high + 1 <= a_len); */
}

/*@ requires (low == 0 || high == a_len - 1 || a[low - 1] < a[high + 1]) && (low == 0 || a[low - 1] < x) && (low <= a_len || high + 1 <= a_len) && (high == a_len - 1 || a[high + 1] >= x) && (high < a_len) && (high + 1 <= a_len) && (high + 1 <= a_len || low <= high + 1) && (high + 1 <= a_len || 0 <= high + 1) && (0 <= low) && (0 <= low || high < 0) && (-1 <= high || high + 1 <= a_len);
    assigns \nothing;
*/
void check_B_implies_A(int *a, int a_len, int high, int i, int j, int k, int low, int x) {
    /*@ assert (0 <= low <= a_len); */
    /*@ assert (-1 <= high < a_len); */
    /*@ assert (low <= high + 1); */
    /*@ assert (x == \at(x,Pre)); */
    /*@ assert (a_len == \at(a_len,Pre)); */
    /*@ assert (a == \at(a,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre)); */
    /*@ assert (\forall integer i, j; 0 <= i <= j < a_len ==> a[i] <= a[j]); */
    /*@ assert ((low <= high) ==> (\forall integer k; low <= k <= high ==> (a[k] == x || a[k] < x || a[k] > x))); */
    /*@ assert ((0 <= \at(a_len,Pre) - 1) ==> (low <= high + 1)); */
    /*@ assert ((0 <= \at(a_len,Pre) - 1) ==> (((high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= low <= a_len))); */
    /*@ assert ((0 <= \at(a_len,Pre) - 1) ==> (((high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (-1 <= high < a_len))); */
    /*@ assert ((!(0 <= \at(a_len,Pre) - 1)) ==> ((high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre)))); */
}
