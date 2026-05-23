
/*@
  logic integer max_prefix(int* a, integer k) =
    k <= 1 ? a[0] : (let m = max_prefix(a, k-1) in (m >= a[k-1] ? m : a[k-1]));

  logic integer min_prefix(int* a, integer k) =
    k <= 1 ? a[0] : (let m = min_prefix(a, k-1) in (m <= a[k-1] ? m : a[k-1]));
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures \result == max_prefix(arr, arr_len) - min_prefix(arr, arr_len);
  ensures \forall integer k; 0 <= k < arr_len ==> min_prefix(arr, arr_len) <= arr[k] <= max_prefix(arr, arr_len);
  ensures 0 <= \result <= 100;
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
          loop assigns \nothing;
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
