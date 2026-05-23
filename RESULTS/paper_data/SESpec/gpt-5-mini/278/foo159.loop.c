
/*@
  logic integer min_prefix(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : min_prefix(a, lo, hi - 1);
*/

/*@
  logic integer max_of_greater(int* a, integer begin, integer end, integer init_min) =
    begin >= end ? 0
    : max_of_greater(a, begin, end-1, init_min)
        + (a[end-1] > init_min ? (a[end-1]) : 0);
*/

/*@
  predicate seen_properties(int* a, integer seen_len, integer cur_min, integer cur_ret, integer init_len, int* init_a) =
    0 <= seen_len <= init_len
    &&
    \true;
*/

/*@
  requires \valid(args + (0 .. args_len-1));
  requires \at(args_len,Pre) > 0 && \at(args_len,Pre) < 100;
  assigns \nothing;
*/
int foo159(int * args, int args_len) {

		int ret = 0;
		int tmp = args[0];
		
            
        /*@
          loop invariant 1 <= j <= \at(args_len,Pre);
          loop invariant \exists integer p; 0 <= p < j && tmp == \at(args[p],Pre);
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
