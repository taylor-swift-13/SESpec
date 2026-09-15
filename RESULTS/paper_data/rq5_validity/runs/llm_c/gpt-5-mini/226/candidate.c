int findMissing(int * args, int args_len, int array);

/*@
    requires array >= 0;
    requires args_len >= array;
    requires array == 0 || \valid(args + (0 .. array-1));
    assigns \nothing;
    behavior has_missing:
        assumes \exists int i; 1 <= i <= array && args[i-1] != i;
        ensures 1 <= \result <= array;
        ensures args[\result-1] != \result;
        ensures \forall int j; 1 <= j < \result ==> args[j-1] == j;
    behavior no_missing:
        assumes \forall int i; 1 <= i <= array ==> args[i-1] == i;
        ensures \result == (array == 0 ? 1 : array);
    complete behaviors has_missing, no_missing;
    disjoint behaviors has_missing, no_missing;
*/
int findMissing(int * args, int args_len, int array) {

		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		/*@
		    loop invariant 1 <= remaining <= array + 1;
		    loop invariant \forall int j; 1 <= j < remaining ==> args[j-1] == j;
		    loop invariant found == (remaining == 1 ? 1 : remaining-1);
		    loop assigns found, remaining;
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
