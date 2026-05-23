
        /*@
        */

/*@
  requires 0 <= array <= args_len;
  requires array == 0 || \valid_read(args + (0..array-1));
  assigns \nothing;
  ensures array <= 1 ==> \result == 1;
  ensures array > 1 && (\forall integer i; 1 <= i <= array ==> args[i - 1] == i) ==> \result == array;
  ensures array > 1 && \exists integer i; 1 <= i <= array && args[i - 1] != i ==> 1 <= \result <= array;
  ensures array > 1 && \exists integer i; 1 <= i < \result ==> args[i - 1] == i;
  ensures array > 1 && \result <= array ==> args[\result - 1] != \result;
  ensures \result >= 1;
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
