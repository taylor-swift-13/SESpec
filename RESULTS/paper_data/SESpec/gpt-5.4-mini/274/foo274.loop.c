
/*@
  logic integer sum_even_even(int* arr, integer lo, integer hi) =
    lo >= hi ? 0
             : sum_even_even(arr, lo, hi - 1)
               + ((hi - 1) % 2 == 0 && arr[hi - 1] % 2 == 0 ? arr[hi - 1] : 0);
*/

/*@ 
  requires n >= 0;
  requires \valid_read(arr + (0..n-1));
*/
int foo274(int * arr, int arr_len, int n) {

        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant count == sum_even_even(arr, 0, i);
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
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
