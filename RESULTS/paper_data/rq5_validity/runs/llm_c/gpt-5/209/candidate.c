/*@ 
  logic integer transform_index{L}(integer w, int ** ranges, integer n)
    decreases n;
  =
    n <= 0 ? w :
      transform_index{L}(
        (
          (\at(ranges[n-1][0],L) <= w && \at(ranges[n-1][1],L) >= w)
          ? ((w == \at(ranges[n-1][0],L)) ? \at(ranges[n-1][1],L) : w - 1)
          : w
        ),
        ranges, n - 1
      );
*/

int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int width);

/*@ 
  requires arr != \null;
  requires arr_len > 0;
  requires \valid_read(arr + (0..arr_len-1));

  requires ranges != \null;
  requires 0 <= array <= ranges_rows;
  requires ranges_cols >= 2;
  requires \valid(ranges + (0..array-1));
  requires \forall integer r; 0 <= r < array ==> \valid_read(ranges[r] + (0..ranges_cols-1));

  requires 0 <= width < arr_len;
  requires \forall integer r; 0 <= r < array ==> 0 <= ranges[r][0] < arr_len && 0 <= ranges[r][1] < arr_len;

  assigns \nothing;

  ensures 0 <= width < arr_len;
  ensures width == transform_index{Pre}(\old(width), ranges, array);
  ensures \result == arr[width];
*/
int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int width) {

		/*@ 
		  loop invariant -1 <= r < array;
		  loop invariant 0 <= width < arr_len;
		  loop variant r + 1;
		*/
		for (int r = array - 1; r >= 0; r--) {
			int j = ranges[r][0];
			int top = ranges[r][1];
			if (j <= width && top >= width) {
				if (width == j) {
					width = top;
				} else {
					//@ assert width >= 1;
					width = width - 1;
				}
			}
		}
		return arr[width];
}
