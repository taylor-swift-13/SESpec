
/*@
  logic integer lower_bound(int *a, integer lo, integer hi, integer v) =
    lo > hi ? lo
            : (a[(lo + hi) / 2] < v
               ? lower_bound(a, (lo + hi) / 2 + 1, hi, v)
               : lower_bound(a, lo, (lo + hi) / 2 - 1, v));
*/

/*@
  logic integer upper_bound(int *a, integer lo, integer hi, integer v) =
    lo > hi ? hi
            : (a[(lo + hi) / 2] > v
               ? upper_bound(a, lo, (lo + hi) / 2 - 1, v)
               : upper_bound(a, (lo + hi) / 2 + 1, hi, v));
*/

/*@
  predicate all_less(int *a, integer lo, integer hi, integer v) =
    \forall integer k; lo <= k <= hi ==> a[k] < v;
*/

/*@
  predicate all_greater(int *a, integer lo, integer hi, integer v) =
    \forall integer k; lo <= k <= hi ==> a[k] > v;
*/

int foo190(int * sortedArray, int sortedArray_len, int value) {

        if (value < sortedArray[0]) return -1;
        if (value > sortedArray[sortedArray_len-1]) return -1;
        int lo = 0;
        int hi = sortedArray_len-1;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(sortedArray_len,Pre) - 1) ==> (((hi == \at(sortedArray_len,Pre) - 1)&&(lo == 0)&&(value == \at(value,Pre))&&(sortedArray_len == \at(sortedArray_len,Pre))&&(sortedArray == \at(sortedArray,Pre))) || (0 <= lo <= hi + 1 <= sortedArray_len));
          loop invariant (0 <= \at(sortedArray_len,Pre) - 1) ==> (((hi == \at(sortedArray_len,Pre) - 1)&&(lo == 0)&&(value == \at(value,Pre))&&(sortedArray_len == \at(sortedArray_len,Pre))&&(sortedArray == \at(sortedArray,Pre))) || (0 <= hi < sortedArray_len));
          loop invariant (!(0 <= \at(sortedArray_len,Pre) - 1)) ==> ((hi == \at(sortedArray_len,Pre) - 1)&&(lo == 0)&&(value == \at(value,Pre))&&(sortedArray_len == \at(sortedArray_len,Pre))&&(sortedArray == \at(sortedArray,Pre)));
          loop invariant value == \at(value,Pre);
          loop invariant sortedArray_len == \at(sortedArray_len,Pre);
          loop invariant sortedArray == \at(sortedArray,Pre);
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
