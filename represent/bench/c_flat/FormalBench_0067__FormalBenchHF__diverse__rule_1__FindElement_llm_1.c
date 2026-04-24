int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int width);

int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int width) {

		for (int r = array - 1; r >= 0; r--) {
			int j = ranges[r][0];
			int top = ranges[r][1];
			if (j <= width && top >= width) {
				if (width == j) {
					width = top;
				} else {
					width = width - 1;
				}
			}
		}
		return arr[width];
}
