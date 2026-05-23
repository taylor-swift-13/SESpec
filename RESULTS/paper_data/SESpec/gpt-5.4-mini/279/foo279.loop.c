
/*@
  logic integer max_prefix(int *args, integer lo, integer hi) =
    lo >= hi ? args[lo] :
    (max_prefix(args, lo, hi - 1) > args[hi - 1] ? max_prefix(args, lo, hi - 1) : args[hi - 1]);
*/

int foo279(int * args, int args_len) {

		int g = 0;
		int ret = args[0];
		
        /*@
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
          loop invariant (j < \at(args_len,Pre)) ==> (args_len == \at(args_len,Pre));
          loop invariant (j < \at(args_len,Pre)) ==> (args == \at(args,Pre));
          loop invariant (!(j < \at(args_len,Pre))) ==> (args_len == \at(args_len,Pre) && args == \at(args,Pre));
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
