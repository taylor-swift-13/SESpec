
/*@ 
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

int foo84(int * args, int args_len, int array) {

		int find = 1;
		if (array == 0 || array == 1) {
			return find;
		}
		
        /*@
          loop invariant 1 <= remaining <= array + 1;
          loop invariant 1 <= find < remaining;
          loop invariant \forall integer k; 1 <= k < remaining ==>
                            args[k - 1] == k ==> find >= k;
          loop invariant \forall integer k; 1 <= k < remaining ==>
                            args[k - 1] != k ==> find != k;
          loop invariant \forall integer k; 1 <= k < remaining ==>
                            args[k - 1] == k || args[k - 1] != k;
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
          loop invariant array == \at(array, Pre);
          loop invariant args_len == \at(args_len, Pre);
        */
            /*@
          loop invariant (!(remaining <= array)) ==> ();
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
