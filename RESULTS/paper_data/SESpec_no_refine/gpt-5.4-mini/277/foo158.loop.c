
/*@ 
  logic integer max_prefix(int* a, integer lo, integer hi) =
    lo >= hi ? a[lo]
             : (a[hi - 1] > max_prefix(a, lo, hi - 1) ? a[hi - 1] : max_prefix(a, lo, hi - 1));
*/

int foo158(int * arg, int arg_len) {

		int g = 0;
		int ret = arg[0];
		
            
        /*@
          loop invariant arg_len == \at(arg_len,Pre);
          loop invariant arg == \at(arg,Pre);
          loop invariant \forall integer k; 0 <= k < arg_len ==> arg[k] == \at(arg[k],Pre);
          loop invariant arg_len == \at(arg_len,Pre);
          loop invariant arg == \at(arg,Pre);
          loop invariant \forall integer k; 0 <= k < arg_len ==> arg[k] == \at(arg[k],Pre);
          loop assigns j, g, ret;
            */
            for (int j = 1; j < arg_len; j++) {
			if (arg[j] > ret) {
				g = g > ret ? g : ret;
			} else {
				ret = arg[j];
			}
		}
            
		return g;
}
