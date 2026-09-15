int findLastOccurrence(int * arr, int arr_len, int array);

int findLastOccurrence(int * arr, int arr_len, int array) {

		int i = 0;
		int hi = arr_len - 1;
		int end = 0;
		/*@
		loop invariant 0 <= i <= arr_len;
		loop invariant -1 <= hi < arr_len;
		loop invariant i <= hi + 1;
		loop invariant end >= 0;
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
