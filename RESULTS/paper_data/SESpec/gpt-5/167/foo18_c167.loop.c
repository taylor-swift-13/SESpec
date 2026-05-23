
/*@
  logic integer max_prefix(int* a, integer n) =
    n <= 1 ? a[0] : (max_prefix(a, n-1) < a[n-1] ? a[n-1] : max_prefix(a, n-1));
*/
/*@ 
  predicate unchanged_prefix{L1,L2}(int* a, integer len) =
    \forall integer k; 0 <= k < len ==> \at(a[k], L1) == \at(a[k], L2);
*/
        
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
*/

int foo18_c167(int * arr, int arr_len, int n, int k) {

        int max1 = arr[0];
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i;
          loop invariant \forall integer k0; 0 <= k0 < i ==> arr[k0] <= max1;
          loop invariant \forall integer k0; 0 <= k0 < arr_len ==> arr[k0] == \at(arr[k0], Pre);
          loop assigns i, max1;
            */
            for (int i = 1; i < n; i++) {
            if (arr[i] > max1) {
                max1 = arr[i];
            }
        }
            
        int res = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i;
          loop invariant \forall integer k0; 0 <= k0 < arr_len ==> arr[k0] == \at(arr[k0], Pre);
          loop assigns i, res;
            */
            for (int i = 0; i < n; i++) {
            if ((max1 - arr[i]) % k != 0) {
                return -1;
            } else {
                res += (max1 - arr[i]) / k;
            }
        }
            
        return res;
}
