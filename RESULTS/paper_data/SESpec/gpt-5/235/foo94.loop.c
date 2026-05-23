
/*@ 
  logic integer max_prefix(int* a, integer n) =
    n <= 0 ? a[0] 
           : (max_prefix(a, n-1) < a[n] ? a[n] : max_prefix(a, n-1));
*/

/*@ 
  logic integer min_prefix(int* a, integer n) =
    n <= 0 ? a[0]
           : (min_prefix(a, n-1) > a[n] ? a[n] : min_prefix(a, n-1));
*/

/*@ 
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
*/
int foo94(int * arr, int arr_len) {

		int result = arr[0];
		int sum = arr[0];
		
            
        /*@ 
          loop invariant 1 <= n <= arr_len;
          loop invariant result == max_prefix(arr, n-1);
          loop invariant sum == min_prefix(arr, n-1);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
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
