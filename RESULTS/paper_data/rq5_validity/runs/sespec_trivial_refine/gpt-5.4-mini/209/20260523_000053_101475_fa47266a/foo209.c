
        /*@
        
        */

/*@
  requires \valid_read(arr + (0 .. arr_len - 1));
  requires 0 <= width < arr_len;

  requires \valid_read(ranges + (0 .. ranges_len - 1));
  requires 0 <= array <= ranges_len;
  requires \forall integer i; 0 <= i < array ==> \valid_read(ranges[i] + (0 .. 1));
  assigns \nothing;
  ensures \result == arr[foo209_width(ranges, array - 1, width)];
  ensures \result == arr[foo209_width(ranges, array - 1, width)];
  ensures \result == arr[width] <==> \forall integer i; 0 <= i < array ==> !(ranges[i][0] <= width && ranges[i][1] >= width);
*/
int foo209(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int width) {

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= r + 1 <= array;
          loop invariant 0 <= width < arr_len;
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
