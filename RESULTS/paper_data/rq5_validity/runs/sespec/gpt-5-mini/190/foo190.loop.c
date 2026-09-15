
/*@
  requires sortedArray_len > 0;
  requires \valid_read(sortedArray + (0 .. sortedArray_len-1));
*/
int foo190(int * sortedArray, int sortedArray_len, int value) {

    if (value < sortedArray[0]) return -1;
    if (value > sortedArray[sortedArray_len-1]) return -1;
    int lo = 0;
    int hi = sortedArray_len-1;

    /*@
      loop invariant 0 <= lo <= sortedArray_len;
      loop invariant -1 <= hi < sortedArray_len;
      loop invariant lo <= hi + 1;
      loop invariant lo <= hi ==> (0 <= lo && lo <= hi && hi < sortedArray_len);
      loop invariant \forall integer i; 0 <= i < sortedArray_len ==> sortedArray[i] == \at(sortedArray[i], Pre);
      loop invariant lo <= hi ==>
        ((\exists integer k; lo <= k <= hi && sortedArray[k] == value)
         || (\forall integer k; lo <= k <= hi ==> sortedArray[k] != value));
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
