int smallestMissing(int * a, int a_len, int leftElement, int rightElement);

 /*@
   requires a_len >= 1;
   requires \valid_read(a + (0 .. a_len-1));
   requires 0 <= leftElement <= rightElement < a_len;

   // array is strictly increasing and non-negative
   requires \forall integer k; 0 <= k < a_len-1 ==> a[k] < a[k+1];
   requires \forall integer k; 0 <= k < a_len ==> a[k] >= 0;

   assigns \nothing;

   ensures leftElement <= \result <= rightElement + 1;

   // all indices before the result match their indices
   ensures \forall integer k; leftElement <= k < \result ==> a[k] == k;

   // either result points to a mismatch, or all in range match and result == rightElement+1
   ensures \result == rightElement + 1 || a[\result] != \result;
 */
int smallestMissing(int * a, int a_len, int leftElement, int rightElement) {

        int i = leftElement;
        int j = rightElement;
        /*@
          loop invariant leftElement <= i <= j + 1 <= rightElement + 1;
          loop invariant \forall integer k; leftElement <= k < i ==> a[k] == k;
          loop invariant \forall integer k; j < k <= rightElement ==> a[k] != k;
          loop assigns i, j;
          loop variant j - i + 1;
        */
        while (i <= j) {
            int mid = (i + j) / 2;
            /*@ assert i <= mid <= j; */
            /*@ assert 0 <= mid < a_len; */
            if (a[mid] == mid) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return i;
}
