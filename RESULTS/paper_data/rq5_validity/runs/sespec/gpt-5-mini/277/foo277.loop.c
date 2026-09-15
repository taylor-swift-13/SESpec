
/*@ 
  logic integer min_prefix(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : (hi == lo + 1 ? a[lo]
               : (min_prefix(a, lo, hi-1) < a[hi-1] ? min_prefix(a, lo, hi-1) : a[hi-1]));
*/

/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/
 
/*@ 
  requires arg_len >= 1;
  requires \valid_read(arg + (0..arg_len-1));
*/
int foo277(int * arg, int arg_len) {

		int g = 0;
		int ret = arg[0];
		
        /*@
          loop invariant 1 <= j <= arg_len;
          loop invariant 0 <= g;
          loop invariant ret == min_prefix(arg, 0, j);
          loop invariant \exists integer t; 0 <= t < j && ret == arg[t];
          loop invariant \forall integer k; 0 <= k < arg_len ==> arg[k] == \at(arg[k], Pre);
          loop invariant (!(j < arg_len)) ==> ( ret == min_prefix(arg,0,arg_len) );
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
