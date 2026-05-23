
/*@
  logic integer min_prefix(int *a, integer lo, integer hi) =
    lo + 1 >= hi ? a[lo]
                 : (a[hi - 1] < min_prefix(a, lo, hi - 1) ? a[hi - 1] : min_prefix(a, lo, hi - 1));
*/

/*@
  requires args_len >= 1;
  requires \valid_read(args + (0 .. args_len - 1));
*/
int foo278(int * args, int args_len) {

		int ret = 0;
		int tmp = args[0];
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= j <= args_len;
          loop invariant tmp == min_prefix(args, 0, j);
          loop invariant ret >= 0;
          loop invariant (j < args_len) ==> (ret >= 0);
          loop invariant (!(j < args_len)) ==> (tmp == min_prefix(args, 0, args_len));
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
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
