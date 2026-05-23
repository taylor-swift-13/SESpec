int findFirstMissing(int * args, int args_len, int start, int stop);

/*@
    requires 0 <= start && start <= stop && stop < args_len;
    requires \valid(args + (0 .. args_len-1));
    assigns \nothing;
    ensures start <= \result && \result <= stop + 1;
    ensures \forall integer j; start <= j < \result ==> args[j] <= j;
    ensures \forall integer j; \result <= j <= stop ==> args[j] > j;
*/
int findFirstMissing(int * args, int args_len, int start, int stop) {

		int found = start;
		int total = stop;
		int mid;

		/*@
		    loop invariant start <= found;
		    loop invariant found <= total + 1;
		    loop invariant total <= stop;
		    loop invariant \forall integer j; start <= j < found ==> args[j] <= j;
		    loop invariant \forall integer j; total < j <= stop ==> args[j] > j;
		    loop assigns found, total, mid;
		    loop variant total - found + 1;
		*/
		while (found <= total) {
			mid = (found + total) / 2;
			int i = args[mid];

			if (i == mid) {
				found = mid + 1;
			} else if (i < mid) {
				found = mid + 1;
			} else {
				total = mid - 1;
			}
		}
		return found;
}
