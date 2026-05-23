

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires 0 <= array <= args_len;
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  assigns \nothing;
  ensures array <= 1 ==> \result == 1;
  ensures array > 1 && (\forall integer k; 1 <= k <= array ==> args[k - 1] == k) ==> \result <= array + 1;
  ensures array > 1 && (\exists integer k; 1 <= k <= array && args[k - 1] != k) ==> 1 <= \result <= array + 1;
  ensures array > 1 && (\exists integer k; 1 <= k <= array && args[k - 1] != k) ==> 1 <= \result <= array + 1;
  ensures array > 1 && (\exists integer k; 1 <= k <= array && args[k - 1] != k) ==> 1 <= \result <= array + 1;
  ensures \result == 1 ==> (array <= 1 || (\exists integer k; 1 <= k <= array && args[k - 1] != k && k == 1));
*/
int foo224(int * args, int args_len, int array) {

		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		
        /*@
          loop invariant 1 <= num;
          loop invariant 1 <= found <= num;
          loop invariant found == num || found == num - 1;
          loop invariant (found == 1) || args[found - 1] == found;
          loop invariant \forall integer k; 0 <= k < num - 1 ==> args[k] == k + 1;
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
          loop invariant (num <= array) ==> (found <= array);
          loop invariant (array >= 1 && !(num <= array)) ==> (num == array + 1);
          loop assigns num, found;
        */
        for (int num = 1; num <= array; num++) {
			if (args[num - 1] == num) {
				found = num;
			} else if (args[num - 1] != num) {
				return num;
			}
		}
            
		return found;
}
