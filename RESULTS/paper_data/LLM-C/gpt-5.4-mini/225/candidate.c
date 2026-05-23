/*@ 
    requires args_len >= 0;
    requires \valid_read(args + (0 .. args_len - 1));
    requires array >= 0;
    requires args_len >= array;
    assigns \nothing;
    ensures \result >= 1;
    ensures (array == 0 || array == 1) ==> \result == 1;
    ensures (array > 1) ==> (\result >= 1 && \result <= array);
*/
int findMissing(int * args, int args_len, int array);

 /*@ 
    requires args_len >= 0;
    requires \valid_read(args + (0 .. args_len - 1));
    requires array >= 0;
    requires args_len >= array;
    assigns \nothing;
    ensures \result >= 1;
    ensures (array == 0 || array == 1) ==> \result == 1;
    ensures (array > 1) ==> (\result >= 1 && \result <= array);
*/
int findMissing(int * args, int args_len, int array) {

		int find = 1;
		if (array == 0 || array == 1) {
			return find;
		}
		/*@
		    loop invariant 1 <= remaining <= array + 1;
		    loop invariant 1 <= find <= remaining - 1;
		    loop invariant \forall integer i; 1 <= i < remaining ==> args[i - 1] == i;
		    loop assigns remaining, find;
		    loop variant array - remaining + 1;
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
