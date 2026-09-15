
/*@
  // Number of indices in [1,hi] such that args[k-1] != k. Useful to
  // express “no mismatch so far” as count == 0.
  logic integer count_mismatch(int* args, integer hi) =
    hi <= 0 ? 0
            : count_mismatch(args, hi - 1) + (args[hi - 1] != hi ? 1 : 0);
*/

/*@
  requires \valid_read(args + (0 .. args_len-1));
  requires args_len >= 0;
  // For safe indexed access args[remaining-1], we need array <= args_len.
  requires 0 <= array <= args_len;
  ensures \result == 1 ==> (array == 0 || array == 1);
*/
int foo225(int * args, int args_len, int array) {

		int find = 1;
		if (array == 0 || array == 1) {
			return find;
		}
		
        /*@ 
          loop invariant 1 <= remaining <= array + 1;
          loop invariant 1 <= find <= remaining;
          loop invariant count_mismatch(args, remaining - 1) == 0;
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
          loop assigns remaining, find;
        */
        for (int remaining = 1; remaining <= array; remaining++) {
			if (args[remaining - 1] == remaining) {
				find = remaining;
			} else if (args[remaining - 1] != remaining) {
				return remaining;
			}
		}
            
		return find;
}
