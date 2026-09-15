
int foo226(int * args, int args_len, int array) {

		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		
        /*@
          loop invariant 1 <= found <= remaining;
          loop invariant \forall integer k; 0 <= k < remaining - 1 ==> args[k] == k + 1;
          loop invariant found == 1 || (\exists integer k; 1 <= k < remaining && found == k && args[k - 1] == k);
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
