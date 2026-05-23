
/*@ logic integer sum_even_at(int* arr, integer lo, integer hi) =
      lo >= hi ? 0
               : sum_even_at(arr, lo, hi - 1) + ((arr[hi - 1] % 2 == 0) ? arr[hi - 1] : 0);
*/

/*@
  requires \at(arr_len, Pre) > 0 && \at(arr_len, Pre) < 100;
  assigns count, i;
  ensures \result == sum_even_at(arr, 0, n);
*/
int foo154(int * arr, int arr_len, int n) {

        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < \at(arr_len,Pre) ==> arr[k] == \at(arr[k],Pre);
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
