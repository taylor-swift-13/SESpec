/*@
    requires \valid(arr+(0..arr_len-1));
    requires arr_len > 0;
    ensures \exists integer i; 0 <= i < arr_len && arr[i] == \result + \min(arr[0..arr_len-1]);
    ensures \result == \max(arr[0..arr_len-1]) - \min(arr[0..arr_len-1]);
    assigns \nothing;
*/
int bigDiff(int * arr, int arr_len);

int bigDiff(int * arr, int arr_len) {

		int big = arr[0];
		int sum = arr[0];
		/*@
		    loop invariant 1 <= n <= arr_len;
		    loop invariant \forall integer i; 0 <= i < n ==> big >= arr[i];
		    loop invariant \forall integer i; 0 <= i < n ==> sum <= arr[i];
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
