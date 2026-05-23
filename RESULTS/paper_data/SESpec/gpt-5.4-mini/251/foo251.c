
/*@
  requires \valid(args + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  assigns \nothing;
*/
int foo251(int * args, int args_len, int start, int stop) {

		int found = start;
		int total = stop;
		int mid;

		
            
        /*@
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (found <= total + 1);
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (found >= \at(start,Pre));
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (total <= \at(stop,Pre));
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (found <= \at(stop,Pre) + 1);
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (total >= \at(start,Pre) - 1);
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (args_len == \at(args_len,Pre));
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (args == \at(args,Pre));
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (\forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre));
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (((total == \at(stop,Pre))&&(found == \at(start,Pre))&&(stop == \at(stop,Pre))&&(start == \at(start,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (found <= total + 1));
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (((total == \at(stop,Pre))&&(found == \at(start,Pre))&&(stop == \at(stop,Pre))&&(start == \at(start,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (total <= \at(stop,Pre)));
          loop invariant (!(\at(start,Pre) <= \at(stop,Pre))) ==> ((total == \at(stop,Pre))&&(found == \at(start,Pre))&&(stop == \at(stop,Pre))&&(start == \at(start,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant stop == \at(stop,Pre);
          loop invariant start == \at(start,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant (\forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre));
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
