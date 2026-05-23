
/*@
  logic integer array_unchanged(int* a, integer lo, integer hi) =
    lo >= hi ? 1 :
    (a[lo] == \at(a[lo], Pre) && array_unchanged(a, lo + 1, hi));
*/

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;
  ensures \result == found;
  ensures args == \at(args, Pre);
  ensures args_len == \at(args_len, Pre);
  ensures start == \at(start, Pre);
  ensures stop == \at(stop, Pre);
*/
int foo110(int * args, int args_len, int start, int stop) {

		int found = start;
		int total = stop;
		int mid;

		
            
        /*@
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (((total == \at(stop,Pre))&&(found == \at(start,Pre))&&(stop == \at(stop,Pre))&&(start == \at(start,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (found >= \at(start,Pre) && found <= \at(stop,Pre) + 1 && total == \at(stop,Pre)));
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (((total == \at(stop,Pre))&&(found == \at(start,Pre))&&(stop == \at(stop,Pre))&&(start == \at(start,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (total <= \at(stop,Pre) && total >= \at(start,Pre) - 1 && found == \at(start,Pre)));
          loop invariant (!(\at(start,Pre) <= \at(stop,Pre))) ==> ((total == \at(stop,Pre))&&(found == \at(start,Pre))&&(stop == \at(stop,Pre))&&(start == \at(start,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant stop == \at(stop,Pre);
          loop invariant start == \at(start,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant array_unchanged(args, 0, args_len);
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
