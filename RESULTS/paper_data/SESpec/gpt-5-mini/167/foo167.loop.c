
/*@ 
  logic integer max_of_prefix(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : (hi == lo + 1 ? a[lo]
                             : (a[hi-1] > max_of_prefix(a, lo, hi-1) ? a[hi-1] : max_of_prefix(a, lo, hi-1)));
*/

/*@
  predicate array_unchanged{L1,L2}(int* a, integer len) =
    \forall integer p; 0 <= p < len ==> \at(a[p],L1) == \at(a[p],L2);
*/

/*@
  logic integer sum_div_k(int* a, integer lo, integer hi, integer max1, integer k) =
    lo >= hi ? 0
             : sum_div_k(a, lo, hi - 1, max1, k) + ( (max1 - a[hi-1]) / k );
*/

/*@
  predicate all_divisible_prefix(int* a, integer lo, integer hi, integer max1, integer k) =
    lo >= hi ? \true
             : ( (max1 - a[hi-1]) % k == 0 && all_divisible_prefix(a, lo, hi - 1, max1, k) );
*/

/*@
  requires \valid_read(arr + (0 .. arr_len-1));
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  requires n == \at(n,Pre);
  requires k == \at(k,Pre);
  requires arr_len == \at(arr_len,Pre);
  requires arr == \at(arr,Pre);
  assigns \nothing;
*/
int foo167(int * arr, int arr_len, int n, int k) {

        int max1 = arr[0];
        
            
        /*@
          loop invariant k == \at(k,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant array_unchanged{Pre,Here}(arr, arr_len);
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
          loop invariant (i < n) ==> (0 <= i && i < n);
          loop invariant (0 <= i && i <= n) ==> all_divisible_prefix(arr, 0, i, max1, k);
          loop invariant (0 <= i && i <= n) ==> res == sum_div_k(arr, 0, i, max1, k);
          loop invariant (!(i < n)) ==> (res == sum_div_k(arr, 0, n, max1, k));
          loop invariant array_unchanged{Pre,Here}(arr, arr_len);
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
