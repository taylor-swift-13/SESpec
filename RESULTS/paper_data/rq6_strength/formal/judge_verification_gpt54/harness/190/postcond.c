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

/*@ requires \valid(&sortedArray[0] + (0..sortedArray_len-1));
  requires \forall integer i; 0 <= i < sortedArray_len ==> 0 <= sortedArray[i] <= 100;
  requires sortedArray_len > 0;
  requires sortedArray_len < 100;
  assigns \nothing;
  ensures \result == -1 ||
          (0 <= \result < sortedArray_len && sortedArray[\result] == value); */
int stub_A(int * sortedArray, int sortedArray_len, int value);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * sortedArray, int sortedArray_len, int value);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * sortedArray, int sortedArray_len, int value) {
    return stub_A(sortedArray, sortedArray_len, value);
}

/*@ requires \valid(&sortedArray[0] + (0..sortedArray_len-1));
  requires \forall integer i; 0 <= i < sortedArray_len ==> 0 <= sortedArray[i] <= 100;
  requires sortedArray_len > 0;
  requires sortedArray_len < 100;
  assigns \nothing;
  ensures \result == -1 ||
          (0 <= \result < sortedArray_len && sortedArray[\result] == value); */
int check_B_implies_A(int * sortedArray, int sortedArray_len, int value) {
    return stub_B(sortedArray, sortedArray_len, value);
}
