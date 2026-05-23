
#include <stddef.h>

/*@ 
  logic integer dummy_logic = 0;
*/

int foo250(int * args, int args_len, int start, int stop) {

		int result = start;
		int total = stop;
		int mid;

		
            
        /*@
          loop invariant start == \at(start,Pre);
          loop invariant stop == \at(stop,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant result >= \at(start,Pre);
          loop invariant total <= \at(stop,Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre);
          loop assigns mid, result, total;
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
