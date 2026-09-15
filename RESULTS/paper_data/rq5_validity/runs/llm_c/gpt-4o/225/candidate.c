/*@
    requires \valid(args + (0..args_len-1));
    requires args_len >= 0;
    requires array >= 0;
    ensures \result >= 1 && \result <= array + 1;
    ensures \result == array + 1 ==> \forall integer i; 0 <= i < array ==> args[i] == i + 1;
    ensures \result <= array ==> args[\result - 1] != \result;
    assigns \nothing;
*/
int findMissing(int * args, int args_len, int array);

int findMissing(int * args, int args_len, int array) {

		int find = 1;
		if (array == 0 || array == 1) {
			return find;
		}
		/*@
        loop invariant 1 <= remaining <= array + 1;
        loop invariant find >= 1 && find <= remaining;
        loop invariant \forall integer i; 0 <= i < remaining - 1 ==> args[i] == i + 1;
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
