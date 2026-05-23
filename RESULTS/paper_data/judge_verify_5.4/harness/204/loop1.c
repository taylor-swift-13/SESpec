#include <limits.h>

/*@ predicate ints_unchanged{L1,L2}(int* ints, integer n) =
    \forall integer k; */

/*@ requires (0 <= find <= offset) && (0 <= find <= max) && (offset <= array) && (1 <= max <= array) && (offset + max - 2 * find >= 1) && (find <= offset && find <= max) && ((0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (find <= offset && find <= max && offset <= array && max <= array)) && ((0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (find >= 0)) && ((0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (offset >= 0 && max >= 0)) && ((!(0 < \at(array,Pre) && 1 < \at(array,Pre))) ==> ((max == 1)&&(offset == 0)&&(find == 0)&&(array == \at(array,Pre))&&(ints_len == \at(ints_len,Pre))&&(ints == \at(ints,Pre)))) && (array == \at(array,Pre)) && (ints_len == \at(ints_len,Pre)) && (ints == \at(ints,Pre)) && (\forall integer k; 0 <= k < ints_len ==> ints[k] == \at(ints[k],Pre));
    assigns \nothing;
*/
void check_A_implies_B(int array, int *find, int *ints, int ints_len, int k) {
    /*@ assert (offset < array ==> max <= array); */
    /*@ assert (offset <= max); */
    /*@ assert (offset <= max || max <= array); */
    /*@ assert (offset <= max + find); */
    /*@ assert (offset <= max + 1); */
    /*@ assert (offset <= array || max - offset <= 1); */
    /*@ assert (offset <= array || max - 1 <= offset + find); */
    /*@ assert (offset <= array || find <= offset + max); */
    /*@ assert (offset <= array || 1 <= max - offset); */
    /*@ assert (offset <= array ==> 0 <= max - offset); */
    /*@ assert (offset + find <= max + array || max - offset <= 1); */
    /*@ assert (offset + find <= max + array || max - 1 <= offset + find); */
    /*@ assert (offset + find <= max + array || find <= offset + max); */
    /*@ assert (offset + find <= max + array || 1 <= max - offset); */
    /*@ assert (max <= array || max - offset <= 1); */
    /*@ assert (max <= array || find <= offset + max); */
    /*@ assert (max <= array || find < offset + max); */
    /*@ assert (max <= array || 1 <= max - offset); */
    /*@ assert (max <= array ==> find <= max); */
    /*@ assert (max - offset == 1 || max - offset >= 0); */
    /*@ assert (max - offset <= array || 1 <= max - offset); */
    /*@ assert (max - offset <= 1 || max - offset <= array); */
    /*@ assert (max - offset <= 1 || 1 <= max - offset); */
    /*@ assert (max - 1 <= offset + find || max <= array); */
    /*@ assert (find <= offset); */
    /*@ assert (find <= offset + max); */
    /*@ assert (find <= offset + max || max <= array); */
    /*@ assert (find <= offset + max || max - 1 <= offset + find); */
    /*@ assert (find <= offset + max || find + offset <= max + array); */
    /*@ assert (find <= max); */
    /*@ assert (find <= max - 1); */
    /*@ assert (find <= array || max - offset <= 1); */
    /*@ assert (find <= array || 1 <= max - offset); */
    /*@ assert (find < offset + max); */
    /*@ assert (find + offset <= max + array || max - offset <= 1); */
    /*@ assert (find + offset <= max + array || max - 1 <= offset + find); */
    /*@ assert (find + offset <= max + array || 1 <= max - offset); */
    /*@ assert (find + offset <= max + array || 0 <= max - find); */
    /*@ assert (find + 1 <= max); */
    /*@ assert (find + 1 <= max || find == 0); */
    /*@ assert (1 <= max); */
    /*@ assert (1 <= max - find); */
    /*@ assert (1 <= max - find || offset <= array); */
    /*@ assert (1 <= max - find || offset + find <= max + array); */
    /*@ assert (1 <= max - find || max <= array); */
    /*@ assert (1 <= max - find || max - 1 <= offset + find); */
    /*@ assert (1 <= max - find || find <= offset + max); */
    /*@ assert (1 <= max - find || find + offset <= max + array); */
    /*@ assert (1 <= max - find || 0 <= max - offset); */
    /*@ assert (0 <= offset); */
    /*@ assert (0 <= max); */
    /*@ assert (0 <= max - offset); */
    /*@ assert (0 <= max - offset || offset <= array); */
    /*@ assert (0 <= max - offset || offset + find <= max + array); */
    /*@ assert (0 <= max - offset || max <= array); */
    /*@ assert (0 <= max - offset || max - 1 <= offset + find); */
    /*@ assert (0 <= max - offset || find <= offset + max); */
    /*@ assert (0 <= max - offset || find + offset <= max + array); */
    /*@ assert (0 <= max - find); */
    /*@ assert (0 <= max - find || offset <= array); */
    /*@ assert (0 <= max - find || offset + find <= max + array); */
    /*@ assert (0 <= max - find || max <= array); */
    /*@ assert (0 <= max - find || max - offset <= array); */
    /*@ assert (0 <= max - find || max - offset <= 1); */
    /*@ assert (0 <= max - find || find <= array); */
    /*@ assert (0 <= max - find || 1 <= max - offset); */
    /*@ assert (0 <= find); */
    /*@ assert (0 < max - find); */
    /*@ assert (-1 <= max - offset); */
    /*@ assert (-1 <= max - offset || offset <= array); */
    /*@ assert (-1 <= max - offset || offset + find <= max + array); */
    /*@ assert (-1 <= max - offset || max <= array); */
    /*@ assert (-1 <= max - offset || max - offset <= array); */
    /*@ assert (-1 <= max - offset || max - offset <= 1); */
    /*@ assert (-1 <= max - offset || find <= array); */
    /*@ assert (-1 <= max - offset || find + offset <= max + array); */
    /*@ assert (-1 <= max - offset || 1 <= max - offset); */
    /*@ assert (-1 <= max - offset || 0 <= max - find); */
    /*@ assert (-1 < max - offset); */
}

/*@ requires (offset < array ==> max <= array) && (offset <= max) && (offset <= max || max <= array) && (offset <= max + find) && (offset <= max + 1) && (offset <= array || max - offset <= 1) && (offset <= array || max - 1 <= offset + find) && (offset <= array || find <= offset + max) && (offset <= array || 1 <= max - offset) && (offset <= array ==> 0 <= max - offset) && (offset + find <= max + array || max - offset <= 1) && (offset + find <= max + array || max - 1 <= offset + find) && (offset + find <= max + array || find <= offset + max) && (offset + find <= max + array || 1 <= max - offset) && (max <= array || max - offset <= 1) && (max <= array || find <= offset + max) && (max <= array || find < offset + max) && (max <= array || 1 <= max - offset) && (max <= array ==> find <= max) && (max - offset == 1 || max - offset >= 0) && (max - offset <= array || 1 <= max - offset) && (max - offset <= 1 || max - offset <= array) && (max - offset <= 1 || 1 <= max - offset) && (max - 1 <= offset + find || max <= array) && (find <= offset) && (find <= offset + max) && (find <= offset + max || max <= array) && (find <= offset + max || max - 1 <= offset + find) && (find <= offset + max || find + offset <= max + array) && (find <= max) && (find <= max - 1) && (find <= array || max - offset <= 1) && (find <= array || 1 <= max - offset) && (find < offset + max) && (find + offset <= max + array || max - offset <= 1) && (find + offset <= max + array || max - 1 <= offset + find) && (find + offset <= max + array || 1 <= max - offset) && (find + offset <= max + array || 0 <= max - find) && (find + 1 <= max) && (find + 1 <= max || find == 0) && (1 <= max) && (1 <= max - find) && (1 <= max - find || offset <= array) && (1 <= max - find || offset + find <= max + array) && (1 <= max - find || max <= array) && (1 <= max - find || max - 1 <= offset + find) && (1 <= max - find || find <= offset + max) && (1 <= max - find || find + offset <= max + array) && (1 <= max - find || 0 <= max - offset) && (0 <= offset) && (0 <= max) && (0 <= max - offset) && (0 <= max - offset || offset <= array) && (0 <= max - offset || offset + find <= max + array) && (0 <= max - offset || max <= array) && (0 <= max - offset || max - 1 <= offset + find) && (0 <= max - offset || find <= offset + max) && (0 <= max - offset || find + offset <= max + array) && (0 <= max - find) && (0 <= max - find || offset <= array) && (0 <= max - find || offset + find <= max + array) && (0 <= max - find || max <= array) && (0 <= max - find || max - offset <= array) && (0 <= max - find || max - offset <= 1) && (0 <= max - find || find <= array) && (0 <= max - find || 1 <= max - offset) && (0 <= find) && (0 < max - find) && (-1 <= max - offset) && (-1 <= max - offset || offset <= array) && (-1 <= max - offset || offset + find <= max + array) && (-1 <= max - offset || max <= array) && (-1 <= max - offset || max - offset <= array) && (-1 <= max - offset || max - offset <= 1) && (-1 <= max - offset || find <= array) && (-1 <= max - offset || find + offset <= max + array) && (-1 <= max - offset || 1 <= max - offset) && (-1 <= max - offset || 0 <= max - find) && (-1 < max - offset);
    assigns \nothing;
*/
void check_B_implies_A(int array, int *find, int *ints, int ints_len, int k) {
    /*@ assert (0 <= find <= offset); */
    /*@ assert (0 <= find <= max); */
    /*@ assert (offset <= array); */
    /*@ assert (1 <= max <= array); */
    /*@ assert (offset + max - 2 * find >= 1); */
    /*@ assert (find <= offset && find <= max); */
    /*@ assert ((0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (find <= offset && find <= max && offset <= array && max <= array)); */
    /*@ assert ((0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (find >= 0)); */
    /*@ assert ((0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (offset >= 0 && max >= 0)); */
    /*@ assert ((!(0 < \at(array,Pre) && 1 < \at(array,Pre))) ==> ((max == 1)&&(offset == 0)&&(find == 0)&&(array == \at(array,Pre))&&(ints_len == \at(ints_len,Pre))&&(ints == \at(ints,Pre)))); */
    /*@ assert (array == \at(array,Pre)); */
    /*@ assert (ints_len == \at(ints_len,Pre)); */
    /*@ assert (ints == \at(ints,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < ints_len ==> ints[k] == \at(ints[k],Pre)); */
}
