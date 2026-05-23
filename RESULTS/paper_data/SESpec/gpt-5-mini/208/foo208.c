
/*@ 
  /* count_after_ranges_rec(ranges, lo, hi, c0) computes the value of
     count after processing ranges at indices lo .. hi-1 (in increasing
     order), where processing a single range (j,t) transforms c as:
       if j <= c && t >= c then (c == j ? t : c-1) else c
  */
  logic integer count_after_ranges_rec(int * *ranges, integer lo, integer hi, integer c0) =
    lo >= hi ? c0
             : count_after_ranges_rec(ranges, lo, hi - 1,
                 ( (ranges[hi-1][0] <= c0 && ranges[hi-1][1] >= c0)
                     ? (c0 == ranges[hi-1][0] ? ranges[hi-1][1] : c0 - 1)
                     : c0));
*/

/*@ 
  logic integer count_after_ranges_rec(int * *ranges, integer lo, integer hi, integer c0) =
    lo >= hi ? c0
             : count_after_ranges_rec(ranges, lo, hi - 1,
                 ( (ranges[hi-1][0] <= c0 && ranges[hi-1][1] >= c0)
                     ? (c0 == ranges[hi-1][0] ? ranges[hi-1][1] : c0 - 1)
                     : c0));
*/
/*@
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100 && \at(ranges_len,Pre) > 0 && \at(ranges_len,Pre) < 100;
  requires \valid_read(arr + (0 .. \at(arr_len,Pre)-1));
  requires \valid_read(ranges + (0 .. \at(ranges_len,Pre)-1));
  requires \forall integer i; 0 <= i < \at(ranges_len,Pre) ==> \valid_read(ranges[i] + (0 .. 1));
  assigns \nothing;
  ensures count == \at(count,Pre) || count == count_after_ranges_rec(ranges, 0, num, \at(count,Pre));
  ensures \result == arr[
             (num <= 0 ? \at(count,Pre) : count_after_ranges_rec(ranges, 0, num, \at(count,Pre)))
          ];
*/
int foo208(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int num, int count) {

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant -1 <= r < num;
              loop invariant (r >= 0) ==> (0 <= count && count < arr_len);
              loop invariant (r >= 0) ==> (count == count_after_ranges_rec(ranges, r+1, num, \at(count,Pre)));
              loop invariant (!(r >= 0)) ==> (count == \at(count,Pre) || count == count_after_ranges_rec(ranges, 0, num, \at(count,Pre)));
              loop invariant num == \at(num,Pre);
              loop invariant ranges_cols == \at(ranges_cols,Pre);
              loop invariant ranges_rows == \at(ranges_rows,Pre);
              loop invariant ranges_len == \at(ranges_len,Pre);
              loop invariant ranges == \at(ranges,Pre);
              loop invariant arr_len == \at(arr_len,Pre);
              loop invariant arr == \at(arr,Pre);
              loop assigns r, j, top, count;
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
