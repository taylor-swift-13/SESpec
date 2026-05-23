

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  assigns \nothing;
  ensures start > stop ==> \result == start;
  ensures start <= stop ==> \result >= start;
  ensures start <= stop ==> \result <= stop + 1;
  ensures start <= stop ==> \result > stop ==> \result == stop + 1;
  ensures \result >= start;
*/
int foo249(int * args, int args_len, int start, int stop) {

		int found = start;
		int num = stop;
		int mid;

		
            
        /*@
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (found >= \at(start,Pre));
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (num <= \at(stop,Pre));
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (found <= \at(stop,Pre) + 1);
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (num + 1 >= \at(start,Pre));
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (found <= num + 1);
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (((num == \at(stop,Pre))&&(found == \at(start,Pre))&&(stop == \at(stop,Pre))&&(start == \at(start,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (found >= \at(start,Pre)));
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (((num == \at(stop,Pre))&&(found == \at(start,Pre))&&(stop == \at(stop,Pre))&&(start == \at(start,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (num <= \at(stop,Pre)));
          loop invariant (!(\at(start,Pre) <= \at(stop,Pre))) ==> ((num == \at(stop,Pre))&&(found == \at(start,Pre))&&(stop == \at(stop,Pre))&&(start == \at(start,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant stop == \at(stop,Pre);
          loop invariant start == \at(start,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
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
