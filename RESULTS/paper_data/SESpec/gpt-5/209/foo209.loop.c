


int foo209(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int width) {

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant array == \at(array, Pre);
          loop invariant ranges == \at(ranges, Pre);
          loop invariant arr == \at(arr, Pre);
          loop invariant ranges_len == \at(ranges_len, Pre);
          loop invariant ranges_rows == \at(ranges_rows, Pre);
          loop invariant ranges_cols == \at(ranges_cols, Pre);
          loop invariant arr_len == \at(arr_len, Pre);
          loop invariant (r >= 0) ==> (0 <= r && r < array);
          loop invariant (r == array - 1) ==> (width == \at(width, Pre));
          loop assigns r, width;
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
