
/*@
  // Logic: all elements in [lo, hi) equal v
  logic boolean all_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? \true : (a[lo] == v && all_eq(a, lo + 1, hi, v));
*/

const char * foo272(int * arr, int arr_len, int n) {

        if (n == 0) {
            return "NO";
        }

        int firstElement = arr[0];
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \forall integer k; 1 <= k < i ==> arr[k] == firstElement;
          loop invariant (!(i < n)) ==> \true;
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop assigns i;
            */
            for (int i = 1; i < n; i++) {
            if (arr[i] != firstElement) {
                return "NO";
            }
        }
            
        return "YES";
}
