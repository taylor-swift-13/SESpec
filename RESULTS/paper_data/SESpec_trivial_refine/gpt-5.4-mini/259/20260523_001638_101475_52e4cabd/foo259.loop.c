
/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/
        
int foo259(int * args, int args_len, int array) {

		int i = 0;
		int stop = array - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i;
          loop invariant stop < array;
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
