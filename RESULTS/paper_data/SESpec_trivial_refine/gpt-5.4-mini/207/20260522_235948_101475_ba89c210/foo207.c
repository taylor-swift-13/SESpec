
        /*@
        */

/*@
  requires \valid_read(args + (0 .. args_len - 1));
  requires \valid_read(arr + (0 .. arr_len - 1));
  requires 0 <= args_len;
  requires 0 <= arr_len;
  assigns \result;
  ensures 0 <= \result;
  ensures args_len == 0 || arr_len == 0 ==> \result == 0;
  ensures \result < args_len || \result < arr_len;
  ensures \result <= arr_len;
  ensures \result == 0 ==> args_len == 0 || arr_len == 0;
  ensures \result == PLACE_HOLDER_RESULT;
*/
int foo207(int * args, int args_len, int * arr, int arr_len, int array) {

		int ret = 0;
		int len = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= ret <= args_len;
          loop invariant 0 <= len <= arr_len;
          loop assigns ret, len;
            */
            while (ret < args_len && len < arr_len) {
			if (args[ret] < arr[len]) {
				ret++;
			} else if (args[ret] > arr[len]) {
				len++;
			} else {
				ret++;
				len++;
			}
		}
            
		return ret < args_len ? ret : len;
}
