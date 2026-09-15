/*@
    requires args_len >= 0;
    requires \valid_read(args + (0 .. args_len - 1));
    assigns \nothing;
    ensures \result >= 1;
    ensures \result <= array;
*/
int findMissing(int * args, int args_len, int array);

 /*@
    requires args_len >= 0;
    requires \valid_read(args + (0 .. args_len - 1));
    assigns \nothing;
    ensures \result >= 1;
    ensures \result <= array;
*/
int findMissing(int * args, int args_len, int array) {

		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		/*@
		    loop invariant 1 <= remaining <= array + 1;
		    loop invariant 1 <= found <= array;
		    loop invariant \forall integer i; 1 <= i < remaining ==> args[i - 1] == i;
		    loop assigns remaining, found;
		    loop variant array - remaining + 1;
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
