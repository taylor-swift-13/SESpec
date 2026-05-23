
        /*@
        */
        
int foo225(int * args, int args_len, int array) {

		int find = 1;
		if (array == 0 || array == 1) {
			return find;
		}
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= remaining <= array + 1;
          loop invariant remaining == 1 ==> find == 1;
          loop invariant remaining > 1 ==> find == remaining - 1;
          loop invariant \forall integer i; 1 <= i < remaining ==> args[i - 1] == i;
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
