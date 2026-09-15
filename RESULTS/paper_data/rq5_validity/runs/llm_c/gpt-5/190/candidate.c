int search(int * sortedArray, int sortedArray_len, int value);

/*@ 
  requires sortedArray_len > 0;
  requires \valid_read(sortedArray + (0 .. sortedArray_len-1));
  requires \forall integer i, j; 0 <= i <= j < sortedArray_len ==> sortedArray[i] <= sortedArray[j];
  assigns \nothing;

  behavior present:
    assumes \exists integer k; 0 <= k < sortedArray_len && sortedArray[k] == value;
    ensures 0 <= \result < sortedArray_len && sortedArray[\result] == value;

  behavior absent:
    assumes \forall integer k; 0 <= k < sortedArray_len ==> sortedArray[k] != value;
    ensures \result == -1;

  complete behaviors;
  disjoint behaviors;
*/
int search(int * sortedArray, int sortedArray_len, int value) {

        if (value < sortedArray[0]) return -1;
        if (value > sortedArray[sortedArray_len-1]) return -1;
        int lo = 0;
        int hi = sortedArray_len-1;

        /*@
          loop invariant 0 <= lo <= sortedArray_len;
          loop invariant -1 <= hi < sortedArray_len;
          loop invariant lo <= hi + 1;
          loop invariant \forall integer k; 0 <= k < lo ==> sortedArray[k] < value;
          loop invariant \forall integer k; hi < k < sortedArray_len ==> sortedArray[k] > value;
          loop assigns lo, hi;
          loop variant hi - lo + 1;
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
