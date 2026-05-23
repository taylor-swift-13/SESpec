#include <limits.h>

/*@ requires (0 <= i) && (j < \at(a_len,Pre)) && (a_len < 0 || i <= j + 1) && ((0 <= \at(a_len,Pre) - 1) ==> (((j == \at(a_len,Pre) - 1)&&(i == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= i <= \at(a_len,Pre)))) && ((0 <= \at(a_len,Pre) - 1) ==> (((j == \at(a_len,Pre) - 1)&&(i == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (-1 <= j < \at(a_len,Pre)))) && ((!(0 <= \at(a_len,Pre) - 1)) ==> ((j == \at(a_len,Pre) - 1)&&(i == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre)))) && (x == \at(x,Pre)) && (a_len == \at(a_len,Pre)) && (a == \at(a,Pre)) && (\forall integer k);
    assigns \nothing;
*/
void check_A_implies_B(int *a, int *a_len, int *i, int *j, int k, int *x) {
    /*@ assert (j == a_len - 1 || a[j+1] >= x) && (j == a_len - 1 || a[j+1] > x) && (j < a_len) && (i == 0 || a[i-1] <= x) && (i == 0 || a[i-1] < x) && (0 <= i); */
}

/*@ requires (j == a_len - 1 || a[j+1] >= x) && (j == a_len - 1 || a[j+1] > x) && (j < a_len) && (i == 0 || a[i-1] <= x) && (i == 0 || a[i-1] < x) && (0 <= i);
    assigns \nothing;
*/
void check_B_implies_A(int *a, int *a_len, int *i, int *j, int k, int *x) {
    /*@ assert (0 <= i) && (j < \at(a_len,Pre)) && (a_len < 0 || i <= j + 1) && ((0 <= \at(a_len,Pre) - 1) ==> (((j == \at(a_len,Pre) - 1)&&(i == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= i <= \at(a_len,Pre)))) && ((0 <= \at(a_len,Pre) - 1) ==> (((j == \at(a_len,Pre) - 1)&&(i == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (-1 <= j < \at(a_len,Pre)))) && ((!(0 <= \at(a_len,Pre) - 1)) ==> ((j == \at(a_len,Pre) - 1)&&(i == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre)))) && (x == \at(x,Pre)) && (a_len == \at(a_len,Pre)) && (a == \at(a,Pre)) && (\forall integer k); */
}
