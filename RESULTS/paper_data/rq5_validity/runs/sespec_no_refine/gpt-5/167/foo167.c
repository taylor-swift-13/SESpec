
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

        
/*@ logic integer max_for_n(int* a, integer n) =
      n <= 0 ? a[0] : max_prefix(a, n); */
/*@ logic integer sum_q(int* a, integer n, integer M, integer k) =
      n <= 0 ? 0 : sum_q(a, n - 1, M, k) + (M - a[n - 1]) / k; */
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures arr == \at(arr,Pre);
  ensures arr_len == \at(arr_len,Pre);
  ensures n == \at(n,Pre);
  ensures k == \at(k,Pre);
  ensures array_unchanged{Pre,Post}(arr, 0, n);
  ensures k != 0 && (\forall integer t; 0 <= t < n ==> (max_for_n(arr, n) - arr[t]) % k == 0)
          ==> \result == sum_q(arr, n, max_for_n(arr, n), k);
  ensures k != 0 && (\exists integer t; 0 <= t < n && (max_for_n(arr, n) - arr[t]) % k != 0)
          ==> \result == -1;
  ensures \result == PLACE_HOLDER_RESULT;
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
