/*@
    requires \valid_read(sortedArray + (0..sortedArray_len-1));
    requires sortedArray_len > 0;
    requires \forall integer i; 0 <= i < sortedArray_len-1 ==> sortedArray[i] <= sortedArray[i+1];
    ensures \result == -1 || (0 <= \result < sortedArray_len && sortedArray[\result] == value);
    assigns \nothing;
*/
int search(int * sortedArray, int sortedArray_len, int value) {

        if (value < sortedArray[0]) return -1;
        if (value > sortedArray[sortedArray_len-1]) return -1;
        int lo = 0;
        int hi = sortedArray_len-1;

        /*@
            loop invariant 0 <= lo && lo <= hi+1 && hi < sortedArray_len;
            loop invariant \forall integer i; 0 <= i < lo ==> sortedArray[i] < value;
            loop invariant \forall integer i; hi+1 <= i < sortedArray_len ==> sortedArray[i] > value;
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
