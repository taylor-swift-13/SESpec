
/*@
predicate sorted{L}(int *a, integer n) =
  \forall integer i, j; 0 <= i <= j < n ==> a[i] <= a[j];
*/

int foo185(int * a, int a_len, int x) {

        int low = 0, high = a_len - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant PLACE_HOLDER_SUPPLEMENTARY_INVARIANTS;
          loop invariant 0 <= low <= a_len;
          loop invariant -1 <= high < a_len;
          loop invariant low <= high + 1;
          loop invariant \forall integer i; 0 <= i < low ==> a[i] < x;
          loop invariant \forall integer i; high < i < a_len ==> a[i] >= x;
          loop assigns low, high;
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
