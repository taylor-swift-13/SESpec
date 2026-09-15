/*@
    requires \valid(args + (0..args_len-1));
    requires args_len > 0;
    requires start >= 0 && stop >= start && stop < args_len;
    ensures \result >= start && \result <= stop + 1;
    ensures \forall integer i; start <= i < \result ==> args[i] == i;
    ensures \result == stop + 1 || args[\result] != \result;
    assigns \nothing;
*/
int findFirstMissing(int * args, int args_len, int start, int stop);

int findFirstMissing(int * args, int args_len, int start, int stop) {

		int found = start;
		int total = stop;
		int mid;

		/*@
		    loop invariant start <= found <= total + 1;
		    loop invariant total >= start - 1 && total < args_len;
		    loop invariant \forall integer i; start <= i < found ==> args[i] == i;
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
