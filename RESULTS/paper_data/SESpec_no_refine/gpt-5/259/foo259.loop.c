
/*@
  // No additional predicates or logic functions are required.
*/

int foo259(int * args, int args_len, int array) {

		int i = 0;
		int stop = array - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant array == \at(array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \valid_read(args + (0 .. args_len - 1));
          loop invariant stop < array;
          loop invariant 0 <= i <= stop + 1;
          loop assigns i, stop;
            */
            while (i <= stop) {
			int cur = i + (stop - i) / 2;
			if (args[cur] == cur) {
				return cur;
			} else if (args[cur] < cur) {
				i = cur + 1;
			} else {
				stop = cur - 1;
			}
		}
            
		return -1;
}
