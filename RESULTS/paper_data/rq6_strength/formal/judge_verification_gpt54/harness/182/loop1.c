#include <limits.h>

/*@ requires (0 <= low) && (high < a_len) && (0 <= mid) && (low <= high + 1) && (0 <= low && high < a_len && (low <= high + 1)) && ((((mid == 0)&&(high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= low))) && ((((mid == 0)&&(high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (high < a_len))) && ((((mid == 0)&&(high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= mid))) && ((!(0 <= \at(a_len,Pre) - 1)) ==> ((mid == 0)&&(high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre)))) && (x == \at(x,Pre)) && (a_len == \at(a_len,Pre)) && (a == \at(a,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *a, int a_len, int high, int low, int mid, int x) {
    /*@ assert (a_len > 0 ==> low <= a_len && -1 <= high < a_len); */
    /*@ assert (a_len == 0 || (high == a_len - 1 || a[high + 1] != x)); */
    /*@ assert (mid >= 0 || mid == 0); */
    /*@ assert (mid == 0 || 0 <= mid < a_len); */
    /*@ assert (mid == 0 || (0 <= mid < a_len)); */
    /*@ assert (low >= 0 && high < a_len); */
    /*@ assert (low == 0 || a[low - 1] <= x); */
    /*@ assert (high == a_len - 1 || high + 1 >= 0); */
    /*@ assert (high == a_len - 1 || a[high + 1] >= x); */
    /*@ assert (high == a_len - 1 || a[high + 1] != x); */
    /*@ assert (high < a_len); */
    /*@ assert (high < a_len || high == -1); */
    /*@ assert (a_len > 0 ==> low >= 0 && high < a_len); */
    /*@ assert (a_len > 0 ==> low == 0 || a[low - 1] <= x); */
    /*@ assert (a_len > 0 ==> low <= high + 1); */
    /*@ assert (a_len > 0 ==> low <= a_len); */
    /*@ assert (a_len > 0 ==> low <= a_len && high >= -1); */
    /*@ assert (a_len > 0 ==> low <= a_len && high < a_len); */
    /*@ assert (a_len > 0 ==> low <= a_len && -1 <= high); */
    /*@ assert (a_len > 0 ==> high >= -1); */
    /*@ assert (a_len > 0 ==> high == a_len - 1 || a[high + 1] >= x); */
    /*@ assert (a_len > 0 ==> high == a_len - 1 || a[high + 1] > x); */
    /*@ assert (a_len > 0 ==> high == a_len - 1 || a[high + 1] != x); */
    /*@ assert (a_len > 0 ==> high < a_len); */
    /*@ assert (a_len > 0 ==> 0 <= mid < a_len); */
    /*@ assert (a_len > 0 ==> 0 <= low); */
    /*@ assert (a_len > 0 ==> 0 <= low <= a_len); */
    /*@ assert (a_len > 0 ==> 0 <= low <= a_len && -1 <= high < a_len); */
    /*@ assert (a_len > 0 ==> 0 <= low && high < a_len); */
    /*@ assert (a_len > 0 ==> 0 <= low && -1 <= high < a_len); */
    /*@ assert (a_len > 0 ==> -1 <= high < a_len); */
    /*@ assert (a_len > 0 ==> (low == 0 || a[low - 1] <= x)); */
    /*@ assert (a_len > 0 ==> (low == 0 || a[low - 1] <= x) && (high == a_len - 1 || a[high + 1] >= x)); */
    /*@ assert (a_len > 0 ==> (low <= high + 1)); */
    /*@ assert (a_len > 0 ==> (low <= a_len && high >= -1)); */
    /*@ assert (a_len > 0 ==> (low <= a_len && -1 <= high)); */
    /*@ assert (a_len > 0 ==> (low <= a_len && -1 <= high < a_len)); */
    /*@ assert (a_len > 0 ==> (high == a_len - 1 || a[high + 1] >= x)); */
    /*@ assert (a_len > 0 ==> (high == a_len - 1 || a[high + 1] > x)); */
    /*@ assert (a_len > 0 ==> (high == a_len - 1 || a[high + 1] != x)); */
    /*@ assert (a_len > 0 ==> (0 <= mid < a_len)); */
    /*@ assert (a_len > 0 ==> (0 <= low <= a_len)); */
    /*@ assert (a_len > 0 ==> (0 <= low && low <= a_len)); */
    /*@ assert (a_len > 0 ==> (0 <= low && high < a_len)); */
    /*@ assert (a_len > 0 ==> (0 <= low && -1 <= high < a_len)); */
    /*@ assert (a_len > 0 ==> (-1 <= high < a_len)); */
    /*@ assert (a_len > 0 ==> (-1 <= high && high < a_len)); */
    /*@ assert (a_len == 0 || (low == 0 || a[low - 1] <= x)); */
    /*@ assert (a_len == 0 || (high == a_len - 1 || a[high + 1] >= x)); */
    /*@ assert (a_len == 0 || (0 <= low && high < a_len)); */
    /*@ assert (a_len == 0 ==> low == 0 && high == -1); */
    /*@ assert (a_len == 0 ==> high == -1); */
    /*@ assert (0 <= mid); */
    /*@ assert (0 <= mid || mid == 0); */
    /*@ assert (0 <= mid <= a_len - 1 || mid == 0); */
    /*@ assert (0 <= mid < a_len || mid == 0); */
    /*@ assert (0 <= low); */
    /*@ assert (0 <= low || low == 0); */
    /*@ assert (0 <= low && high < a_len); */
}

/*@ requires (a_len > 0 ==> low <= a_len && -1 <= high < a_len) && (a_len == 0 || (high == a_len - 1 || a[high + 1] != x)) && (mid >= 0 || mid == 0) && (mid == 0 || 0 <= mid < a_len) && (mid == 0 || (0 <= mid < a_len)) && (low >= 0 && high < a_len) && (low == 0 || a[low - 1] <= x) && (high == a_len - 1 || high + 1 >= 0) && (high == a_len - 1 || a[high + 1] >= x) && (high == a_len - 1 || a[high + 1] != x) && (high < a_len) && (high < a_len || high == -1) && (a_len > 0 ==> low >= 0 && high < a_len) && (a_len > 0 ==> low == 0 || a[low - 1] <= x) && (a_len > 0 ==> low <= high + 1) && (a_len > 0 ==> low <= a_len) && (a_len > 0 ==> low <= a_len && high >= -1) && (a_len > 0 ==> low <= a_len && high < a_len) && (a_len > 0 ==> low <= a_len && -1 <= high) && (a_len > 0 ==> high >= -1) && (a_len > 0 ==> high == a_len - 1 || a[high + 1] >= x) && (a_len > 0 ==> high == a_len - 1 || a[high + 1] > x) && (a_len > 0 ==> high == a_len - 1 || a[high + 1] != x) && (a_len > 0 ==> high < a_len) && (a_len > 0 ==> 0 <= mid < a_len) && (a_len > 0 ==> 0 <= low) && (a_len > 0 ==> 0 <= low <= a_len) && (a_len > 0 ==> 0 <= low <= a_len && -1 <= high < a_len) && (a_len > 0 ==> 0 <= low && high < a_len) && (a_len > 0 ==> 0 <= low && -1 <= high < a_len) && (a_len > 0 ==> -1 <= high < a_len) && (a_len > 0 ==> (low == 0 || a[low - 1] <= x)) && (a_len > 0 ==> (low == 0 || a[low - 1] <= x) && (high == a_len - 1 || a[high + 1] >= x)) && (a_len > 0 ==> (low <= high + 1)) && (a_len > 0 ==> (low <= a_len && high >= -1)) && (a_len > 0 ==> (low <= a_len && -1 <= high)) && (a_len > 0 ==> (low <= a_len && -1 <= high < a_len)) && (a_len > 0 ==> (high == a_len - 1 || a[high + 1] >= x)) && (a_len > 0 ==> (high == a_len - 1 || a[high + 1] > x)) && (a_len > 0 ==> (high == a_len - 1 || a[high + 1] != x)) && (a_len > 0 ==> (0 <= mid < a_len)) && (a_len > 0 ==> (0 <= low <= a_len)) && (a_len > 0 ==> (0 <= low && low <= a_len)) && (a_len > 0 ==> (0 <= low && high < a_len)) && (a_len > 0 ==> (0 <= low && -1 <= high < a_len)) && (a_len > 0 ==> (-1 <= high < a_len)) && (a_len > 0 ==> (-1 <= high && high < a_len)) && (a_len == 0 || (low == 0 || a[low - 1] <= x)) && (a_len == 0 || (high == a_len - 1 || a[high + 1] >= x)) && (a_len == 0 || (0 <= low && high < a_len)) && (a_len == 0 ==> low == 0 && high == -1) && (a_len == 0 ==> high == -1) && (0 <= mid) && (0 <= mid || mid == 0) && (0 <= mid <= a_len - 1 || mid == 0) && (0 <= mid < a_len || mid == 0) && (0 <= low) && (0 <= low || low == 0) && (0 <= low && high < a_len);
    assigns \nothing;
*/
void check_B_implies_A(int *a, int a_len, int high, int low, int mid, int x) {
    /*@ assert (0 <= low); */
    /*@ assert (high < a_len); */
    /*@ assert (0 <= mid); */
    /*@ assert (low <= high + 1); */
    /*@ assert (0 <= low && high < a_len && (low <= high + 1)); */
    /*@ assert ((((mid == 0)&&(high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= low))); */
    /*@ assert ((((mid == 0)&&(high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (high < a_len))); */
    /*@ assert ((((mid == 0)&&(high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= mid))); */
    /*@ assert ((!(0 <= \at(a_len,Pre) - 1)) ==> ((mid == 0)&&(high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre)))); */
    /*@ assert (x == \at(x,Pre)); */
    /*@ assert (a_len == \at(a_len,Pre)); */
    /*@ assert (a == \at(a,Pre)); */
}
