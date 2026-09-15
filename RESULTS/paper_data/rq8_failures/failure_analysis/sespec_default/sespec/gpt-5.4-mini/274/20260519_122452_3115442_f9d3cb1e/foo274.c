
/*@
logic integer sum_even_index_even_value(int *arr, integer begin, integer end) =
  begin >= end ? 0 :
  sum_even_index_even_value(arr, begin, end - 1) +
  (((end - 1) % 2 == 0 && arr[end - 1] % 2 == 0) ? arr[end - 1] : 0);
*/

/*@ 
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  requires 0 <= n <= arr_len;
  assigns \nothing;
  ensures \result == sum_even_index_even_value(arr, 0, n);
*/
int foo274(int * arr, int arr_len, int n) {

        int count = 0;
        
            
        /*@
          loop invariant 0 <= i;
          loop invariant (n < 0) || (i <= n);
          loop invariant count == sum_even_index_even_value(arr, 0, i);
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
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
