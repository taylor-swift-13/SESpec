
/*@
  logic integer count_fix(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : count_fix(a, lo, hi - 1) + (a[hi - 1] == (int)(hi - 1) ? 1 : 0);
*/

/*@
  predicate unchanged_array{L1, L2}(int* a, integer lo, integer hi) =
    \forall integer k; lo <= k < hi ==> \at(a[k], L1) == \at(a[k], L2);
*/

int foo110(int * args, int args_len, int start, int stop) {

		int found = start;
		int total = stop;
		int mid;

		
            
        /*@
          loop invariant (!(\at(start,Pre) <= \at(stop,Pre))) ==> ((total == \at(stop,Pre))&&(found == \at(start,Pre))&&(stop == \at(stop,Pre))&&(start == \at(start,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant stop == \at(stop,Pre);
          loop invariant start == \at(start,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant unchanged_array{Pre,Here}(args, 0, args_len);
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
