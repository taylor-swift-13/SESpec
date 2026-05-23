
/*@
  logic integer bsearch_found(integer lo, integer hi, int *a, integer value) =
    lo > hi ? 0 :
    (a[lo + (hi - lo) / 2] == value ? 1 :
     (a[lo + (hi - lo) / 2] < value ?
        bsearch_found(lo + (hi - lo) / 2 + 1, hi, a, value) :
        bsearch_found(lo, lo + (hi - lo) / 2 - 1, a, value)));
*/

int foo190(int * sortedArray, int sortedArray_len, int value) {

        if (value < sortedArray[0]) return -1;
        if (value > sortedArray[sortedArray_len-1]) return -1;
        int lo = 0;
        int hi = sortedArray_len-1;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(sortedArray_len,Pre) - 1) ==> (((hi == \at(sortedArray_len,Pre) - 1)&&(lo == 0)&&(value == \at(value,Pre))&&(sortedArray_len == \at(sortedArray_len,Pre))&&(sortedArray == \at(sortedArray,Pre))) || (0 <= lo <= hi + 1));
          loop invariant (0 <= \at(sortedArray_len,Pre) - 1) ==> (((hi == \at(sortedArray_len,Pre) - 1)&&(lo == 0)&&(value == \at(value,Pre))&&(sortedArray_len == \at(sortedArray_len,Pre))&&(sortedArray == \at(sortedArray,Pre))) || (lo >= 0 && hi < \at(sortedArray_len,Pre)));
          loop invariant (!(0 <= \at(sortedArray_len,Pre) - 1)) ==> ((hi == \at(sortedArray_len,Pre) - 1)&&(lo == 0)&&(value == \at(value,Pre))&&(sortedArray_len == \at(sortedArray_len,Pre))&&(sortedArray == \at(sortedArray,Pre)));
          loop invariant value == \at(value,Pre);
          loop invariant sortedArray_len == \at(sortedArray_len,Pre);
          loop invariant sortedArray == \at(sortedArray,Pre);
          loop invariant \forall integer k; 0 <= k < sortedArray_len ==> sortedArray[k] == \at(sortedArray[k],Pre);
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
