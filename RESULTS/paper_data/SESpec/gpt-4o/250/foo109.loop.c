
/*@
  logic integer array_sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : array_sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic boolean is_sorted(int* a, integer lo, integer hi) =
    lo >= hi - 1 ? \true : (a[lo] <= a[lo + 1] && is_sorted(a, lo + 1, hi));
*/

/*@
  logic boolean binary_search_invariant(int* a, integer lo, integer hi, integer mid) =
    (lo <= mid && mid <= hi && is_sorted(a, lo, hi));
*/

int foo109(int * args, int args_len, int start, int stop) {

		int result = start;
		int total = stop;
		int mid;

		/*@
          loop invariant (!(\at(start,Pre) <= \at(stop,Pre))) ==> ((total == \at(stop,Pre))&&(result == \at(start,Pre))&&(stop == \at(stop,Pre))&&(start == \at(start,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant stop == \at(stop,Pre);
          loop invariant start == \at(start,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre);
          loop assigns mid, result, total;
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
