
/*@ logic integer max_prefix(int *args, integer lo, integer hi) =
      hi <= lo ? args[lo]
               : (max_prefix(args, lo, hi - 1) > args[hi - 1] ? max_prefix(args, lo, hi - 1) : args[hi - 1]);
*/

int foo278(int * args, int args_len) {

		int ret = 0;
		int tmp = args[0];
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer i; 0 <= i < args_len ==> args[i] == \at(args[i],Pre) ;
          loop assigns j, ret, tmp;
            */
            for (int j = 1; j < args_len; j++) {
			if (args[j] > tmp) {
				ret = ret > tmp ? ret : tmp;
			} else {
				tmp = args[j];
			}
		}
            
		return ret;
}
