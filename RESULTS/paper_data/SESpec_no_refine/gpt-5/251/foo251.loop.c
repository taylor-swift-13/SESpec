
/*@
  // No additional predicates or logic functions are required.
*/

int foo251(int * args, int args_len, int start, int stop) {

		int found = start;
		int total = stop;
		int mid;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant start == \at(start,Pre);
          loop invariant stop == \at(stop,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre);
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (\at(start,Pre) <= found && total <= \at(stop,Pre));
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (found <= total + 1);
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (\forall integer k; \at(start,Pre) <= k < found ==> args[k] <= k);
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (\forall integer k; total < k <= \at(stop,Pre) ==> args[k] > k);
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
