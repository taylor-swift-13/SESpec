
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100 && \at(ranges_len,Pre) > 0 && \at(ranges_len,Pre) < 100;
  assigns width;
  ensures (\at(array,Pre) <= 0) ==> (width == \at(width,Pre) && \result == arr[\at(width,Pre)]);
  ensures (\at(array,Pre) > 0) ==> (
            (\exists integer k; 0 <= k <= \at(array,Pre) - 1 &&
              (\exists integer m; k <= m <= \at(array,Pre) - 1 &&
                \at(ranges[k],Pre)[0] <= \at(width,Pre) &&
                \at(ranges[k],Pre)[1] >= \at(width,Pre) &&
                ((\forall integer t; k <= t <= m ==> \at(ranges[t],Pre)[0] <= \at(width,Pre) &&
                                                   \at(ranges[t],Pre)[1] >= \at(width,Pre))) &&
                ((\at(ranges[m],Pre)[0] == \at(width,Pre)) ?
                   width == \at(ranges[m],Pre)[1] :
                   width == \at(width,Pre) - 1)) ) )
            && \result == arr[width]);
*/
int foo67(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int width) {


        /*@
          loop invariant (r >= 0) ==> (((width == \at(width,Pre))&&(array == \at(array,Pre))&&(ranges_cols == \at(ranges_cols,Pre))&&(ranges_rows == \at(ranges_rows,Pre))&&(ranges_len == \at(ranges_len,Pre))&&(ranges == \at(ranges,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (PLACE_HOLDER_width));
          loop invariant (!(r >= 0)) ==> ((width == \at(width,Pre))&&(array == \at(array,Pre))&&(ranges_cols == \at(ranges_cols,Pre))&&(ranges_rows == \at(ranges_rows,Pre))&&(ranges_len == \at(ranges_len,Pre))&&(ranges == \at(ranges,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant ranges_cols == \at(ranges_cols,Pre);
          loop invariant ranges_rows == \at(ranges_rows,Pre);
          loop invariant ranges_len == \at(ranges_len,Pre);
          loop invariant ranges == \at(ranges,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant PLACE_HOLDER_UNCHANGED_ARRAY_ranges ;
          loop assigns r, j, top, width;
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
