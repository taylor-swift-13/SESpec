int bigDiff(int * arr, int arr_len);

/*@ 
  requires arr_len > 0;
  requires \valid_read(arr + (0 .. arr_len-1));
  assigns \nothing;
  ensures \exists integer i, j;
            0 <= i < arr_len && 0 <= j < arr_len &&
            (\forall integer k; 0 <= k < arr_len ==> arr[k] <= arr[i]) &&
            (\forall integer k; 0 <= k < arr_len ==> arr[k] >= arr[j]) &&
            \result == arr[i] - arr[j];
  ensures \result >= 0;
*/
int bigDiff(int * arr, int arr_len) {

		int result = arr[0];
		int num = arr[0];
		/*@
		  loop invariant 1 <= n <= arr_len;
		  loop invariant (\forall integer k; 0 <= k < n ==> arr[k] <= result);
		  loop invariant (\exists integer k; 0 <= k < n && result == arr[k]);
		  loop invariant (\forall integer k; 0 <= k < n ==> arr[k] >= num);
		  loop invariant (\exists integer k; 0 <= k < n && num == arr[k]);
		  loop assigns n, result, num;
		  loop variant arr_len - n;
		*/
		for (int n = 1; n < arr_len; n++) {
			if (arr[n] > result) {
				result = arr[n];
			}
			if (arr[n] < num) {
				num = arr[n];
			}
		}
		return result - num;
}
