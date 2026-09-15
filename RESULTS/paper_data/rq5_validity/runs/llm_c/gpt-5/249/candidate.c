int findFirstMissing(int * args, int args_len, int start, int stop);

/*@ 
  requires args_len >= 0;
  requires start >= 0;
  requires start > stop || (0 <= start && start <= stop && stop < args_len);
  requires start > stop || (\forall integer i; start <= i < stop ==> args[i] < args[i+1]);
  assigns \nothing;
  ensures start <= \result && \result <= stop + 1;
  ensures start > stop ==> \result == start;
  ensures (\forall integer j; start <= j && j <= stop && j < \result ==> args[j] <= j);
  ensures \result <= stop ==> args[\result] > \result;
*/
int findFirstMissing(int * args, int args_len, int start, int stop) {

		int found = start;
		int num = stop;
		int mid;

		/*@
		  loop invariant start <= found && found <= num + 1;
		  loop invariant num <= stop;
		  loop invariant (\forall integer k; start <= k < found ==> args[k] <= k);
		  loop invariant (\forall integer k; num < k <= stop ==> args[k] > k);
		  loop variant num - found + 1;
		*/
		while (found <= num) {
			mid = (found + num) / 2;
			//@ assert 0 <= mid < args_len;
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
