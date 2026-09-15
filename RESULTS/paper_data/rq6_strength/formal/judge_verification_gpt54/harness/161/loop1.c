#include <limits.h>

/*@ requires (array == \at(array,Pre)) && (positions_len == \at(positions_len,Pre)) && (positions == \at(positions,Pre)) && (0 <= ret) && ((0 < \at(array,Pre)) ==> (ret <= \at(array,Pre))) && ((0 < \at(array,Pre)) ==> (ret >= 0)) && ((0 < \at(array,Pre)) ==> (ret == 0 || ret > 0)) && ((!(0 < \at(array,Pre))) ==> ((ret == 0)&&(array == \at(array,Pre))&&(positions_len == \at(positions_len,Pre))&&(positions == \at(positions,Pre))));
    assigns \nothing;
*/
void check_A_implies_B(int array, int k, int *positions, int positions_len, int ret) {
    /*@ assert (ret == array || positions[ret] == ret + 1 || positions[ret] != ret + 1); */
    /*@ assert (\forall integer k; ret <= k < array ==> positions[k] == positions[k]); */
    /*@ assert (\forall integer k; ret <= k < array ==> positions[k] != k + 1 || positions[k] == k + 1); */
    /*@ assert (\forall integer k; ret <= k < array ==> positions[k] != k + 1 ==> positions[k] == positions[k]); */
    /*@ assert (\forall integer k; ret <= k < array ==> positions[k] != k + 1 ==> positions[k] <= 0 || positions[k] > array || positions[k] == positions[k]); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> positions[k] == positions[k]); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> positions[k] == k + 1 || positions[k] <= 0 || positions[k] > array); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> positions[k] == k + 1 ==> positions[k] > 0); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> positions[k] <= 0 || positions[k] > array || positions[k] == k + 1); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> positions[k] != k + 1 ==> positions[k] <= 0 || positions[k] > array); */
    /*@ assert (\forall integer k; 0 <= k < positions_len ==> positions[k] == positions[k]); */
    /*@ assert (\forall integer k; 0 <= k < array ==> positions[k] == positions[k]); */
    /*@ assert (\exists integer k; 0 <= k < ret ==> positions[k] == k + 1); */
    /*@ assert (\exists integer k; 0 <= k < ret && positions[k] != k + 1 ==> ret <= array); */
    /*@ assert (\exists integer k; 0 <= k < array && positions[k] != k + 1 ==> ret <= k); */
    /*@ assert (0 <= ret); */
}

/*@ requires (ret == array || positions[ret] == ret + 1 || positions[ret] != ret + 1) && (\forall integer k; ret <= k < array ==> positions[k] == positions[k]) && (\forall integer k; ret <= k < array ==> positions[k] != k + 1 || positions[k] == k + 1) && (\forall integer k; ret <= k < array ==> positions[k] != k + 1 ==> positions[k] == positions[k]) && (\forall integer k; ret <= k < array ==> positions[k] != k + 1 ==> positions[k] <= 0 || positions[k] > array || positions[k] == positions[k]) && (\forall integer k; 0 <= k < ret ==> positions[k] == positions[k]) && (\forall integer k; 0 <= k < ret ==> positions[k] == k + 1 || positions[k] <= 0 || positions[k] > array) && (\forall integer k; 0 <= k < ret ==> positions[k] == k + 1 ==> positions[k] > 0) && (\forall integer k; 0 <= k < ret ==> positions[k] <= 0 || positions[k] > array || positions[k] == k + 1) && (\forall integer k; 0 <= k < ret ==> positions[k] != k + 1 ==> positions[k] <= 0 || positions[k] > array) && (\forall integer k; 0 <= k < positions_len ==> positions[k] == positions[k]) && (\forall integer k; 0 <= k < array ==> positions[k] == positions[k]) && (\exists integer k; 0 <= k < ret ==> positions[k] == k + 1) && (\exists integer k; 0 <= k < ret && positions[k] != k + 1 ==> ret <= array) && (\exists integer k; 0 <= k < array && positions[k] != k + 1 ==> ret <= k) && (0 <= ret);
    assigns \nothing;
*/
void check_B_implies_A(int array, int k, int *positions, int positions_len, int ret) {
    /*@ assert (array == \at(array,Pre)); */
    /*@ assert (positions_len == \at(positions_len,Pre)); */
    /*@ assert (positions == \at(positions,Pre)); */
    /*@ assert (0 <= ret); */
    /*@ assert ((0 < \at(array,Pre)) ==> (ret <= \at(array,Pre))); */
    /*@ assert ((0 < \at(array,Pre)) ==> (ret >= 0)); */
    /*@ assert ((0 < \at(array,Pre)) ==> (ret == 0 || ret > 0)); */
    /*@ assert ((!(0 < \at(array,Pre))) ==> ((ret == 0)&&(array == \at(array,Pre))&&(positions_len == \at(positions_len,Pre))&&(positions == \at(positions,Pre)))); */
}
