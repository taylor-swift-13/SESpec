

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  requires 0 <= array <= args_len;
  assigns \nothing;
  ensures (array == 0 || array == 1) ==> \result == 1;
            (\forall integer r; 1 <= r <= array ==> args[r - 1] == r) && \result == 1
          );
*/
int foo225(int * args, int args_len, int array) {

		int find = 1;
		if (array == 0 || array == 1) {
			return find;
		}
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
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
