
/*@
logic integer prod{L}(int *a, integer l, integer u) =
  (l >= u) ? 1 : ((integer)a[l] * prod(a, l + 1, u));
*/

/*@ logic integer suffixsum(int *a, integer i, integer n) =
  (i >= n) ? 0 : prod(a, i, n) + suffixsum(a, i + 1, n);
*/

/*@ logic integer contrib(int *a, integer i, integer j) =
  (j <= i) ? 0 : contrib(a, i, j - 1) + prod(a, i, j - 1);
*/

        
/*@ logic integer row_contrib_sum(int *a, integer i, integer n) =
  (i >= n) ? 0 : contrib(a, i, n) + row_contrib_sum(a, i + 1, n);
*/
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires 0 <= n <= arr_len;
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result >= 0;
  ensures n == 0 ==> \result >= 0;
  ensures \result >= 0;
*/

int foo273(int * arr, int arr_len, int n) {

        int sum = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant 0 <= sum;
          loop invariant \forall integer k; 0 <= k < i ==> 0 <= arr[k] <= 100;
          loop assigns i, sum;
            */
            for (int i = 0; i < n; i++) {
            int product = 1;
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant i <= j <= n;
          loop invariant product >= 0;
          loop invariant sum >= 0;
          loop invariant \forall integer k; i <= k < j ==> 0 <= arr[k] <= 100;
          loop assigns product, sum, j;
            */
            for (int j = i; j < n; j++) {
                product *= arr[j];
                sum += product;
            }
            
        }
            
        return sum;
}
