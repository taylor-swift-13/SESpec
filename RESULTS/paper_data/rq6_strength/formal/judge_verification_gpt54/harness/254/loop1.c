#include <limits.h>

/*@ logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0); */

/*@ requires ((\at(start,Pre) <= \at(end,Pre)) ==> (start <= min)) && ((\at(start,Pre) <= \at(end,Pre)) ==> (max <= end)) && ((\at(start,Pre) <= \at(end,Pre)) ==> (min <= max + 1)) && ((\at(start,Pre) <= \at(end,Pre)) ==> (min <= \at(end,Pre) + 1)) && ((\at(start,Pre) <= \at(end,Pre)) ==> (\at(start,Pre) - 1 <= max)) && ((!(\at(start,Pre) <= \at(end,Pre))) ==> ((max == \at(end,Pre))&&(min == \at(start,Pre))&&(end == \at(end,Pre))&&(start == \at(start,Pre))&&(array_len == \at(array_len,Pre))&&(array == \at(array,Pre)))) && (end == \at(end,Pre)) && (start == \at(start,Pre)) && (array_len == \at(array_len,Pre)) && (array == \at(array,Pre)) && (\forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k],Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *array, int array_len, int end, int k, int start) {
    /*@ assert (start <= min); */
    /*@ assert (min == start || array[min - 1] < min); */
    /*@ assert (max == end || array[max + 1] > max); */
    /*@ assert (max <= end); */
}

/*@ requires (start <= min) && (min == start || array[min - 1] < min) && (max == end || array[max + 1] > max) && (max <= end);
    assigns \nothing;
*/
void check_B_implies_A(int *array, int array_len, int end, int k, int start) {
    /*@ assert ((\at(start,Pre) <= \at(end,Pre)) ==> (start <= min)); */
    /*@ assert ((\at(start,Pre) <= \at(end,Pre)) ==> (max <= end)); */
    /*@ assert ((\at(start,Pre) <= \at(end,Pre)) ==> (min <= max + 1)); */
    /*@ assert ((\at(start,Pre) <= \at(end,Pre)) ==> (min <= \at(end,Pre) + 1)); */
    /*@ assert ((\at(start,Pre) <= \at(end,Pre)) ==> (\at(start,Pre) - 1 <= max)); */
    /*@ assert ((!(\at(start,Pre) <= \at(end,Pre))) ==> ((max == \at(end,Pre))&&(min == \at(start,Pre))&&(end == \at(end,Pre))&&(start == \at(start,Pre))&&(array_len == \at(array_len,Pre))&&(array == \at(array,Pre)))); */
    /*@ assert (end == \at(end,Pre)); */
    /*@ assert (start == \at(start,Pre)); */
    /*@ assert (array_len == \at(array_len,Pre)); */
    /*@ assert (array == \at(array,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k],Pre)); */
}
