
/*@
  logic integer sorted{L}(int* a, integer lo, integer hi) =
    lo >= hi - 1 ? 1
                 : (a[lo] <= a[lo + 1] ? sorted(a, lo + 1, hi) : 0);
*/

/*@
  requires \valid_read(sortedArray + (0..sortedArray_len-1));
  requires sortedArray_len > 0;
  requires sortedArray_len < 100;
  requires sorted(sortedArray, 0, sortedArray_len);
  requires value >= sortedArray[0];
  requires value <= sortedArray[sortedArray_len - 1];
  ensures \result == -1 || (0 <= \result < sortedArray_len && sortedArray[\result] == value);
  assigns \nothing;
*/
int foo190(int * sortedArray, int sortedArray_len, int value) {

    if (value < sortedArray[0]) return -1;
    if (value > sortedArray[sortedArray_len-1]) return -1;
    int lo = 0;
    int hi = sortedArray_len-1;

    /*@
      loop invariant 0 <= lo <= hi + 1 <= sortedArray_len;
      loop invariant sorted(sortedArray, 0, sortedArray_len);
      loop invariant \exists integer mid; lo <= mid <= hi ==> sortedArray[mid] == value || sortedArray[mid] != value;
      loop invariant value == \at(value, Pre);
      loop invariant sortedArray_len == \at(sortedArray_len, Pre);
      loop invariant sortedArray == \at(sortedArray, Pre);
      loop assigns lo, hi;
      loop variant hi - lo;
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
