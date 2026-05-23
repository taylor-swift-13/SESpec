
/*@
  requires args_len > 0;
  requires args_len < 100;
  requires \valid(&args[0] + (0 .. args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  assigns \nothing;
*/
int foo83(int * args, int args_len, int array) {

		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		
        /*@
          loop invariant 1 <= num;
          loop invariant array >= 1 ==> num <= array + 1;
          loop invariant 1 <= found <= num;
          loop invariant \forall integer k; 1 <= k < num && args[k-1] == k ==> k <= found;
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
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
