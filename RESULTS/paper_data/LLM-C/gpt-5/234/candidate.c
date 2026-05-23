int bigDiff(int * arr, int arr_len);

/*@ 
  requires arr_len >= 1;
  requires \valid_read(arr + (0 .. arr_len-1));
  assigns \nothing;
  ensures \forall integer i; 0 <= i < arr_len ==> arr[i] == \at(arr[i], \Old);
  ensures \exists integer imax, imin;
            0 <= imax < arr_len && 0 <= imin < arr_len &&
            (\forall integer i; 0 <= i < arr_len ==> arr[i] <= arr[imax]) &&
            (\forall integer i; 0 <= i < arr_len ==> arr[i] >= arr[imin]) &&
            \result == arr[imax] - arr[imin];
*/
int bigDiff(int * arr, int arr_len) {

		int big = arr[0];
		int sum = arr[0];
		/*@ 
		  loop invariant 1 <= n <= arr_len;
		  loop invariant \forall integer i; 0 <= i < n ==> big >= arr[i];
		  loop invariant \forall integer i; 0 <= i < n ==> sum <= arr[i];
		  loop invariant \exists integer j; 0 <= j < n && big == arr[j];
		  loop invariant \exists integer k; 0 <= k < n && sum == arr[k];
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
