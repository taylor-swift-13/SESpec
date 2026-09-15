#include <limits.h>

/*@ requires (0 <= index) && ((x_len < 0) || (index <= x_len)) && ((0 < \at(x_len,Pre)) ==> (index <= \at(x_len,Pre))) && ((0 < \at(x_len,Pre)) ==> (index == 0 || \forall integer k; 0 <= k < index ==> x[k] == y[x_len - 1 - k])) && ((!(0 < \at(x_len,Pre))) ==> ((index == 0)&&(y_len == \at(y_len,Pre))&&(y == \at(y,Pre))&&(x_len == \at(x_len,Pre))&&(x == \at(x,Pre)))) && (y_len == \at(y_len,Pre)) && (y == \at(y,Pre)) && (x_len == \at(x_len,Pre)) && (x == \at(x,Pre)) && (\forall integer k; 0 <= k < x_len ==> x[k] == \at(x[k], Pre)) && (\forall integer k; 0 <= k < y_len ==> y[k] == \at(y[k], Pre));
    assigns \nothing;
*/
void check_A_implies_B(int index, int k, int *x, int x_len, int *y, int y_len) {
    /*@ assert (\forall integer k; index <= k < x_len ==> k < x_len); */
    /*@ assert (x_len == y_len); */
    /*@ assert (index == x_len || x[index] == y[x_len - 1 - index] || x[index] != y[x_len - 1 - index]); */
    /*@ assert (index == x_len || x[index] != y[x_len - 1 - index] || x[index] == y[x_len - 1 - index]); */
    /*@ assert (index == x_len ==> \forall integer k; 0 <= k < x_len ==> x[k] == y[x_len - 1 - k]); */
    /*@ assert (index == 0 || y[y_len - index] == x[index - 1]); */
    /*@ assert (index == 0 || y[y_len - 1 - (index - 1)] == x[index - 1]); */
    /*@ assert (index == 0 || y[x_len - index] == x[index - 1]); */
    /*@ assert (index == 0 || y[x_len - 1 - (index - 1)] == x[index - 1]); */
    /*@ assert (index == 0 || x[index-1] == y[x_len - index]); */
    /*@ assert (index == 0 || x[index - 1] == y[y_len - index]); */
    /*@ assert (index == 0 || x[index - 1] == y[y_len - 1 - (index - 1)]); */
    /*@ assert (index == 0 || x[index - 1] == y[x_len - index]); */
    /*@ assert (index == 0 || x[index - 1] == y[x_len - 1 - (index - 1)]); */
    /*@ assert (index == 0 || x[index - 1] != y[x_len - index] || x[index - 1] == y[x_len - index]); */
    /*@ assert (index == 0 || x[index - 1] != y[x_len - 1 - index] || x[index - 1] == y[x_len - 1 - index]); */
    /*@ assert (index <= x_len ==> x_len - 1 - index >= -1); */
    /*@ assert (index <= x_len ==> x_len - 1 - index < x_len); */
    /*@ assert (index < x_len ==> x_len - 1 - index < x_len); */
    /*@ assert (index < x_len ==> x[index] == y[x_len - 1 - index] || x[index] != y[x_len - 1 - index]); */
    /*@ assert (index < x_len ==> x[index] != y[x_len - 1 - index] || x[index] == y[x_len - 1 - index]); */
    /*@ assert (\forall integer k; index <= k < x_len ==> x[k] == x[k]); */
    /*@ assert (\forall integer k; index <= k < x_len ==> 0 <= k < x_len); */
    /*@ assert (\forall integer k; 0 <= k < index ==> y[y_len - 1 - k] == x[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> y[x_len - 1 - k] == x[k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> x[k] == y[y_len - 1 - k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> x[k] == y[x_len - 1 - k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> x[k] != y[x_len - 1 - k] || x[k] == y[x_len - 1 - k]); */
    /*@ assert (\forall integer k; 0 <= k < index ==> x[k] != y[x_len - 1 - k] ==> \false); */
    /*@ assert (0 <= index); */
}

/*@ requires (\forall integer k; index <= k < x_len ==> k < x_len) && (x_len == y_len) && (index == x_len || x[index] == y[x_len - 1 - index] || x[index] != y[x_len - 1 - index]) && (index == x_len || x[index] != y[x_len - 1 - index] || x[index] == y[x_len - 1 - index]) && (index == x_len ==> \forall integer k; 0 <= k < x_len ==> x[k] == y[x_len - 1 - k]) && (index == 0 || y[y_len - index] == x[index - 1]) && (index == 0 || y[y_len - 1 - (index - 1)] == x[index - 1]) && (index == 0 || y[x_len - index] == x[index - 1]) && (index == 0 || y[x_len - 1 - (index - 1)] == x[index - 1]) && (index == 0 || x[index-1] == y[x_len - index]) && (index == 0 || x[index - 1] == y[y_len - index]) && (index == 0 || x[index - 1] == y[y_len - 1 - (index - 1)]) && (index == 0 || x[index - 1] == y[x_len - index]) && (index == 0 || x[index - 1] == y[x_len - 1 - (index - 1)]) && (index == 0 || x[index - 1] != y[x_len - index] || x[index - 1] == y[x_len - index]) && (index == 0 || x[index - 1] != y[x_len - 1 - index] || x[index - 1] == y[x_len - 1 - index]) && (index <= x_len ==> x_len - 1 - index >= -1) && (index <= x_len ==> x_len - 1 - index < x_len) && (index < x_len ==> x_len - 1 - index < x_len) && (index < x_len ==> x[index] == y[x_len - 1 - index] || x[index] != y[x_len - 1 - index]) && (index < x_len ==> x[index] != y[x_len - 1 - index] || x[index] == y[x_len - 1 - index]) && (\forall integer k; index <= k < x_len ==> x[k] == x[k]) && (\forall integer k; index <= k < x_len ==> 0 <= k < x_len) && (\forall integer k; 0 <= k < index ==> y[y_len - 1 - k] == x[k]) && (\forall integer k; 0 <= k < index ==> y[x_len - 1 - k] == x[k]) && (\forall integer k; 0 <= k < index ==> x[k] == y[y_len - 1 - k]) && (\forall integer k; 0 <= k < index ==> x[k] == y[x_len - 1 - k]) && (\forall integer k; 0 <= k < index ==> x[k] != y[x_len - 1 - k] || x[k] == y[x_len - 1 - k]) && (\forall integer k; 0 <= k < index ==> x[k] != y[x_len - 1 - k] ==> \false) && (0 <= index);
    assigns \nothing;
*/
void check_B_implies_A(int index, int k, int *x, int x_len, int *y, int y_len) {
    /*@ assert (0 <= index); */
    /*@ assert ((x_len < 0) || (index <= x_len)); */
    /*@ assert ((0 < \at(x_len,Pre)) ==> (index <= \at(x_len,Pre))); */
    /*@ assert ((0 < \at(x_len,Pre)) ==> (index == 0 || \forall integer k; 0 <= k < index ==> x[k] == y[x_len - 1 - k])); */
    /*@ assert ((!(0 < \at(x_len,Pre))) ==> ((index == 0)&&(y_len == \at(y_len,Pre))&&(y == \at(y,Pre))&&(x_len == \at(x_len,Pre))&&(x == \at(x,Pre)))); */
    /*@ assert (y_len == \at(y_len,Pre)); */
    /*@ assert (y == \at(y,Pre)); */
    /*@ assert (x_len == \at(x_len,Pre)); */
    /*@ assert (x == \at(x,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < x_len ==> x[k] == \at(x[k], Pre)); */
    /*@ assert (\forall integer k; 0 <= k < y_len ==> y[k] == \at(y[k], Pre)); */
}
