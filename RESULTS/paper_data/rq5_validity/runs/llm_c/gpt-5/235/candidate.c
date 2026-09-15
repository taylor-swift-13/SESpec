int bigDiff(int * arr, int arr_len);

/*@
  requires arr_len >= 1;
  requires \valid_read(arr + (0 .. arr_len-1));
  assigns \nothing;
  ensures \exists integer i, j;
            0 <= i < arr_len && 0 <= j < arr_len &&
            (\forall integer k; 0 <= k < arr_len ==> arr[i] >= arr[k] && arr[j] <= arr[k]) &&
            \result == arr[i] - arr[j];
  ensures \result >= 0;
*/
int bigDiff(int * arr, int arr_len) {

		int result = arr[0];
		int sum = arr[0];
		/*@
		  loop invariant 1 <= n <= arr_len;
		  loop invariant \forall integer k; 0 <= k < n ==> sum <= arr[k] <= result;
		  loop invariant \exists integer iR; 0 <= iR < n && result == arr[iR];
		  loop invariant \exists integer iS; 0 <= iS < n && sum == arr[iS];
		  loop invariant result >= sum;
		  loop assigns result, sum, n;
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
