/*@
    requires arr_len > 0;
    requires \valid_read(arr + (0 .. arr_len-1));
    assigns \nothing;
    ensures \result == (\max integer i; 0 <= i < arr_len; arr[i]) - (\min integer i; 0 <= i < arr_len; arr[i]);
*/
int bigDiff(int * arr, int arr_len);

int bigDiff(int * arr, int arr_len) {

		int result = arr[0];
		int sum = arr[0];
		/*@
		    loop invariant 1 <= n <= arr_len;
		    loop invariant \forall integer i; 0 <= i < n ==> arr[i] <= result;
		    loop invariant \forall integer i; 0 <= i < n ==> arr[i] >= sum;
		    loop invariant \exists integer i; 0 <= i < n && arr[i] == result;
		    loop invariant \exists integer i; 0 <= i < n && arr[i] == sum;
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
