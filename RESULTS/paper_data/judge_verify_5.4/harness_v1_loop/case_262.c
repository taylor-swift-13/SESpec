#include <limits.h>

/*@ requires (0 <= left <= a_len) && (-1 <= right < a_len) && (left <= right + 1) && ((0 <= \at(a_len,Pre) - 1) ==> ((left == 0 && right == \at(a_len,Pre) - 1 && x == \at(x,Pre) && a_len == \at(a_len,Pre) && a == \at(a,Pre)) || (0 <= left <= a_len))) && ((0 <= \at(a_len,Pre) - 1) ==> ((left == 0 && right == \at(a_len,Pre) - 1 && x == \at(x,Pre) && a_len == \at(a_len,Pre) && a == \at(a,Pre)) || (-1 <= right < a_len))) && ((!(0 <= \at(a_len,Pre) - 1)) ==> (right == \at(a_len,Pre) - 1 && left == 0 && x == \at(x,Pre) && a_len == \at(a_len,Pre) && a == \at(a,Pre))) && (x == \at(x,Pre)) && (a_len == \at(a_len,Pre)) && (a == \at(a,Pre)) && (\forall integer k);
    assigns \nothing;
*/
void check_A_implies_B(int *a, int *a_len, int k, int *left, int *right, int *x) {
    /*@ assert (right == a_len - 1 || a[right+1] >= x) && (right == a_len - 1 || a[right+1] > x) && (right == a_len - 1 || a[right + 1] >= x) && (right == a_len - 1 || a[right + 1] > x) && (right < a_len) && (right < a_len ==> a[right] >= x || a[right] < x) && (right < a_len ==> a[right] <= x || a[right] > x) && (right < a_len ==> a[right] < x || a[right] >= x) && (right + 1 <= a_len) && (left > 0 ==> a[left-1] <= x) && (left == 0 || a[left-1] <= x) && (left == 0 || a[left-1] < x) && (left == 0 || a[left - 1] <= x) && (left == 0 || a[left - 1] < x) && (0 <= left) && (0 <= left || right < a_len) && (0 <= left + (a_len - 1 - right)); */
}

/*@ requires (right == a_len - 1 || a[right+1] >= x) && (right == a_len - 1 || a[right+1] > x) && (right == a_len - 1 || a[right + 1] >= x) && (right == a_len - 1 || a[right + 1] > x) && (right < a_len) && (right < a_len ==> a[right] >= x || a[right] < x) && (right < a_len ==> a[right] <= x || a[right] > x) && (right < a_len ==> a[right] < x || a[right] >= x) && (right + 1 <= a_len) && (left > 0 ==> a[left-1] <= x) && (left == 0 || a[left-1] <= x) && (left == 0 || a[left-1] < x) && (left == 0 || a[left - 1] <= x) && (left == 0 || a[left - 1] < x) && (0 <= left) && (0 <= left || right < a_len) && (0 <= left + (a_len - 1 - right));
    assigns \nothing;
*/
void check_B_implies_A(int *a, int *a_len, int k, int *left, int *right, int *x) {
    /*@ assert (0 <= left <= a_len) && (-1 <= right < a_len) && (left <= right + 1) && ((0 <= \at(a_len,Pre) - 1) ==> ((left == 0 && right == \at(a_len,Pre) - 1 && x == \at(x,Pre) && a_len == \at(a_len,Pre) && a == \at(a,Pre)) || (0 <= left <= a_len))) && ((0 <= \at(a_len,Pre) - 1) ==> ((left == 0 && right == \at(a_len,Pre) - 1 && x == \at(x,Pre) && a_len == \at(a_len,Pre) && a == \at(a,Pre)) || (-1 <= right < a_len))) && ((!(0 <= \at(a_len,Pre) - 1)) ==> (right == \at(a_len,Pre) - 1 && left == 0 && x == \at(x,Pre) && a_len == \at(a_len,Pre) && a == \at(a,Pre))) && (x == \at(x,Pre)) && (a_len == \at(a_len,Pre)) && (a == \at(a,Pre)) && (\forall integer k); */
}
