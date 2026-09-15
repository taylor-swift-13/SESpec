
int foo225(int * args, int args_len, int array) {

		int find = 1;
		if (array == 0 || array == 1) {
			return find;
		}
		
            
        /*@
          loop invariant 1 <= remaining;
          loop invariant 1 <= find;
          loop invariant find == remaining || find == remaining - 1;
          loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] == k;
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
