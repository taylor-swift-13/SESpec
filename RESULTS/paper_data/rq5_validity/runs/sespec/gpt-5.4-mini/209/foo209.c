
/*@ logic integer foo209_final_width(int **ranges, integer array, integer width) =
      array <= 0 ? width :
      foo209_final_width(ranges, array - 1,
        ((ranges[array - 1][0] <= width && ranges[array - 1][1] >= width) ?
          ((ranges[array - 1][0] == width) ? ranges[array - 1][1] : width - 1) :
          width)); */
/*@
  requires arr_len > 0;
  requires 0 <= width < arr_len;
  requires array >= 0;
  requires \valid_read(arr + (0 .. arr_len - 1));
  requires \valid_read(ranges + (0 .. array - 1));
  requires \forall integer i; 0 <= i < array ==> \valid_read(ranges[i] + (0 .. 1));
  requires \forall integer i; 0 <= i < array ==> 0 <= ranges[i][0] < arr_len;
  requires \forall integer i; 0 <= i < array ==> 0 <= ranges[i][1] < arr_len;
  assigns \nothing;
  ensures \valid_read(arr + (0 .. arr_len - 1));
  ensures 0 <= width < arr_len;
  ensures \forall integer i; 0 <= i < array ==>
            (ranges[i][0] > \at(width, Pre) || ranges[i][1] < \at(width, Pre) ||
             width <= ranges[i][1]);
*/
int foo209(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int width) {


        /*@
          loop invariant -1 <= r < array;
          loop invariant 0 <= width < arr_len;
          loop invariant array == \at(array,Pre);
          loop invariant ranges_cols == \at(ranges_cols,Pre);
          loop invariant ranges_rows == \at(ranges_rows,Pre);
          loop invariant ranges_len == \at(ranges_len,Pre);
          loop invariant ranges == \at(ranges,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer i; 0 <= i < ranges_len ==> ranges[i][0] == \at(ranges[i][0],Pre);
          loop invariant \forall integer i; 0 <= i < ranges_len ==> ranges[i][1] == \at(ranges[i][1],Pre);
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
