
/*@
  requires arr_len >= 1;
  requires \valid_read(arr + (0..arr_len-1));
  assigns \nothing;
*/
int foo235(int * arr, int arr_len) {

		int result = arr[0];
		int sum = arr[0];
		
        /*@
          loop invariant 1 <= n <= arr_len;
          loop invariant result >= sum;
          loop invariant \forall integer k; 0 <= k < n ==> arr[k] <= result;
          loop invariant \forall integer k; 0 <= k < n ==> arr[k] >= sum;
          loop invariant \exists integer k; 0 <= k < n && arr[k] == result;
          loop invariant \exists integer k; 0 <= k < n && arr[k] == sum;
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop invariant (n < arr_len) ==> (result - sum >= 0);
          loop invariant (!(n < arr_len)) ==> (\true);
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
