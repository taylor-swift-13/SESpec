
/*@
  logic integer pair_xor_sum_prefix(int* a, integer hi) =
    hi <= 0 ? 0
            : pair_xor_sum_prefix(a, hi - 1)
              + ( \sum integer k; 0 <= k < hi ==> (a[hi - 1] ^ a[k]) );
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;   
  ensures \result == pair_xor_sum_prefix(arr, arr_len);
  ensures \result == pair_xor_sum_prefix(\at(arr,Pre), \at(arr_len,Pre));  
*/
int foo275(int * arr, int arr_len, int n) {

        int sum = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= arr_len;
          loop invariant sum == pair_xor_sum_prefix(arr, i);
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop assigns i, j, sum;
            */
            for (int i = 0; i < arr_len; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant i + 1 <= j <= arr_len;
          loop invariant sum == pair_xor_sum_prefix(arr, i)
                               + ( \sum integer k; i + 1 <= k < j ==> (arr[i] ^ arr[k]) );
          loop assigns sum, j;
            */
            for (int j = i + 1; j < arr_len; j++) {
                sum += arr[i] ^ arr[j];
            }
            
        }
            
        return sum;
}
