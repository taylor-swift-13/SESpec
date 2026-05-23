
/*@
  // No additional predicates or logic functions are required.
*/

int foo209(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int width) {

        /* >>> LOOP INVARIANT TO FILL <<< */
        /*@
          loop invariant array == array;
          loop invariant ranges_cols == ranges_cols;
          loop invariant ranges_rows == ranges_rows;
          loop invariant ranges_len == ranges_len;
          loop invariant ranges == ranges;
          loop invariant arr_len == arr_len;
          loop invariant arr == arr;

          loop invariant -1 <= r <= array - 1;
          loop invariant 0 <= array;
          loop invariant 0 <= ranges_len;

          loop invariant 0 <= width < arr_len;

          loop assigns r, width, j, top;
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
