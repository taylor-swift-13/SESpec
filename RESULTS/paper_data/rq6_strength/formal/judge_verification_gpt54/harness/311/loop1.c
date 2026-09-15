#include <limits.h>

/*@ requires (1 <= index <= 2 * count + 1) && (result >= 0) && (diameter == 2 * count) && (center == diameter * diameter) && (count == \at(count,Pre)) && (result <= (index - 1) * (2 * count));
    assigns \nothing;
*/
void check_A_implies_B(int center, int *count, int *diameter, int i, int i0, int index, int j, int k, int t) {
    /*@ assert (result == 0 || result > 0); */
    /*@ assert (diameter == 2 * count); */
    /*@ assert (center == diameter * diameter); */
    /*@ assert (center == 4 * count * count); */
    /*@ assert (center == (2 * count) * (2 * count)); */
    /*@ assert (\forall integer t; 1 <= t < index ==> t <= 2 * count + 1); */
    /*@ assert (\forall integer t; 1 <= t < index ==> result >= 0); */
    /*@ assert (\forall integer t; 1 <= t < index ==> 0 <= result); */
    /*@ assert (\forall integer k; 1 <= k < index ==> result >= 0); */
    /*@ assert (\forall integer k; 1 <= k < index ==> k <= 2 * count + 1); */
    /*@ assert (\forall integer k; 1 <= k < index ==> 1 <= k <= 2 * count + 1); */
    /*@ assert (\forall integer k; 1 <= k < index ==> 0 <= result); */
    /*@ assert (\forall integer j; 1 <= j < index ==> result >= 0); */
    /*@ assert (\forall integer j; 1 <= j < index ==> j <= 2 * count + 1); */
    /*@ assert (\forall integer j; 1 <= j < index ==> 0 <= result); */
    /*@ assert (\forall integer j; 0 <= j < index ==> result >= 0); */
    /*@ assert (\forall integer i; 1 <= i <= 2 * count ==> i <= 2 * count + 1); */
    /*@ assert (\forall integer i; 1 <= i < index ==> result >= 0); */
    /*@ assert (\forall integer i; 1 <= i < index ==> i <= 2 * count + 1); */
    /*@ assert (\forall integer i; 1 <= i < index ==> 1 <= i <= 2 * count + 1); */
    /*@ assert (\forall integer i; 1 <= i < index ==> 0 <= result); */
    /*@ assert (\forall integer i0; 1 <= i0 < index ==> i0 <= 2 * count + 1); */
    /*@ assert (\forall integer i0; 1 <= i0 < index ==> 0 <= result); */
    /*@ assert (1 <= index); */
    /*@ assert (0 <= result); */
    /*@ assert (0 <= index); */
    /*@ assert (0 <= center); */
}

/*@ requires (result == 0 || result > 0) && (diameter == 2 * count) && (center == diameter * diameter) && (center == 4 * count * count) && (center == (2 * count) * (2 * count)) && (\forall integer t; 1 <= t < index ==> t <= 2 * count + 1) && (\forall integer t; 1 <= t < index ==> result >= 0) && (\forall integer t; 1 <= t < index ==> 0 <= result) && (\forall integer k; 1 <= k < index ==> result >= 0) && (\forall integer k; 1 <= k < index ==> k <= 2 * count + 1) && (\forall integer k; 1 <= k < index ==> 1 <= k <= 2 * count + 1) && (\forall integer k; 1 <= k < index ==> 0 <= result) && (\forall integer j; 1 <= j < index ==> result >= 0) && (\forall integer j; 1 <= j < index ==> j <= 2 * count + 1) && (\forall integer j; 1 <= j < index ==> 0 <= result) && (\forall integer j; 0 <= j < index ==> result >= 0) && (\forall integer i; 1 <= i <= 2 * count ==> i <= 2 * count + 1) && (\forall integer i; 1 <= i < index ==> result >= 0) && (\forall integer i; 1 <= i < index ==> i <= 2 * count + 1) && (\forall integer i; 1 <= i < index ==> 1 <= i <= 2 * count + 1) && (\forall integer i; 1 <= i < index ==> 0 <= result) && (\forall integer i0; 1 <= i0 < index ==> i0 <= 2 * count + 1) && (\forall integer i0; 1 <= i0 < index ==> 0 <= result) && (1 <= index) && (0 <= result) && (0 <= index) && (0 <= center);
    assigns \nothing;
*/
void check_B_implies_A(int center, int *count, int *diameter, int i, int i0, int index, int j, int k, int t) {
    /*@ assert (1 <= index <= 2 * count + 1); */
    /*@ assert (result >= 0); */
    /*@ assert (diameter == 2 * count); */
    /*@ assert (center == diameter * diameter); */
    /*@ assert (count == \at(count,Pre)); */
    /*@ assert (result <= (index - 1) * (2 * count)); */
}
