
/*@
*/

/*@
  loop invariant 0 <= ret <= args_len;
  loop invariant 0 <= r <= arr_len;
  loop assigns ret, r;
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
