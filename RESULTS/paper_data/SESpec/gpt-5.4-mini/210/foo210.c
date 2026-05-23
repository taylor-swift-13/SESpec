

/*@
  requires \valid(arr + (0 .. arr_len - 1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires \valid(ranges + (0 .. array - 1));
  requires \forall integer i; 0 <= i < array ==> \valid(ranges[i] + (0 .. 1));
  assigns \nothing;
  ensures \true;
  ensures \true;
  ensures \true;
  ensures \true;
  ensures \true;
  ensures \true;
*/
int foo210(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int count) {

        
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant r < array;
          loop assigns r, count;
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
