
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires a_len >= 0;
  requires \valid_read(a + (0..(a_len > 0 ? a_len-1 : 0)));
  // The array is non-decreasing (sorted)
  requires \forall integer i,j; 0 <= i <= j < a_len ==> a[i] <= a[j];

  // Postconditions (for context; not modified as per rules)
  ensures \result == -1 ==> \forall integer k; 0 <= k < a_len ==> a[k] != x;
  ensures \result >= 0 ==> 0 <= \result < a_len;
  ensures \result >= 0 ==> a[\result] == x;
  ensures \result >= 0 ==> (\result == a_len - 1 || a[\result + 1] != x);
*/
int foo182(int * a, int a_len, int x) {

        int low = 0;
        int high = a_len - 1;
        int mid = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          // Window bounds and monotonic narrowing
          loop invariant 0 <= low <= a_len;
          loop invariant -1 <= high < a_len;
          loop invariant low <= high + 1;

          // Relational facts w.r.t x preserved by updates

          // Array is not modified
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);

          // Mid is within window when the loop guard holds
          loop invariant (low <= high) ==> (low <= ((low + high) / 2) <= high);

          // Exit implication: empty window and relational facts imply x absent

          // Pre-state preservation of parameters/pointers
          loop invariant x == \at(x,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop assigns mid, low, high;
            */
            while (low <= high) {
            mid = (low + high) / 2;
            if (a[mid] == x) {
                if (mid == a_len - 1 || a[mid + 1] != x) {
                    return mid;
                } else {
                    low = mid + 1;
                }
            } else if (a[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
            
        return -1;
}
