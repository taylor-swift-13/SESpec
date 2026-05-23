#include <limits.h>


/*@
  logic integer lower_bound(int *a, integer lo, integer hi, integer v) =
    lo > hi ? lo
            : (a[(lo + hi) / 2] < v
               ? lower_bound(a, (lo + hi) / 2 + 1, hi, v)
               : lower_bound(a, lo, (lo + hi) / 2 - 1, v));
*/

  logic integer upper_bound(int *a, integer lo, integer hi, integer v) =
    lo > hi ? hi
            : (a[(lo + hi) / 2] > v
               ? upper_bound(a, lo, (lo + hi) / 2 - 1, v)
               : upper_bound(a, (lo + hi) / 2 + 1, hi, v));

  predicate all_less(int *a, integer lo, integer hi, integer v) =
    \forall integer k; lo <= k <= hi ==> a[k] < v;

  predicate all_greater(int *a, integer lo, integer hi, integer v) =
    \forall integer k; lo <= k <= hi ==> a[k] > v;

/*@requires \valid(&sortedArray[0] + (0..sortedArray_len-1));
  requires \forall integer i; 0 <= i < sortedArray_len ==> 0 <= sortedArray[i] <= 100;
  requires sortedArray_len > 0;
  requires sortedArray_len < 100;
  assigns \nothing;
  ensures \result == -1 ||
          (0 <= \result < sortedArray_len && sortedArray[\result] == value);*/
int stub_A(int * sortedArray, int sortedArray_len, int value);

/*@loop invariant lo == 0 || sortedArray[lo-1] <= value;
        loop invariant lo == 0 || sortedArray[lo-1] < value;
        loop invariant hi == sortedArray_len-1 || value <= sortedArray[hi+1];
        loop invariant hi == sortedArray_len-1 || value < sortedArray[hi+1];
        loop invariant hi == sortedArray_len-1 || sortedArray[hi+1] > value;
        loop invariant hi < sortedArray_len;
        loop invariant hi + 1 <= sortedArray_len;
        loop invariant 0 <= lo;
        loop invariant 0 <= lo || lo == hi + 1;
        loop assigns lo;
        loop assigns hi;*/
int stub_B(int * sortedArray, int sortedArray_len, int value);

/*@loop invariant lo == 0 || sortedArray[lo-1] <= value;
        loop invariant lo == 0 || sortedArray[lo-1] < value;
        loop invariant hi == sortedArray_len-1 || value <= sortedArray[hi+1];
        loop invariant hi == sortedArray_len-1 || value < sortedArray[hi+1];
        loop invariant hi == sortedArray_len-1 || sortedArray[hi+1] > value;
        loop invariant hi < sortedArray_len;
        loop invariant hi + 1 <= sortedArray_len;
        loop invariant 0 <= lo;
        loop invariant 0 <= lo || lo == hi + 1;
        loop assigns lo;
        loop assigns hi;*/
int check_A_implies_B(int * sortedArray, int sortedArray_len, int value) {
    return stub_A(sortedArray, sortedArray_len, value);
}

/*@requires \valid(&sortedArray[0] + (0..sortedArray_len-1));
  requires \forall integer i; 0 <= i < sortedArray_len ==> 0 <= sortedArray[i] <= 100;
  requires sortedArray_len > 0;
  requires sortedArray_len < 100;
  assigns \nothing;
  ensures \result == -1 ||
          (0 <= \result < sortedArray_len && sortedArray[\result] == value);*/
int check_B_implies_A(int * sortedArray, int sortedArray_len, int value) {
    return stub_B(sortedArray, sortedArray_len, value);
}
