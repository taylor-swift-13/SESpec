

/*@
  requires 0 <= array <= args_len;
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  assigns \nothing;
  ensures array <= 1 ==> \result == 1;
  ensures array > 1 && (\exists integer k; 1 <= k <= array && args[k - 1] != k) ==> 1 <= \result <= array;
  ensures array > 1 && (\exists integer k; 1 <= k <= array && args[k - 1] != k) ==> args[\result - 1] != \result;
  ensures array > 1 && (\exists integer k; 1 <= k <= array && args[k - 1] != k) ==> (\forall integer j; 1 <= j < \result ==> args[j - 1] == j);
*/
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
