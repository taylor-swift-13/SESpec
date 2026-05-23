
/*@
  logic integer max_prefix(int* a, integer hi) =
    hi <= 1 ? a[0] : (max_prefix(a, hi - 1) >= a[hi - 1] ? max_prefix(a, hi - 1) : a[hi - 1]);
*/
/*@
  predicate array_unchanged{L1,L2}(int* a, integer lo, integer hi) =
    \forall integer t; lo <= t < hi ==> \at(a[t],L1) == \at(a[t],L2);
*/

/*@
*/

        
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
*/

int foo167(int * arr, int arr_len, int n, int k) {

        int max1 = arr[0];
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \forall integer t; 0 <= t < n ==> \at(arr[t],Pre) == arr[t];
          loop invariant (i < \at(n,Pre)) ==> (\forall integer t; 0 <= t < i ==> arr[t] <= max1);
          loop invariant k == \at(k,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant array_unchanged{Pre,Here}(arr, 0, n) ;
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
          loop invariant 0 <= i <= n;
          loop invariant \forall integer t; 0 <= t < n ==> \at(arr[t],Pre) == arr[t];
          loop invariant \forall integer t; 0 <= t < i ==> (max1 - arr[t]) % k == 0;
          loop invariant k == \at(k,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant array_unchanged{Pre,Here}(arr, 0, n) ;
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
