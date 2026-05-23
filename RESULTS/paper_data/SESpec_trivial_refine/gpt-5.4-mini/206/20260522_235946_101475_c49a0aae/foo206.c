
/*@
*/

/*@
  loop invariant 0 <= ret <= args_len;
  loop invariant 0 <= r <= arr_len;
  loop assigns ret, r;
*/

/*@
  requires 0 <= args_len;
  requires 0 <= arr_len;
  requires args_len == 0 || \valid_read(args + (0 .. args_len-1));
  requires arr_len == 0 || \valid_read(arr + (0 .. arr_len-1));
  assigns \nothing;
  ensures 0 <= \result;
  ensures \result <= args_len;
  ensures \result <= arr_len;
  ensures args_len == 0 || arr_len == 0 ==> \result == 0;
  ensures (args_len > 0 && arr_len > 0) ==> (\result < args_len || \result < arr_len);
*/
int foo206(int * args, int args_len, int * arr, int arr_len, int array) {

		int ret = 0;
		int r = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= ret <= args_len;
          loop invariant 0 <= r <= arr_len;
          loop assigns ret, r;
            */
            while (ret < args_len && r < arr_len) {
			if (args[ret] < arr[r]) {
				ret++;
			} else if (args[ret] > arr[r]) {
				r++;
			} else {
				ret++;
				r++;
			}
		}
            
		return ret < args_len ? ret : r;
}
