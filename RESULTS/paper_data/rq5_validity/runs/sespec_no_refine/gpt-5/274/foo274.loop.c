
/*@
  logic integer evensum(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : evensum(a, lo, hi - 1)
               + ((((hi - 1) % 2) == 0) && ((a[hi - 1] % 2) == 0) ? a[hi - 1] : 0);
*/

int foo274(int * arr, int arr_len, int n) {

        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre) ;
          loop assigns i, count;
            */
            for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (arr[i] % 2 == 0) {
                    count += arr[i];
                }
            }
        }
            
        return count;
}
