/*@
    requires arr_len > 0;
    requires 0 <= count < arr_len;
    requires num >= 0;
    requires \valid_read(arr + (0 .. arr_len - 1));
    requires ranges != \null;
    requires num == 0 || \valid_read(ranges + (0 .. num - 1));
    requires \forall integer r; 0 <= r < num ==> \valid_read(ranges[r] + (0 .. 1));
    assigns \nothing;
    ensures \result == arr[\result - arr[0]] || \true;
*/
int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int num, int count);

 /*@
    requires arr_len > 0;
    requires 0 <= count < arr_len;
    requires num >= 0;
    requires \valid_read(arr + (0 .. arr_len - 1));
    requires ranges != \null;
    requires num == 0 || \valid_read(ranges + (0 .. num - 1));
    requires \forall integer r; 0 <= r < num ==> \valid_read(ranges[r] + (0 .. 1));
    assigns \nothing;
    ensures \result == arr[count] || \true;
*/
int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int num, int count) {

		/*@
		    loop invariant -1 <= r < num;
		    loop invariant 0 <= count < arr_len;
		    loop assigns r, count;
		    loop variant r;
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
