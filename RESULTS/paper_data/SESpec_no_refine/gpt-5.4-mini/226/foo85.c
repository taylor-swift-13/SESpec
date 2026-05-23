
/*@
*/

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;
  ensures (array == 0 || array == 1) ==> \result == 1;
  ensures array > 1 ==> ((\forall integer k; 1 <= k <= array ==> args[k - 1] == k) ? \result == array : \result == 1);
*/
int foo85(int * args, int args_len, int array) {

		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		
        /*@
          loop invariant 1 <= remaining <= array + 1;
          loop invariant 1 <= found <= array;
          loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] == k;
          loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> found >= k;
          loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] == k ==> found == k || found > k;
          loop invariant args_len == args_len;
          loop assigns remaining, found;
        */
        /*@
          loop invariant (!(remaining <= array)) ==> ();
          loop invariant \forall integer i; 0 <= i < args_len ==> args[i] == \at(args[i], Pre);
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
