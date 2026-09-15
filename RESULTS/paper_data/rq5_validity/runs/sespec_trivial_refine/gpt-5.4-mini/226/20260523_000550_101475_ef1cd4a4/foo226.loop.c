
/*@
predicate prefix_ok(int *a, integer n) = 
  \forall integer i; 0 <= i < n ==> a[i] == i + 1;
*/

int foo226(int * args, int args_len, int array) {

		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant remaining >= 1;
          loop invariant 1 <= found <= remaining;
          loop invariant found >= remaining - 1;
          loop invariant \forall integer i; 0 <= i < remaining - 1 ==> args[i] == i + 1;
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
