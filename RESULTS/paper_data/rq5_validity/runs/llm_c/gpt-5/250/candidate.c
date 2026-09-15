int findFirstMissing(int * args, int args_len, int start, int stop);

/*@
  requires args_len >= 0;
  requires \valid_read(args + (0 .. args_len-1));
  requires 0 <= start <= stop < args_len;

  // Strictly increasing by at least 1 ensures monotonicity of (args[i] > i)
  requires \forall integer k; 0 <= k < args_len-1 ==> args[k+1] >= args[k] + 1;

  assigns \nothing;

  // Result is a boundary between indices with args[k] <= k and those with args[k] > k
  ensures start <= \result <= stop + 1;

  // All indices before result satisfy args[k] <= k
  ensures \forall integer k; start <= k < \result ==> args[k] <= k;

  // All indices from result to stop satisfy args[k] > k
  ensures \forall integer k; \result <= k <= stop ==> args[k] > k;

  // Minimality: if there exists an index with args[k] > k, result is the smallest such index
  ensures (\exists integer j; start <= j <= stop && args[j] > j) ==>
          (start <= \result <= stop &&
           args[\result] > \result &&
           (\forall integer k; start <= k < \result ==> args[k] <= k));

  // If no such index exists in [start..stop], result is stop+1
  ensures (\forall integer k; start <= k <= stop ==> args[k] <= k) ==> \result == stop + 1;
*/
int findFirstMissing(int * args, int args_len, int start, int stop) {

		int result = start;
		int total = stop;
		int mid;

		/*@
		  loop invariant start <= result <= stop + 1;
		  loop invariant -1 <= total <= stop;
		  loop invariant result <= total + 1;
		  loop invariant \forall integer k; start <= k < result ==> args[k] <= k;
		  loop invariant \forall integer k; total + 1 <= k <= stop ==> args[k] > k;
		  loop assigns result, total, mid;
		  loop variant (total - result + 1);
		*/
		while (result <= total) {
			mid = (result + total) / 2;

			/*@ assert result <= mid <= total; */
			/*@ assert start <= mid <= stop; */
			/*@ assert 0 <= mid < args_len; */

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
