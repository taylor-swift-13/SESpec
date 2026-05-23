
/*@
  logic integer array_unchanged{L}(int* a, integer n) =
    n <= 0 ? 1 :
    (\forall integer i; 0 <= i < n ==> a[i] == \at(a[i], Pre));
*/

 /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
int foo109(int * args, int args_len, int start, int stop) {

		int result = start;
		int total = stop;
		int mid;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (((total == \at(stop,Pre))&&(result == \at(start,Pre))&&(stop == \at(stop,Pre))&&(start == \at(start,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (result >= \at(start,Pre) && result <= \at(stop,Pre) + 1 && total >= \at(start,Pre) - 1 && total <= \at(stop,Pre)));
          loop invariant (\at(start,Pre) <= \at(stop,Pre)) ==> (((total == \at(stop,Pre))&&(result == \at(start,Pre))&&(stop == \at(stop,Pre))&&(start == \at(start,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (total >= \at(start,Pre) - 1 && total <= \at(stop,Pre) && result >= \at(start,Pre) && result <= \at(stop,Pre) + 1));
          loop invariant (!(\at(start,Pre) <= \at(stop,Pre))) ==> ((total == \at(stop,Pre))&&(result == \at(start,Pre))&&(stop == \at(stop,Pre))&&(start == \at(start,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant stop == \at(stop,Pre);
          loop invariant start == \at(start,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant array_unchanged(args, args_len);
          loop assigns mid, i, result, total;
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
