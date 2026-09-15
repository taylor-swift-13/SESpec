
/*@
  // Array is nondecreasing over [0..n-1]
  predicate nondecreasing(int *a, integer n) =
    \forall integer i, j; 0 <= i <= j < n ==> a[i] <= a[j];
*/

int foo185(int * a, int a_len, int x) {

        int low = 0, high = a_len - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= a_len ==> 0 <= low && -1 <= high && low <= high + 1;
              loop invariant 0 <= a_len ==> -1 <= high < a_len;
              loop invariant 0 <= a_len ==> 0 <= low <= a_len;
              loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
              loop assigns high, low;
            */
            while (low <= high) {
            int mid = low + (high - low) / 2;
            if (a[mid] == x) {
                if (mid == 0 || a[mid - 1] != x) {
                    return mid;
                } else {
                    high = mid - 1;
                }
            } else if (a[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
            
        return -1;
}
