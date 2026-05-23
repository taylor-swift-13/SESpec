#include <limits.h>

/*@ requires (0 <= low <= a_len) && (-1 <= high < a_len) && (low <= high + 1) && (x == \at(x,Pre)) && (a_len == \at(a_len,Pre)) && (a == \at(a,Pre)) && (\forall integer k) && (\forall integer i, j) && ((low <= high) ==> (\forall integer k) && ((0 <= \at(a_len,Pre) - 1) ==> (low <= high + 1)) && ((0 <= \at(a_len,Pre) - 1) ==> (((high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= low <= a_len))) && ((0 <= \at(a_len,Pre) - 1) ==> (((high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (-1 <= high < a_len))) && ((!(0 <= \at(a_len,Pre) - 1)) ==> ((high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))));
    assigns \nothing;
*/
void check_A_implies_B(int *a, int *a_len, int *high, int i, int j, int k, int *low, int *x) {
    /*@ assert (low == 0 || high == a_len - 1 || a[low - 1] < a[high + 1]) && (low == 0 || a[low - 1] < x) && (low <= a_len || high + 1 <= a_len) && (high == a_len - 1 || a[high + 1] >= x) && (high < a_len) && (high + 1 <= a_len) && (high + 1 <= a_len || low <= high + 1) && (high + 1 <= a_len || 0 <= high + 1) && (0 <= low) && (0 <= low || high < 0) && (-1 <= high || high + 1 <= a_len); */
}

/*@ requires (low == 0 || high == a_len - 1 || a[low - 1] < a[high + 1]) && (low == 0 || a[low - 1] < x) && (low <= a_len || high + 1 <= a_len) && (high == a_len - 1 || a[high + 1] >= x) && (high < a_len) && (high + 1 <= a_len) && (high + 1 <= a_len || low <= high + 1) && (high + 1 <= a_len || 0 <= high + 1) && (0 <= low) && (0 <= low || high < 0) && (-1 <= high || high + 1 <= a_len);
    assigns \nothing;
*/
void check_B_implies_A(int *a, int *a_len, int *high, int i, int j, int k, int *low, int *x) {
    /*@ assert (0 <= low <= a_len) && (-1 <= high < a_len) && (low <= high + 1) && (x == \at(x,Pre)) && (a_len == \at(a_len,Pre)) && (a == \at(a,Pre)) && (\forall integer k) && (\forall integer i, j) && ((low <= high) ==> (\forall integer k) && ((0 <= \at(a_len,Pre) - 1) ==> (low <= high + 1)) && ((0 <= \at(a_len,Pre) - 1) ==> (((high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= low <= a_len))) && ((0 <= \at(a_len,Pre) - 1) ==> (((high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (-1 <= high < a_len))) && ((!(0 <= \at(a_len,Pre) - 1)) ==> ((high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre)))); */
}
