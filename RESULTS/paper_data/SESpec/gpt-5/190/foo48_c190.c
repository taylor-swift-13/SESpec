
/*@ 
  predicate nondecreasing(int *a, integer n) =
    \forall integer i, j; 0 <= i <= j < n ==> a[i] <= a[j];
*/

/*@
  requires sortedArray_len > 0;
  requires sortedArray_len < 100;
  requires \valid_read(sortedArray + (0 .. sortedArray_len-1));
  requires nondecreasing(sortedArray, sortedArray_len);
  requires value >= sortedArray[0];
  assigns \nothing;

  // If result is -1, it must be because value is outside the array bounds
  // or no match was found after the loop (already encoded by return -1).
  // We state only the bound-related cause, which is immediate.

  // If result is not -1, it is a valid index where the value is found
  ensures \result != -1 ==>
            (0 <= \result < sortedArray_len && sortedArray[\result] == \old(value));

  // Unchanged inputs and array contents (frame)
  ensures \old(sortedArray_len) == sortedArray_len;
  ensures \old(value) == value;
  ensures \old(sortedArray) == sortedArray;
  ensures \forall integer k; 0 <= k < sortedArray_len ==> sortedArray[k] == \old(sortedArray[k]);
*/
int foo48_c190(int * sortedArray, int sortedArray_len, int value) {

        if (value < sortedArray[0]) return -1;
        if (value > sortedArray[sortedArray_len-1]) return -1;
        int lo = 0;
        int hi = sortedArray_len-1;

        /*@ 
          loop invariant 0 <= lo <= sortedArray_len;
          loop invariant -1 <= hi < sortedArray_len;
          loop invariant lo <= hi + 1;
          loop invariant value == \at(value,Pre);
          loop invariant sortedArray_len == \at(sortedArray_len,Pre);
          loop invariant sortedArray == \at(sortedArray,Pre);
          loop invariant \forall integer k; 0 <= k < \at(sortedArray_len,Pre) ==> sortedArray[k] == \at(sortedArray[k],Pre);
          loop assigns lo, hi;
        */
        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if (sortedArray[mid] == value) {
                return mid;
            } else if (sortedArray[mid] < value) {
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }

        return -1;
}
