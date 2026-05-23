
/*@ logic integer max_prefix(int *arr, integer n, integer i) =
      i <= 0 ? arr[0] :
      (i <= 1 ? arr[0] :
       (i <= n ? (max_prefix(arr, n, i - 1) > arr[i - 1] ? max_prefix(arr, n, i - 1) : arr[i - 1]) : max_prefix(arr, n, n)));
*/

/*@ logic integer min_prefix(int *arr, integer n, integer i) =
      i <= 0 ? arr[0] :
      (i <= 1 ? arr[0] :
       (i <= n ? (min_prefix(arr, n, i - 1) < arr[i - 1] ? min_prefix(arr, n, i - 1) : arr[i - 1]) : min_prefix(arr, n, n)));
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures \result == max_prefix(arr, arr_len, arr_len) - min_prefix(arr, arr_len, arr_len);
  ensures \result == \at(result, Pre) - \at(sum, Pre);
*/
int foo94(int * arr, int arr_len) {

		int result = arr[0];
		int sum = arr[0];
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop assigns n, result, sum;
            */
            for (int n = 1; n < arr_len; n++) {
			if (arr[n] > result) {
				result = arr[n];
			}
			if (arr[n] < sum) {
				sum = arr[n];
			}
		}
            
		return result - sum;
}
