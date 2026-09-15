
/*@
  logic integer minp(int* a, integer lo, integer hi) =
    hi <= lo ? 0 :
    (hi == lo + 1 ? a[lo] :
     (minp(a, lo, hi - 1) <= a[hi - 1] ? minp(a, lo, hi - 1) : a[hi - 1]));
*/

/*@ 
  requires arg_len >= 1;
  requires \valid_read(arg + (0 .. arg_len - 1));
*/
int foo277(int * arg, int arg_len) {

		int g = 0;
		int ret = arg[0];
		
            
        /*@
          loop invariant 1 <= j <= arg_len;
          loop invariant ret == minp(arg, 0, j);
          loop invariant \forall integer k; 0 <= k < j ==> ret <= arg[k];
          loop invariant 0 <= g;
          loop invariant \exists integer k; 0 <= k < arg_len && ret == arg[k];
          loop invariant (j < arg_len) ==> (ret == minp(arg, 0, j));
          loop invariant (!(j < arg_len)) ==> (ret == minp(arg, 0, arg_len));
          loop invariant \forall integer k; 0 <= k < arg_len ==> arg[k] == \at(arg[k], Pre);
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
