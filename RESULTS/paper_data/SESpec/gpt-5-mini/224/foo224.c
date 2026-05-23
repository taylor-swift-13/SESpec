
/*@
  logic boolean prefix_matches(int* args, integer lo, integer hi) =
    lo >= hi ? \true
             : prefix_matches(args, lo, hi - 1) && args[hi - 1] == hi;
*/

/*@
  logic integer last_match(int* args, integer n) =
    n <= 0 ? 0
          : (prefix_matches(args, 1, n) ? n : last_match(args, n - 1));
*/

/*@ logic integer first_mismatch(int* args, integer n) =
      n <= 0 ? 0
            : (args[n-1] != n ? n : first_mismatch(args, n-1));
*/
/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;
  ensures (array == 0 || array == 1) ==> \result == 1;
      
*/
int foo224(int * args, int args_len, int array) {

		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		
        /*@
          loop invariant prefix_matches(args, 1, num - 1);
          loop assigns num, found;
        */
        for (int num = 1; num <= array; num++) {
			if (args[num - 1] == num) {
				found = num;
			} else if (args[num - 1] != num) {
				return num;
			}
		}
            
		return found;
}
