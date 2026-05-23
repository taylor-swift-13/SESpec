#include <limits.h>

/*@ logic integer lower_bound(int *a, integer lo, integer hi, integer v) =
    lo > hi ? lo
            : (a[(lo + hi) / 2] < v
               ? lower_bound(a, (lo + hi) / 2 + 1, hi, v)
               : lower_bound(a, lo, (lo + hi) / 2 - 1, v)); */
/*@ logic integer upper_bound(int *a, integer lo, integer hi, integer v) =
    lo > hi ? hi
            : (a[(lo + hi) / 2] > v
               ? upper_bound(a, lo, (lo + hi) / 2 - 1, v)
               : upper_bound(a, (lo + hi) / 2 + 1, hi, v)); */
/*@ predicate all_less(int *a, integer lo, integer hi, integer v) =
    \forall integer k; */
/*@ predicate all_greater(int *a, integer lo, integer hi, integer v) =
    \forall integer k; */

/*@ requires ((0 <= \at(sortedArray_len,Pre) - 1) ==> (((hi == \at(sortedArray_len,Pre) - 1)&&(lo == 0)&&(value == \at(value,Pre))&&(sortedArray_len == \at(sortedArray_len,Pre))&&(sortedArray == \at(sortedArray,Pre))) || (0 <= lo <= hi + 1 <= sortedArray_len))) && ((0 <= \at(sortedArray_len,Pre) - 1) ==> (((hi == \at(sortedArray_len,Pre) - 1)&&(lo == 0)&&(value == \at(value,Pre))&&(sortedArray_len == \at(sortedArray_len,Pre))&&(sortedArray == \at(sortedArray,Pre))) || (0 <= hi < sortedArray_len))) && ((!(0 <= \at(sortedArray_len,Pre) - 1)) ==> ((hi == \at(sortedArray_len,Pre) - 1)&&(lo == 0)&&(value == \at(value,Pre))&&(sortedArray_len == \at(sortedArray_len,Pre))&&(sortedArray == \at(sortedArray,Pre)))) && (value == \at(value,Pre)) && (sortedArray_len == \at(sortedArray_len,Pre)) && (sortedArray == \at(sortedArray,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int hi, int lo, int *sortedArray, int sortedArray_len, int value) {
    /*@ assert (lo == 0 || sortedArray[lo-1] <= value); */
    /*@ assert (lo == 0 || sortedArray[lo-1] < value); */
    /*@ assert (hi == sortedArray_len-1 || value <= sortedArray[hi+1]); */
    /*@ assert (hi == sortedArray_len-1 || value < sortedArray[hi+1]); */
    /*@ assert (hi == sortedArray_len-1 || sortedArray[hi+1] > value); */
    /*@ assert (hi < sortedArray_len); */
    /*@ assert (hi + 1 <= sortedArray_len); */
    /*@ assert (0 <= lo); */
    /*@ assert (0 <= lo || lo == hi + 1); */
}

/*@ requires (lo == 0 || sortedArray[lo-1] <= value) && (lo == 0 || sortedArray[lo-1] < value) && (hi == sortedArray_len-1 || value <= sortedArray[hi+1]) && (hi == sortedArray_len-1 || value < sortedArray[hi+1]) && (hi == sortedArray_len-1 || sortedArray[hi+1] > value) && (hi < sortedArray_len) && (hi + 1 <= sortedArray_len) && (0 <= lo) && (0 <= lo || lo == hi + 1);
    assigns \nothing;
*/
void check_B_implies_A(int hi, int lo, int *sortedArray, int sortedArray_len, int value) {
    /*@ assert ((0 <= \at(sortedArray_len,Pre) - 1) ==> (((hi == \at(sortedArray_len,Pre) - 1)&&(lo == 0)&&(value == \at(value,Pre))&&(sortedArray_len == \at(sortedArray_len,Pre))&&(sortedArray == \at(sortedArray,Pre))) || (0 <= lo <= hi + 1 <= sortedArray_len))); */
    /*@ assert ((0 <= \at(sortedArray_len,Pre) - 1) ==> (((hi == \at(sortedArray_len,Pre) - 1)&&(lo == 0)&&(value == \at(value,Pre))&&(sortedArray_len == \at(sortedArray_len,Pre))&&(sortedArray == \at(sortedArray,Pre))) || (0 <= hi < sortedArray_len))); */
    /*@ assert ((!(0 <= \at(sortedArray_len,Pre) - 1)) ==> ((hi == \at(sortedArray_len,Pre) - 1)&&(lo == 0)&&(value == \at(value,Pre))&&(sortedArray_len == \at(sortedArray_len,Pre))&&(sortedArray == \at(sortedArray,Pre)))); */
    /*@ assert (value == \at(value,Pre)); */
    /*@ assert (sortedArray_len == \at(sortedArray_len,Pre)); */
    /*@ assert (sortedArray == \at(sortedArray,Pre)); */
}
