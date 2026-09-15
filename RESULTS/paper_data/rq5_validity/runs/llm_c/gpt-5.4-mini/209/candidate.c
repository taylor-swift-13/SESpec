/*@
    requires \valid_read(arr + (0 .. arr_len - 1));
    requires arr_len > 0;
    requires 0 <= width < arr_len;
    requires 0 <= array;
    requires \valid_read(ranges + (0 .. ranges_len - 1));
    requires \forall integer r; 0 <= r < array ==> \valid_read(ranges[r] + (0 .. ranges_cols - 1));
    assigns \nothing;
    ensures \result == arr[width];
*/
int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int width);

int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int width) {

		/*@
		    loop invariant -1 <= r < array;
		    loop invariant 0 <= width < arr_len;
		    loop invariant \valid_read(arr + (0 .. arr_len - 1));
		    loop invariant \valid_read(ranges + (0 .. ranges_len - 1));
		    loop invariant \forall integer k; 0 <= k < array ==> \valid_read(ranges[k] + (0 .. ranges_cols - 1));
		    loop assigns r, width;
		    loop variant r + 1;
		*/
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
