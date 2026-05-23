/*@ 
  logic integer step(integer c, integer j, integer top) =
    (j <= c && c <= top) ? ((c == j) ? top : c - 1) : c;

  logic integer apply_rev{L}(int **ranges, integer n, integer c) =
    (n <= 0) ? c
             : apply_rev{L}(ranges, n - 1, step(c, \at(ranges[n-1][0], L), \at(ranges[n-1][1], L)));
*/

int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int count);

/*@ 
  requires arr_len > 0;
  requires array >= 0;
  requires ranges_len >= 0;
  requires ranges_cols >= 2;
  requires 0 <= array <= ranges_len;

  requires \valid_read(arr + (0 .. arr_len-1));
  requires \valid_read(ranges + (0 .. array-1));
  requires \forall integer i; 0 <= i < array ==> \valid_read(ranges[i] + (0 .. ranges_cols-1));

  requires 0 <= count < arr_len;

  // Each range is within array bounds and well-formed (j <= top), and j is non-negative
  requires \forall integer i; 0 <= i < array ==> 
             0 <= ranges[i][0] <= ranges[i][1] < arr_len;

  assigns \nothing;

  ensures \let final_count = apply_rev{Pre}(ranges, array, \old(count));
          0 <= final_count < arr_len && \result == \at(arr[final_count], Pre);
*/
int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int count) {

		/*@
		  loop invariant -1 <= r <= array - 1;
		  loop invariant 0 <= array;
		  loop invariant 0 <= count < arr_len;
		  loop assigns count;
		  loop variant r + 1;
		*/
		for (int r = array - 1; r >= 0; r--) {
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
