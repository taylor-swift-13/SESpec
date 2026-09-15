/*@
    requires \valid(arr+(0..arr_len-1));
    requires arr_len > 0;
    ensures \result == (\max(0, arr_len-1, arr) - \min(0, arr_len-1, arr));
    assigns \nothing;
*/
int bigDiff(int * arr, int arr_len);

int bigDiff(int * arr, int arr_len) {

		int result = arr[0];
		int num = arr[0];
		/*@
		    loop invariant 1 <= n <= arr_len;
		    loop invariant \forall integer i; 0 <= i < n ==> result >= arr[i];
		    loop invariant \forall integer i; 0 <= i < n ==> num <= arr[i];
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
