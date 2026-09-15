int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int num, int count);

/*@
  requires arr != \null;
  requires arr_len >= 0;
  requires \valid_read(arr + (0 .. arr_len-1));

  requires ranges != \null;
  requires 0 <= num;
  requires ranges_rows >= num;
  requires ranges_cols >= 2;
  requires \valid_read(ranges + (0 .. num-1));
  requires \forall integer r; 0 <= r < num ==> (ranges[r] != \null && \valid_read(ranges[r] + (0 .. ranges_cols-1)));

  requires 0 <= count < arr_len;
  requires \forall integer r; 0 <= r < num ==> 0 <= ranges[r][0] <= ranges[r][1] < arr_len;

  assigns \nothing;

  ensures 0 <= count < arr_len;
  ensures \result == arr[count];
*/
int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int num, int count) {

		/*@
		  loop invariant 0 <= r < num ==> 0 <= count < arr_len;
		  loop invariant 0 <= count < arr_len;
		  loop invariant 0 <= r + 1 <= num;
		  loop invariant \valid_read(arr + (0 .. arr_len-1));
		  loop invariant \valid_read(ranges + (0 .. num-1));
		  loop invariant \forall integer k; 0 <= k < num ==> (ranges[k] != \null && \valid_read(ranges[k] + (0 .. 1)));
		  loop invariant \forall integer k; 0 <= k < num ==> 0 <= ranges[k][0] <= ranges[k][1] < arr_len;
		  loop assigns r, count;
		  loop variant r + 1;
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
