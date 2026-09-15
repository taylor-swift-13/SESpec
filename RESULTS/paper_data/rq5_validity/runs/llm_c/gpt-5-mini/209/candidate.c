/*@
    requires arr_len > 0;
    requires \valid(arr + (0 .. arr_len-1));
    requires ranges_rows >= 0;
    requires \valid(ranges + (0 .. ranges_rows-1));
    requires ranges_cols >= 2;
    requires 0 <= array <= ranges_rows;
    requires 0 <= width < arr_len;
    requires \forall integer i; 0 <= i < ranges_rows ==> \valid(ranges[i] + (0 .. ranges_cols-1));
    assigns \nothing;
    ensures 0 <= width < arr_len;
    ensures \result == arr[width];
*/
int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int width) {

		/*@
		    loop invariant -1 <= r && r < array;
		    loop invariant 0 <= width < arr_len;
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
