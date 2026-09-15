
/*@
  predicate ranges_ok{L}(int **ranges, integer n, integer arr_len) =
    \valid_read(ranges + (0 .. n-1)) &&
    \forall integer i; 0 <= i < n ==>
      \valid_read(ranges[i] + (0 .. 1)) &&
      0 <= ranges[i][0] <= ranges[i][1] < arr_len;
*/

/*@
  requires arr_len > 0;
  requires \valid(arr + (0 .. arr_len-1));
  requires num >= 0;
  requires ranges_ok(ranges, num, arr_len);
  requires 0 <= count < arr_len;
*/
        
int foo208(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int num, int count) {

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant -1 <= r < num;
          loop invariant 0 <= count < arr_len;
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
