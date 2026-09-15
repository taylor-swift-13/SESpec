
/* No additional predicates or logic functions are needed. */

int foo279(int * args, int args_len) {

		int g = 0;
		int ret = args[0];
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (j < \at(args_len,Pre)) ==> (\forall integer k; 0 <= k < \at(args_len,Pre) ==> \at(args[k],Pre) == args[k]);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < \at(args_len,Pre) ==> \at(args[k],Pre) == args[k] ;
          loop assigns j, g, ret;
            */
            for (int j = 1; j < args_len; j++) {
			if (args[j] > ret) {
				g = g > ret ? g : ret;
			} else {
				ret = args[j];
			}
		}
            
		return g;
}
