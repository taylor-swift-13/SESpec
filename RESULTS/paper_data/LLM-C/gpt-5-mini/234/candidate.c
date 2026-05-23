int bigDiff(int * arr, int arr_len);

/*@
    requires arr_len > 0;
    requires \valid(arr + (0 .. arr_len-1));
    assigns \nothing;
    ensures \exists integer i_max, i_min;
                0 <= i_max < arr_len &&
                0 <= i_min < arr_len &&
                (\forall integer j; 0 <= j < arr_len ==> arr[j] <= arr[i_max]) &&
                (\forall integer j; 0 <= j < arr_len ==> arr[j] >= arr[i_min]) &&
                \result == arr[i_max] - arr[i_min];
*/
int bigDiff(int * arr, int arr_len) {

		int big = arr[0];
		int sum = arr[0];
		/*@
		    loop invariant 1 <= n <= arr_len;
		    loop invariant (\forall integer j; 0 <= j < n ==> arr[j] <= big);
		    loop invariant (\forall integer j; 0 <= j < n ==> arr[j] >= sum);
		    loop invariant (\exists integer k; 0 <= k < n && arr[k] == big);
		    loop invariant (\exists integer k; 0 <= k < n && arr[k] == sum);
		    loop assigns n, big, sum;
		    loop variant arr_len - n;
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
