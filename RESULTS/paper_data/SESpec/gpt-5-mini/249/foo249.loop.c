
/*@
  logic integer count_fix(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : count_fix(a, lo, hi - 1) + (a[hi - 1] == (int)(hi - 1) ? 1 : 0);
*/

/*@
  requires \valid(args + (0 .. args_len-1));
  requires \at(args_len,Pre) > 0 && \at(args_len,Pre) < 100;
*/
int foo249(int * args, int args_len, int start, int stop) {

		int found = start;
		int num = stop;
		int mid;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \at(start,Pre) == start;
          loop invariant \at(stop,Pre) == stop;
          loop invariant \at(args_len,Pre) == args_len;
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre);
          loop invariant found >= \at(start,Pre);
          loop invariant num <= \at(stop,Pre);
          loop assigns mid, found, num;
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
