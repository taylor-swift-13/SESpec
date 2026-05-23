
/*@
  // Array is nondecreasing over [0..n-1]
  predicate nondecreasing(int *a, integer n) =
    \forall integer i, j; 0 <= i <= j < n ==> a[i] <= a[j];
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns \nothing;
  ensures (\result != -1 ==> (0 <= \result < a_len && a[\result] == x && (\result == 0 || a[\result - 1] != x)));
  ensures \result == -1 || \result >= 0;
  ensures \result == -1 || \result < a_len;
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
