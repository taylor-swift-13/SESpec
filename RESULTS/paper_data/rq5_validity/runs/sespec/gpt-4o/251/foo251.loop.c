
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

int foo251(int * args, int args_len, int start, int stop) {

		int found = start;
		int total = stop;
		int mid;

        /*@
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
          loop invariant stop == \at(stop, Pre);
          loop invariant start == \at(start, Pre);
          loop invariant args_len == \at(args_len, Pre);
          loop invariant args == \at(args, Pre);
          loop assigns mid, found, total;
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
