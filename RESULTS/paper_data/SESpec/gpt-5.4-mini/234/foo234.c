
/*@ logic integer min_arr{L}(int *arr, integer n) =
      n == 1 ? arr[0] : (arr[n-1] < min_arr{L}(arr, n-1) ? arr[n-1] : min_arr{L}(arr, n-1)); */

/*@ logic integer max_arr{L}(int *arr, integer n) =
      n == 1 ? arr[0] : (arr[n-1] > max_arr{L}(arr, n-1) ? arr[n-1] : max_arr{L}(arr, n-1)); */

/*@
  requires arr_len >= 1;
  requires \valid_read(arr + (0..arr_len-1));
  assigns \nothing;
  
  ensures \result >= 0;
  ensures \forall integer k; 0 <= k < arr_len ==> arr[k] == \old(arr[k]);
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
