
/*@
  requires \valid_read(arr + (0 .. arr_len-1));
  requires arr_len >= 0;
  requires \valid_read(ranges + (0 .. ranges_len-1));
*/

int foo66_c208(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int num, int count) {

        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant r <= num - 1;
          loop invariant num == \at(num,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant ranges == \at(ranges,Pre);
          loop invariant ranges_len == \at(ranges_len,Pre);
          loop invariant ranges_rows == \at(ranges_rows,Pre);
          loop invariant ranges_cols == \at(ranges_cols,Pre);
          loop invariant 0 <= num ==> -1 <= r <= num - 1;
          loop assigns r, count;
            */
            for (int r = num - 1; r >= 0; r--) {
			int j = ranges[r][0];
			int top = ranges[r][1];
			if (j <= count && top >= count) {
				if (count == j) {
					count = top;
				} else {
					count = count - 1;
				}
			}
		}
            
		return arr[count];
}
