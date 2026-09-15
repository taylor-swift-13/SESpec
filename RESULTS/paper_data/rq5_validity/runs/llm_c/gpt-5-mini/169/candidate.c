int findRotationCount(int * arr, int arr_len);

/*@
    requires arr_len >= 0;
    requires arr_len == 0 || \valid(arr + (0 .. arr_len-1));
    // The array is a rotation of a strictly increasing sequence:
    // there exists a pivot p such that, cyclically starting at p, the sequence is strictly increasing.
    requires arr_len <= 1 || (\exists integer p; 0 <= p < arr_len &&
             \forall integer j; 1 <= j < arr_len ==>
                 arr[(p + j - 1) % arr_len] < arr[(p + j) % arr_len]);
    assigns \nothing;
    ensures arr_len == 0 ==> \result == 0;
    ensures arr_len > 0 ==>
        0 <= \result < arr_len &&
        (\forall integer j; 0 <= j < arr_len ==> arr[\result] <= arr[j]);
*/
int findRotationCount(int * arr, int arr_len) {

		int r = 0;
		int stop = arr_len - 1;
		/*@
		    loop invariant 0 <= r && r <= arr_len;
		    loop invariant -1 <= stop && stop <= arr_len - 1;
		    loop invariant arr_len <= 1 || (
		        \exists integer p; 0 <= p < arr_len &&
		            \forall integer j; 1 <= j < arr_len ==>
		                arr[(p + j - 1) % arr_len] < arr[(p + j) % arr_len] &&
		            (r <= stop ==> r <= p && p <= stop)
		    );
		    loop assigns r, stop;
		    loop variant stop - r + 1;
		*/
		while (r <= stop) {
			int i = r + (stop - r) / 2;
			if (i < stop
					&& arr[i] > arr[i + 1]) {
				return i + 1;
			} else if (i > r
					&& arr[i] < arr[i - 1]) {
				return i;
			}
			if (arr[i] >= arr[r]) {
				r = i + 1;
			} else {
				stop = i - 1;
			}
		}
		return 0;
}
