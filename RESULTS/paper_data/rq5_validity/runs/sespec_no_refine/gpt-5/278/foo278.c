
/*@
  logic integer min_slice(int *a, integer lo, integer hi) =
    lo >= hi ? 2147483647 :
      (min_slice(a, lo, hi-1) < a[hi-1] ? min_slice(a, lo, hi-1) : a[hi-1]);

  predicate unchanged_array{L}(int *a, integer n) =
    \forall integer k; 0 <= k < n ==> a[k] == \at(a[k], L);
*/

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;
  ensures unchanged_array{Pre}(args, args_len);
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
