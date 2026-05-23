
/*@
  assigns \nothing;
*/
int foo159(int * args, int args_len) {
		int ret = 0;
		int tmp = args[0];
		
        /*@
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre);
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
