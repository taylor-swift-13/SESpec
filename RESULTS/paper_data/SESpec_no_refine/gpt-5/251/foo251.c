
/*@
  // No additional predicates or logic functions are required.
*/

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;
  ensures args == \old(args);
  ensures args_len == \old(args_len);
  ensures \forall integer k; 0 <= k < args_len ==> args[k] == \old(args[k]);
  ensures start > stop ==> \result == start;
  ensures start <= stop ==> start <= \result <= stop + 1;
  ensures start <= stop ==> (\forall integer k; start <= k < \result ==> args[k] <= k);
  ensures start <= stop ==> (\forall integer k; \result <= k <= stop ==> args[k] > k);
  ensures \result == \result;
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
