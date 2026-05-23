int findFirstMissing(int * args, int args_len, int start, int stop);

 /*@
     requires 0 <= start <= stop < args_len;
     requires \valid_read(args + (start .. stop));
     assigns \nothing;
     ensures start <= \result && \result <= stop + 1;
     ensures \forall integer j; start <= j < \result ==> args[j] <= j;
     ensures \forall integer j; \result <= j <= stop ==> args[j] > j;
 */
int findFirstMissing(int * args, int args_len, int start, int stop) {

		int result = start;
		int total = stop;
		int mid;

		/*@
		    loop invariant start <= result && result <= total + 1 && total <= stop;
		    loop invariant \forall integer j; start <= j < result ==> args[j] <= j;
		    loop invariant \forall integer j; total + 1 <= j <= stop ==> args[j] > j;
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
