
/*@
  predicate valid_prefix(int *arr, integer n) =
    \forall integer k; 0 <= k < n ==> \valid(arr + k);
*/

/*@
  logic integer prod_from_to(int* a, integer lo, integer hi) =
    lo >= hi ? 1 : a[lo] * prod_from_to(a, lo + 1, hi);

  logic integer tail_prod_sum_from(int* a, integer start, integer n) =
    start >= n ? 0 : prod_from_to(a, start, n) + tail_prod_sum_from(a, start + 1, n);
*/
        
/*@
  assigns \nothing;
  ensures \result == tail_prod_sum_from(arr, 0, n);
*/
int foo273(int * arr, int arr_len, int n) {

        int sum = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop invariant sum == (\sum integer ii = 0; ii < i; ii++
                                   (\prod integer k = ii; k < n; k++ arr[k]));
          loop assigns i, product, j, sum;
            */
            for (int i = 0; i < n; i++) {
            int product = 1;
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant i <= j <= n;
          loop invariant valid_prefix(arr, n);
          loop invariant sum == \at(sum, Pre) +
                                (\sum integer ii = 0; ii < i; ii++
                                  (\prod integer k = ii; k < n; k++ arr[k]));
          loop invariant product == (\prod integer k = i; k < j; k++ arr[k]);
          loop invariant j == i ==> product == 1;
          loop assigns product, sum;
            */
            for (int j = i; j < n; j++) {
                product *= arr[j];
                sum += product;
            }
            
        }
            
        return sum;
}
