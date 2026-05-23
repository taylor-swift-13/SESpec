
/*@ 
  logic integer prefix_mismatch(int* args, integer lo, integer hi) =
    lo >= hi ? 0 :
    prefix_mismatch(args, lo, hi - 1) +
    (args[hi - 1] == hi ? 0 : 1);
*/

int foo83(int * args, int args_len, int array) {

		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		
        /*@
          loop invariant found < num ==> args[found - 1] == found;
          loop invariant \forall integer k; 1 <= k < num ==> (args[k - 1] == k);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
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
