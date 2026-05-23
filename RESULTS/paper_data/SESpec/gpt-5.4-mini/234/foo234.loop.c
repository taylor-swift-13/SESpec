
/*@
  requires arr_len >= 1;
  requires \valid_read(arr + (0..arr_len-1));
*/
int foo234(int * arr, int arr_len) {

		int big = arr[0];
		int sum = arr[0];
		
        /*@
          loop invariant 1 <= n <= arr_len;
          loop invariant \forall integer k; 0 <= k < n ==> arr[k] <= big;
          loop invariant \forall integer k; 0 <= k < n ==> sum <= arr[k];
          loop invariant \exists integer k; 0 <= k < n && arr[k] == big;
          loop invariant \exists integer k; 0 <= k < n && arr[k] == sum;
          loop invariant big >= sum;
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop invariant (n < arr_len) ==> big >= sum;
          loop invariant (n >= arr_len) ==> (\forall integer k; 0 <= k < arr_len ==> arr[k] <= big);
          loop invariant (n >= arr_len) ==> (\forall integer k; 0 <= k < arr_len ==> sum <= arr[k]);
          loop invariant (n >= arr_len) ==> (\exists integer k; 0 <= k < arr_len && arr[k] == big);
          loop invariant (n >= arr_len) ==> (\exists integer k; 0 <= k < arr_len && arr[k] == sum);
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
