
/*@ 
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;
  ensures (\old(array) == 0 || \old(array) == 1) ==> \result == 1;
  ensures \old(array) > 1 && (\forall integer remaining; 1 <= remaining <= \old(array) ==> args[remaining - 1] == remaining) ==> \result == \old(array);
  ensures \old(array) > 1 && (\exists integer remaining; 1 <= remaining <= \old(array) && args[remaining - 1] != remaining) ==>
            (\result >= 1 && \result <= \old(array) && args[\result - 1] != \result);
*/
int foo84(int * args, int args_len, int array) {

		int find = 1;
		if (array == 0 || array == 1) {
			return find;
		}
		
        /*@
          loop invariant 1 <= remaining <= array + 1;
          loop invariant 1 <= find < remaining;
          loop invariant \forall integer k; 1 <= k < remaining ==>
                            args[k - 1] == k ==> find >= k;
          loop invariant \forall integer k; 1 <= k < remaining ==>
                            args[k - 1] != k ==> find != k;
          loop invariant \forall integer k; 1 <= k < remaining ==>
                            args[k - 1] == k || args[k - 1] != k;
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
          loop invariant array == \at(array, Pre);
          loop invariant args_len == \at(args_len, Pre);
        */
            /*@
          loop invariant (!(remaining <= array)) ==> ();
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
