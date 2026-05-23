
int foo171(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int c) {

		int result = 0;
		int tmp = 0;

        /*@
          loop invariant result + tmp == count;
          loop assigns count, result, tmp;
        */
            for (int count = 0; count < c; count++) {
			if (result < Array
					&& (tmp >= n || arr1[result] <= arr[tmp])) {
				if (count == c - 1) {
					return arr1[result];
				}
				result++;
			} else {
				if (count == c - 1) {
					return arr[tmp];
				}
				tmp++;
			}
		}
            
		return -1;
}
