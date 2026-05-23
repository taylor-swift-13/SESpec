
/*@
  // Running minimum of a slice: min of a[lo..hi-1], with hi>lo
  logic integer min_slice(int* a, integer lo, integer hi) =
    lo + 1 >= hi ? a[lo]
                 : \min(min_slice(a, lo, hi - 1), a[hi - 1]);

  // ret equals the minimum over the already scanned prefix [0..j]
  predicate ret_is_min_prefix(int* a, integer j, integer ret) =
    j >= 0 ==> ret == min_slice(a, 0, j + 1);
*/

/*@
  requires \valid_read(arg + (0..\at(arg_len,Pre)-1));
  requires \at(arg_len,Pre) > 0 && \at(arg_len,Pre) < 100;
*/
int foo277(int * arg, int arg_len) {

		int g = 0;
		int ret = arg[0];
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= j <= \at(arg_len,Pre);
          loop invariant arg_len == \at(arg_len,Pre);
          loop invariant arg == \at(arg,Pre);
          loop invariant \valid_read(arg + (0..\at(arg_len,Pre)-1));
          loop invariant \forall integer k; 0 <= k < \at(arg_len,Pre) ==> arg[k] == \at(arg[k],Pre);
          loop invariant ret_is_min_prefix(arg, j-1, ret);
          loop invariant (j < \at(arg_len,Pre)) ==> (ret_is_min_prefix(arg, j-1, ret));
          loop invariant arg_len == \at(arg_len,Pre);
          loop invariant arg == \at(arg,Pre);
          loop invariant \forall integer k; 0 <= k < \at(arg_len,Pre) ==> arg[k] == \at(arg[k],Pre);
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
