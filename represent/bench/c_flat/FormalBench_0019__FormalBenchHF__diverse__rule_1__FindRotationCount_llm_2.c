int findRotationCount(int * arr, int arr_len);

int findRotationCount(int * arr, int arr_len) {

		int ret = 0;
		int count = arr_len - 1;
		while (ret <= count) {
			int r = ret + (count - ret) / 2;
			if (r < count
					&& arr[r] > arr[r + 1]) {
				return r + 1;
			} else if (r > ret
					&& arr[r] < arr[r - 1]) {
				return r;
			}
			if (arr[r] >= arr[ret]) {
				ret = r + 1;
			} else {
				count = r - 1;
			}
		}
		return 0;
}
