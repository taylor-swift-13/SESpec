int findFirstMissing(int * args, int args_len, int start, int stop);

 /*@
     requires 0 <= start <= stop < args_len;
     requires \valid(args + (start .. stop));
     assigns \nothing;
     ensures start <= \result <= stop + 1;
     ensures \forall integer j; start <= j < \result ==> args[j] <= j;
     ensures \forall integer j; \result <= j <= stop ==> args[j] > j;
 */
int findFirstMissing(int * args, int args_len, int start, int stop) {

		int found = start;
		int num = stop;
		int mid;

		/*@
		    loop invariant start <= found;
		    loop invariant num <= stop;
		    loop invariant start-1 <= num;
		    loop invariant found <= stop + 1;
		    loop invariant \forall integer j; start <= j < found ==> args[j] <= j;
		    loop invariant \forall integer j; num < j <= stop ==> args[j] > j;
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
