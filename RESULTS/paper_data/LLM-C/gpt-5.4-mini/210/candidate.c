/*@
    requires \valid_read(arr + (0 .. arr_len - 1));
    requires ranges_len >= array;
    requires ranges_rows >= array;
    requires ranges_cols >= 2;
    requires \valid_read(ranges + (0 .. ranges_rows - 1));
    requires \forall integer r; 0 <= r < array ==> \valid_read(ranges[r] + (0 .. ranges_cols - 1));
    requires 0 <= array;
    requires 0 <= count < arr_len;
    assigns count;
    ensures \valid_read(arr + \old(count));
*/
int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int count);

int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int count) {
		/*@
		    loop invariant 0 <= r < array;
		    loop invariant 0 <= count < arr_len;
		    loop assigns r, count;
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
