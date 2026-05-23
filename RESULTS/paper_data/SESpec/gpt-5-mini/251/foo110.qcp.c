#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo110(int * args, int args_len, int start, int stop);

int foo110(int * args, int args_len, int start, int stop) 
/*@
With args_l
Require store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100
Ensure Results(__return)
*/{

		int found = start;
		int total = stop;
		int mid;

	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100 &&
    ((!(start@pre <= stop@pre)) => ((total == stop@pre)&&(found == start@pre)&&(stop == stop@pre)&&(start == start@pre)&&(args_len == args_len@pre)&&(args == args@pre))) &&
(stop == stop@pre) &&
(start == start@pre) &&
(args_len == args_len@pre) &&
(args == args@pre) &&
(unchanged_array{Pre,Here}(args, 0, args_len)
          loop assigns mid, found, total)
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