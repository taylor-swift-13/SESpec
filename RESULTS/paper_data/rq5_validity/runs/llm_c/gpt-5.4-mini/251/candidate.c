/*@
    requires args_len > 0;
    requires \valid_read(args + (0 .. args_len - 1));
    requires 0 <= start <= stop < args_len;
    assigns \nothing;
    ensures start <= \result <= stop + 1;
*/
int findFirstMissing(int * args, int args_len, int start, int stop);

 /*@
    requires args_len > 0;
    requires \valid_read(args + (0 .. args_len - 1));
    requires 0 <= start <= stop < args_len;
    assigns \nothing;
    ensures start <= \result <= stop + 1;
*/
int findFirstMissing(int * args, int args_len, int start, int stop) {

		int found = start;
		int total = stop;
		int mid;

		/*@
		    loop invariant start <= found <= stop + 1;
		    loop invariant start - 1 <= total < stop;
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
