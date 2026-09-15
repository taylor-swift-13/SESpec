
/*@
  logic integer min_slice(int *a, integer lo, integer hi) =
    lo >= hi ? 2147483647 :
      (min_slice(a, lo, hi-1) < a[hi-1] ? min_slice(a, lo, hi-1) : a[hi-1]);

  predicate unchanged_array{L}(int *a, integer n) =
    \forall integer k; 0 <= k < n ==> a[k] == \at(a[k], L);
*/
        
int foo278(int * args, int args_len) {

		int ret = 0;
		int tmp = args[0];
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant unchanged_array{Pre}(args, args_len) ;
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
