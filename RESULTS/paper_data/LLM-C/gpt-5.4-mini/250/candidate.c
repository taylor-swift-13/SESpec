/*@
    requires args_len > 0;
    requires \valid_read(args + (0 .. args_len - 1));
    requires 0 <= start <= stop < args_len;
    requires \forall integer i; start <= i < stop ==> args[i] >= i;
    assigns \nothing;
    ensures start <= \result <= stop + 1;
    ensures \forall integer i; start <= i < \result ==> args[i] >= i;
    ensures \result == stop + 1 || args[\result] < \result;
*/
int findFirstMissing(int * args, int args_len, int start, int stop);

int findFirstMissing(int * args, int args_len, int start, int stop) {

		int result = start;
		int total = stop;
		int mid;

		/*@
            loop invariant start <= result <= stop + 1;
            loop invariant start - 1 <= total < stop;
            loop invariant result <= total + 1;
            loop invariant \forall integer i; start <= i < result ==> args[i] >= i;
            loop invariant \forall integer i; total < i <= stop ==> args[i] < i;
            loop assigns result, total, mid;
            loop variant total - result + 1;
        */
		while (result <= total) {
			mid = (result + total) / 2;
			int i = args[mid];

			if (i == mid) {
				result = mid + 1;
			} else if (i < mid) {
				result = mid + 1;
			} else {
				total = mid - 1;
			}
		}
		return result;
}
