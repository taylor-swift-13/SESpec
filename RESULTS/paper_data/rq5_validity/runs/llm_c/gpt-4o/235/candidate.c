/*@
    requires \valid_read(arr + (0..arr_len-1));
    requires arr_len > 0;
    ensures \result == (\max(0, arr_len-1, arr) - \min(0, arr_len-1, arr));
    assigns \nothing;
*/
int bigDiff(int * arr, int arr_len);

int bigDiff(int * arr, int arr_len) {

		int result = arr[0];
		int sum = arr[0];
		/*@
		loop invariant 1 <= n <= arr_len;
		loop invariant result == \max(0, n-1, arr);
		loop invariant sum == \min(0, n-1, arr);
		loop assigns n, result, sum;
		loop variant arr_len - n;
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
