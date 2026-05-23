
/*@
  logic integer max_prefix(int* arr, integer n) =
    n <= 1 ? arr[0] : (arr[n - 1] > max_prefix(arr, n - 1) ? arr[n - 1] : max_prefix(arr, n - 1));

  logic integer min_prefix(int* arr, integer n) =
    n <= 1 ? arr[0] : (arr[n - 1] < min_prefix(arr, n - 1) ? arr[n - 1] : min_prefix(arr, n - 1));
*/

int foo234(int * arr, int arr_len) {

		int big = arr[0];
		int sum = arr[0];
		
        /*@
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < n ==> arr[k] <= big;
          loop invariant big >= sum;
          loop assigns n, big, sum;
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
