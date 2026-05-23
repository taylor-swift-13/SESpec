
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);

  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  requires \valid(arr + (0..arr_len-1));
  requires \valid(ranges + (0..ranges_len-1));
  requires \forall integer i; 0 <= i < ranges_len ==> \valid(ranges[i] + (0..ranges_cols-1));
  requires arr_len > 0 && arr_len < 100;
  requires ranges_len > 0 && ranges_len < 100;
  ensures \result == arr[\at(count, Pre)];
  assigns count;
*/
int foo68(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int count) {

        /*@
          loop invariant 0 <= r < array;
          loop invariant \forall integer i; 0 <= i < ranges_len ==> \valid(ranges[i] + (0..ranges_cols-1));
          loop invariant count >= 0 && count < arr_len;
          loop invariant array == \at(array, Pre);
          loop invariant ranges_cols == \at(ranges_cols, Pre);
          loop invariant ranges_rows == \at(ranges_rows, Pre);
          loop invariant ranges_len == \at(ranges_len, Pre);
          loop invariant ranges == \at(ranges, Pre);
          loop invariant arr_len == \at(arr_len, Pre);
          loop invariant arr == \at(arr, Pre);
          loop assigns r, j, top, count;
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
