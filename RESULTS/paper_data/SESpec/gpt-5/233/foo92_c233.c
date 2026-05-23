
/*@
  logic integer max_prefix(int* a, integer n) =
    n <= 1 ? a[0] : (a[n-1] > max_prefix(a, n-1) ? a[n-1] : max_prefix(a, n-1));
*/

/*@
  logic integer min_prefix(int* a, integer n) =
    n <= 1 ? a[0] : (a[n-1] < min_prefix(a, n-1) ? a[n-1] : min_prefix(a, n-1));
*/

/*@
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  assigns \nothing;
  ensures \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
  ensures \result == max_prefix(arr, arr_len) - min_prefix(arr, arr_len);
*/
int foo92_c233(int * arr, int arr_len) {

		int result = arr[0];
		int num = arr[0];
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= n <= arr_len;
          loop invariant result == max_prefix(arr, n);
          loop invariant num == min_prefix(arr, n);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
          loop assigns n, result, num;
            */
            for (int n = 1; n < arr_len; n++) {
			if (arr[n] > result) {
				result = arr[n];
			}
			if (arr[n] < num) {
				num = arr[n];
			}
		}
            
		return result - num;
}
