
/*@
*/

int foo85(int * args, int args_len, int array) {

		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		
        /*@
          loop invariant 1 <= remaining <= array + 1;
          loop invariant 1 <= found <= array;
          loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] == k;
          loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> found >= k;
          loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] == k ==> found == k || found > k;
          loop invariant args_len == args_len;
          loop assigns remaining, found;
        */
        /*@
          loop invariant (!(remaining <= array)) ==> ();
          loop invariant PLACE_HOLDER_UNCHANGED_ARRAY_args ;
          loop assigns remaining, found;
            */
            for (int remaining = 1; remaining <= array; remaining++) {
			if (args[remaining - 1] == remaining) {
				found = remaining;
			} else if (args[remaining - 1] != remaining) {
				return remaining;
			}
		}
            
		return found;
}
