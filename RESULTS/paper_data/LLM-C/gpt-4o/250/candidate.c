/*@
    requires \valid(args + (0 .. args_len - 1));
    requires 0 <= start <= stop < args_len;
    requires \forall integer i; 0 <= i < args_len - 1 ==> args[i] <= args[i+1];
    ensures \result >= start && \result <= stop + 1;
    ensures \forall integer i; start <= i < \result ==> \exists integer j; 0 <= j < args_len && args[j] == i;
    ensures \result <= stop ==> \forall integer j; 0 <= j < args_len ==> args[j] != \result;
    assigns \nothing;
*/
int findFirstMissing(int * args, int args_len, int start, int stop) {

		int result = start;
		int total = stop;
		int mid;

		/*@
        loop invariant start <= result <= total + 1;
        loop invariant start <= total + 1 <= stop + 1;
        loop invariant \forall integer i; start <= i < result ==> \exists integer j; 0 <= j < args_len && args[j] == i;
        loop invariant result <= stop + 1 ==> \forall integer j; 0 <= j < args_len ==> args[j] != result;
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
