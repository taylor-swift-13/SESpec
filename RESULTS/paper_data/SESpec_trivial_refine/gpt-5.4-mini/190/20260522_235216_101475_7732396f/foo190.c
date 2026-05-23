
/*@
predicate sorted(int *a, integer n) =
  \forall integer i, j; 0 <= i <= j < n ==> a[i] <= a[j];
*/

/*@
    requires sorted(sortedArray, sortedArray_len);
    requires sortedArray_len > 0;
    assigns \nothing;
    ensures \result != -1 ==> 0 <= \result < sortedArray_len;
    ensures \result != -1 ==> sortedArray[\result] == value;
*/
int foo190(int * sortedArray, int sortedArray_len, int value) {

        if (value < sortedArray[0]) return -1;
        if (value > sortedArray[sortedArray_len-1]) return -1;
        int lo = 0;
        int hi = sortedArray_len-1;

        /*@
          loop invariant sorted(sortedArray, sortedArray_len);
          loop invariant 0 <= lo <= sortedArray_len;
          loop invariant -1 <= hi < sortedArray_len;
          loop invariant lo <= hi + 1;
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
