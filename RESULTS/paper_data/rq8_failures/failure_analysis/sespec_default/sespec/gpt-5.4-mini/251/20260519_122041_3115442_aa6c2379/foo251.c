
/*@
  requires \at(args_len,Pre) > 0;
  requires \at(args_len,Pre) < 100;
  requires start <= stop + 1;
  assigns \nothing;
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
          loop invariant found >= \at(start,Pre);
          loop invariant total <= \at(stop,Pre);
          loop invariant found <= total + 1;
          loop invariant total >= \at(start,Pre) - 1;
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
