#include <stddef.h>

int findEvenPair(int * arr, int arr_len, int n);

int findEvenPair(int * arr, int arr_len, int n) {

		if (arr == NULL) {
			return -1;
		}
		if (arr_len == 1) {
			return 0;
		}

		int evenPairCount = 0;
		for (int i = 0; i < arr_len; i++) {
			for (int c = i + 1; c < arr_len; c++) {
				int even = arr[i];
				int odd = arr[c];
				int z = even ^ odd;
				if ((z & 1) == 0) {
					evenPairCount++;
				}
			}
		}
		return evenPairCount;
}
