
/*@ predicate all_equal_prefix(int *arr, integer n, integer i) =
      0 <= i <= n &&
      (\forall integer k; 0 <= k < i - 1 ==> arr[k] == arr[k + 1]);
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  requires n > 0;
  requires n <= arr_len;
  assigns \nothing;
*/
int foo283(int * arr, int arr_len, int n) {

        int i = 0;
        
            /*@
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop assigns i;
            */
            while (i < n - 1) {
            if (arr[i] == arr[i + 1]) {
                i += 2;
            } else {
                return arr[i];
            }
        }
            
        return arr[n - 1];
}
