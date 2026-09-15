
/*@ 
  predicate nondecreasing(int *a, integer n) =
    \forall integer i, j; 0 <= i <= j < n ==> a[i] <= a[j];
*/

/*@
  requires \valid_read(sortedArray + (0 .. sortedArray_len-1));
  requires \at(value,Pre) <= sortedArray[\at(sortedArray_len,Pre) - 1]
           && \at(value,Pre) >= sortedArray[0]
           && \at(sortedArray_len,Pre) > 0
           && \at(sortedArray_len,Pre) < 100 ;
  assigns \nothing;
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
