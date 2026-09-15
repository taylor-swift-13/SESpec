

/*@
  requires args_len > 0;
  requires 0 <= array <= args_len;
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  assigns \nothing;
  ensures array <= 1 ==> \result == 1;
  ensures array > 1 ==> 1 <= \result;
  ensures array > 1 ==> \forall integer k; 1 <= k < \result ==> args[k - 1] == k;
  ensures array > 1 && \result < array ==> args[\result - 1] != \result;
  ensures array > 1 && \result == array ==> \forall integer k; 1 <= k < array ==> args[k - 1] == k;
  ensures \result == 1 || array > 1;
*/
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
