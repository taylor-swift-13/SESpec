int findLastOccurrence(int * arr, int arr_len, int array);

int findLastOccurrence(int * arr, int arr_len, int array) {

		int i = 0;
		int hi = arr_len - 1;
		int end = 0;
		/*@
		loop invariant 0 <= i <= arr_len;
		loop invariant -1 <= hi < arr_len;
		loop invariant 0 <= end < arr_len || arr_len == 0;
		loop invariant i <= hi + 1;
		loop invariant end <= hi + 1;
		loop invariant end < arr_len;
		loop invariant \forall integer k; 0 <= k < i ==> arr[k] <= array;
		loop invariant \forall integer k; hi < k < arr_len ==> arr[k] > array;
		loop invariant end == (i + hi) / 2 || end == 0;
		loop invariant i == 0 || 0 <= i <= arr_len;
		loop invariant i <= hi + 1;
		loop invariant i <= end + 1;
		loop invariant i <= arr_len;
		loop invariant hi == arr_len - 1 || -1 <= hi < arr_len;
		loop invariant hi <= arr_len - 1;
		loop invariant hi < arr_len;
		loop invariant end >= 0 || arr_len == 0;
		loop invariant end == 0 || end >= i - 1;
		loop invariant end == 0 || (0 <= end < arr_len);
		loop invariant end <= hi || i > hi;
		loop invariant end <= hi + 1;
		loop invariant end <= arr_len - 1;
		loop invariant end <= arr_len - 1 || end <= hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < hi + 1;
		loop invariant end < arr_len;
		loop invariant end < arr_len || arr_len == 0;
		loop invariant end < arr_len - 1;
		loop invariant \forall integer k; hi < k < arr_len ==> arr[k] >= array;
		loop invariant \forall integer k; hi < k < arr_len ==> arr[k] > array;
		loop invariant \forall integer k; 0 <= k < i ==> arr[k] <= array;
		loop invariant \forall integer k; 0 <= k < i ==> arr[k] < array;
		loop invariant 0 <= i;
		loop invariant 0 <= end;
		loop invariant 0 <= end < arr_len || arr_len == 0;
		loop invariant -1 <= hi;
		loop invariant -1 <= end;
		loop assigns i;
		loop assigns hi;
		loop assigns end;
		*/
		while (i <= hi) {
			end = (i + hi) / 2;
			if (arr[end] == array) {
				if (end == arr_len - 1
						|| arr[end + 1] != array) {
					return end;
				} else {
					i = end + 1;
				}
			} else if (arr[end] < array) {
				i = end + 1;
			} else {
				hi = end - 1;
			}
		}
		return -1;
}
