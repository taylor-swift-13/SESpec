
/*@
  requires arr_len >= 0;
  requires \valid_read(arr + (0..arr_len-1));
*/

/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

const char * foo152(int * arr, int arr_len, int n) {

        if (n == 0) {
            return "NO";
        }

        int firstElement = arr[0];
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= n;
          loop invariant \forall integer k; 0 <= k < i ==> arr[k] == firstElement;
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
