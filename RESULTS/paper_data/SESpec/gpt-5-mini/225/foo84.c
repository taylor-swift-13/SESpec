
/*@
  predicate valid_args(int* a, integer n) =
    n >= 0 && \valid(a + (0..n-1));
*/

/*@ 
  requires array >= 1;
  requires \valid(args + (0..array-1));
  requires args_len >= 0;
  assigns \nothing;
  ensures (\exists integer i; 1 <= i <= \result - 1 ==> args[i-1] == \at(args[i-1], Pre));
*/
int foo84(int * args, int args_len, int array) {

		int find = 1;
		if (array == 0 || array == 1) {
			return find;
		}
		
        /*@
          loop invariant 1 <= remaining <= array + 1;
          loop invariant 1 <= find <= remaining;
          loop invariant \forall integer k; 0 <= k < array ==> args[k] == \at(args[k], Pre);
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
