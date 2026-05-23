
int foo226(int * args, int args_len, int array) {

		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		
        /*@
          loop invariant 1 <= remaining;
          loop invariant array < 1 || remaining <= array + 1;
          loop invariant 1 <= found <= remaining;
          loop invariant found == remaining || found == remaining - 1;
          loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] == k;
          loop invariant (remaining <= array) ==> found <= array;
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
