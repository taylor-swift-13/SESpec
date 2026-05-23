#include <limits.h>

/*@ requires (0 <= left <= a_len) && (-1 <= right < a_len) && (left <= right + 1) && ((0 <= \at(a_len,Pre) - 1) ==> ((left == 0 && right == \at(a_len,Pre) - 1 && x == \at(x,Pre) && a_len == \at(a_len,Pre) && a == \at(a,Pre)) || (0 <= left <= a_len))) && ((0 <= \at(a_len,Pre) - 1) ==> ((left == 0 && right == \at(a_len,Pre) - 1 && x == \at(x,Pre) && a_len == \at(a_len,Pre) && a == \at(a,Pre)) || (-1 <= right < a_len))) && ((!(0 <= \at(a_len,Pre) - 1)) ==> (right == \at(a_len,Pre) - 1 && left == 0 && x == \at(x,Pre) && a_len == \at(a_len,Pre) && a == \at(a,Pre))) && (x == \at(x,Pre)) && (a_len == \at(a_len,Pre)) && (a == \at(a,Pre)) && (\forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k],Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *a, int a_len, int k, int left, int right, int x) {
    /*@ assert (right == a_len - 1 || a[right+1] >= x); */
    /*@ assert (right == a_len - 1 || a[right+1] > x); */
    /*@ assert (right == a_len - 1 || a[right + 1] >= x); */
    /*@ assert (right == a_len - 1 || a[right + 1] > x); */
    /*@ assert (right < a_len); */
    /*@ assert (right < a_len ==> a[right] >= x || a[right] < x); */
    /*@ assert (right < a_len ==> a[right] <= x || a[right] > x); */
    /*@ assert (right < a_len ==> a[right] < x || a[right] >= x); */
    /*@ assert (right + 1 <= a_len); */
    /*@ assert (left > 0 ==> a[left-1] <= x); */
    /*@ assert (left == 0 || a[left-1] <= x); */
    /*@ assert (left == 0 || a[left-1] < x); */
    /*@ assert (left == 0 || a[left - 1] <= x); */
    /*@ assert (left == 0 || a[left - 1] < x); */
    /*@ assert (0 <= left); */
    /*@ assert (0 <= left || right < a_len); */
    /*@ assert (0 <= left + (a_len - 1 - right)); */
}

/*@ requires (right == a_len - 1 || a[right+1] >= x) && (right == a_len - 1 || a[right+1] > x) && (right == a_len - 1 || a[right + 1] >= x) && (right == a_len - 1 || a[right + 1] > x) && (right < a_len) && (right < a_len ==> a[right] >= x || a[right] < x) && (right < a_len ==> a[right] <= x || a[right] > x) && (right < a_len ==> a[right] < x || a[right] >= x) && (right + 1 <= a_len) && (left > 0 ==> a[left-1] <= x) && (left == 0 || a[left-1] <= x) && (left == 0 || a[left-1] < x) && (left == 0 || a[left - 1] <= x) && (left == 0 || a[left - 1] < x) && (0 <= left) && (0 <= left || right < a_len) && (0 <= left + (a_len - 1 - right));
    assigns \nothing;
*/
void check_B_implies_A(int *a, int a_len, int k, int left, int right, int x) {
    /*@ assert (0 <= left <= a_len); */
    /*@ assert (-1 <= right < a_len); */
    /*@ assert (left <= right + 1); */
    /*@ assert ((0 <= \at(a_len,Pre) - 1) ==> ((left == 0 && right == \at(a_len,Pre) - 1 && x == \at(x,Pre) && a_len == \at(a_len,Pre) && a == \at(a,Pre)) || (0 <= left <= a_len))); */
    /*@ assert ((0 <= \at(a_len,Pre) - 1) ==> ((left == 0 && right == \at(a_len,Pre) - 1 && x == \at(x,Pre) && a_len == \at(a_len,Pre) && a == \at(a,Pre)) || (-1 <= right < a_len))); */
    /*@ assert ((!(0 <= \at(a_len,Pre) - 1)) ==> (right == \at(a_len,Pre) - 1 && left == 0 && x == \at(x,Pre) && a_len == \at(a_len,Pre) && a == \at(a,Pre))); */
    /*@ assert (x == \at(x,Pre)); */
    /*@ assert (a_len == \at(a_len,Pre)); */
    /*@ assert (a == \at(a,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k],Pre)); */
}
