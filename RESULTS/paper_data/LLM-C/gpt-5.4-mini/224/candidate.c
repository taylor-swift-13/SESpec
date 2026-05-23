/*@ 
    requires args_len >= 0;
    requires array >= 0;
    requires array <= args_len;
    requires \valid_read(args + (0 .. args_len - 1));
    assigns \nothing;
    ensures array == 0 || array == 1 ==> \result == 1;
    ensures array > 1 ==> 1 <= \result <= array;
*/
int findMissing(int * args, int args_len, int array);

 /*@ 
    requires args_len >= 0;
    requires array >= 0;
    requires array <= args_len;
    requires \valid_read(args + (0 .. args_len - 1));
    assigns \nothing;
    ensures array == 0 || array == 1 ==> \result == 1;
    ensures array > 1 ==> 1 <= \result <= array;
*/
int findMissing(int * args, int args_len, int array) {

		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		/*@
		    loop invariant 1 <= num <= array + 1;
		    loop invariant found == 1 || (1 <= found < num);
		    loop invariant \forall integer k; 1 <= k < num && args[k - 1] == k;
		    loop assigns num, found;
		    loop variant array - num + 1;
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
