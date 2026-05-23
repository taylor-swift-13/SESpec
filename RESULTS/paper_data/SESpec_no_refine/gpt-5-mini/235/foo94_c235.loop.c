
/*@
  logic integer max_prefix(int* a, integer lo, integer hi) =
    lo >= hi ? -2147483648
             : (max_prefix(a, lo, hi-1) > a[hi-1] ? max_prefix(a, lo, hi-1) : a[hi-1]);

  logic integer min_prefix(int* a, integer lo, integer hi) =
    lo >= hi ? 2147483647
             : (min_prefix(a, lo, hi-1) < a[hi-1] ? min_prefix(a, lo, hi-1) : a[hi-1]);

  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0 : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid_read(arr + (0 .. arr_len-1));
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
*/
int foo94_c235(int * arr, int arr_len) {

		int result = arr[0];
		int sum = arr[0];
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= n <= arr_len;
          loop invariant (n < arr_len) ==> result == max_prefix(arr, 0, n);
          loop invariant (n < arr_len) ==> sum == min_prefix(arr, 0, n);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer v; count_eq(arr, 0, arr_len, v) == \at(count_eq(arr, 0, arr_len, v), Pre);
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
