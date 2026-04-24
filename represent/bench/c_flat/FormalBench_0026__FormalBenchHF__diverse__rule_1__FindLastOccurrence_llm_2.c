int findLastOccurrence(int * arr, int arr_len, int Array);

int findLastOccurrence(int * arr, int arr_len, int Array) {

		int i = 0;
		int hi = arr_len - 1;
		int end = 0;
		while (i <= hi) {
			end = (i + hi) / 2;
			if (arr[end] == Array) {
				if (end == arr_len - 1
						|| arr[end + 1] != Array) {
					return end;
				} else {
					i = end + 1;
				}
			} else if (arr[end] < Array) {
				i = end + 1;
			} else {
				hi = end - 1;
			}
		}
		return -1;
}
