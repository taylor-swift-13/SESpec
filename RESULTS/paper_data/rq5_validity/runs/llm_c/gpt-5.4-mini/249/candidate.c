/*@
    requires args_len > 0;
    requires 0 <= start <= stop < args_len;
    requires \valid_read(args + (0 .. args_len - 1));
    assigns \nothing;
    ensures start <= \result <= stop + 1;
*/
int findFirstMissing(int * args, int args_len, int start, int stop);

 /*@
    requires args_len > 0;
    requires 0 <= start <= stop < args_len;
    requires \valid_read(args + (0 .. args_len - 1));
    assigns \nothing;
    ensures start <= \result <= stop + 1;
*/
int findFirstMissing(int * args, int args_len, int start, int stop) {

		int found = start;
		int num = stop;
		int mid;

		/*@
            loop invariant start <= found <= stop + 1;
            loop invariant start - 1 <= num <= stop;
            loop invariant found <= num + 1;
            loop invariant \valid_read(args + (0 .. args_len - 1));
            loop assigns found, num, mid;
            loop variant num - found + 1;
        */
		while (found <= num) {
			mid = (found + num) / 2;
			int i = args[mid];

			if (i == mid) {
				found = mid + 1;
			} else if (i < mid) {
				found = mid + 1;
			} else {
				num = mid - 1;
			}
		}
		return found;
}
