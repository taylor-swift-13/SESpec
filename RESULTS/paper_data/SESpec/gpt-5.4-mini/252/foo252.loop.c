
/*@
logic integer pair_count{L}(int *arr, integer n, integer k, int sum) =
  (k <= 0 ? 0 :
   pair_count(arr, n, k - 1, sum) +
   (k - 1 < n && 0 <= k - 1 && 0 <= k - 1 < n ? 0 : 0));
*/

/*@ requires n >= 0; */

int foo252(int * arr, int arr_len, int n, int sum) {

        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant 0 <= count;
          loop invariant sum == \at(sum, Pre);
          loop invariant n == \at(n, Pre);
          loop invariant arr_len == \at(arr_len, Pre);
          loop invariant arr == \at(arr, Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop assigns i, count;
            */
            for (int i = 0; i < n; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant 0 <= count;
          loop invariant i + 1 <= n;
          loop invariant 0 <= j <= n;
          loop invariant j >= i + 1;
          loop assigns j, count;
            */
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == sum) {
                    count++;
                }
            }
            
        }
            
        return count;
}
