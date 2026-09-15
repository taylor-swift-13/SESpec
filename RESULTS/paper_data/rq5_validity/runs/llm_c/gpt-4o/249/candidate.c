/*@
    requires \valid(args + (0 .. args_len - 1));
    requires 0 <= start <= stop < args_len;
    requires \forall integer i; 0 <= i < args_len - 1 ==> args[i] <= args[i+1];
    ensures \result >= start && \result <= stop + 1;
    ensures \forall integer i; start <= i < \result ==> \exists integer j; 0 <= j < args_len && args[j] == i;
    ensures \result <= stop ==> \forall integer j; 0 <= j < args_len ==> args[j] != \result;
    assigns \nothing;
*/
int findFirstMissing(int * args, int args_len, int start, int stop);

int findFirstMissing(int * args, int args_len, int start, int stop) {

		int found = start;
		int num = stop;
		int mid;

		/*@
        loop invariant start <= found <= stop + 1;
        loop invariant start <= num + 1 <= stop + 1;
        loop invariant \forall integer i; start <= i < found ==> \exists integer j; 0 <= j < args_len && args[j] == i;
        loop invariant \forall integer i; num + 1 <= i <= stop ==> \forall integer j; 0 <= j < args_len ==> args[j] != i;
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
