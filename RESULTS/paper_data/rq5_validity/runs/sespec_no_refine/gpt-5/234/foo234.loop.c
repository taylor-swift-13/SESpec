
/*@
  logic integer max_prefix(int* a, integer k) =
    k <= 1 ? a[0] : (let m = max_prefix(a, k-1) in (m >= a[k-1] ? m : a[k-1]));

  logic integer min_prefix(int* a, integer k) =
    k <= 1 ? a[0] : (let m = min_prefix(a, k-1) in (m <= a[k-1] ? m : a[k-1]));
*/
        
int foo234(int * arr, int arr_len) {

		int big = arr[0];
		int sum = arr[0];
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= n <= arr_len;
          loop invariant big == max_prefix(arr, n);
          loop invariant sum == min_prefix(arr, n);
          loop invariant \forall integer k; 0 <= k < n ==> sum <= arr[k] <= big;
          loop assigns PLACE_HOLDER_ASSIGNMENTS;
            */
            for (int n = 1; n < arr_len; n++) {
			if (arr[n] > big) {
				big = arr[n];
			}
			if (arr[n] < sum) {
				sum = arr[n];
			}
		}
            
		return big - sum;
}
