
        /*@
        */
        
int foo205(int * args, int args_len, int * arr, int arr_len, int Array) {

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
