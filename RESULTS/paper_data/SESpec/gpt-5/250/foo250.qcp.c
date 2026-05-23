#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo250(int * args, int args_len, int start, int stop) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int result = start;
		int total = stop;
		int mid;

	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (forall (k:Z), 0 <= k && k < args_len => args_l[k] == args_l[k]@pre) &&
    (start@pre <= result) &&
    (total <= stop@pre) &&
    ((total - result) <= (stop@pre - start@pre)) &&
    ((start@pre <= stop@pre) => (result <= total + 1)) &&
    ((start@pre <= stop@pre) => (((total == stop@pre)&&(result == start@pre)&&(stop == stop@pre)&&(start == start@pre)&&(args_len == args_len@pre)&&(args == args@pre)) || (start@pre <= result && result <= stop@pre + 1))) &&
    ((start@pre <= stop@pre) => (((total == stop@pre)&&(result == start@pre)&&(stop == stop@pre)&&(start == start@pre)&&(args_len == args_len@pre)&&(args == args@pre)) || (start@pre - 1 <= total && total <= stop@pre))) &&
    ((!(start@pre <= stop@pre)) => ((total == stop@pre)&&(result == start@pre)&&(stop == stop@pre)&&(start == start@pre)&&(args_len == args_len@pre)&&(args == args@pre))) &&
    (stop == stop@pre) &&
    (start == start@pre) &&
    (args_len == args_len@pre) &&
    (args == args@pre) &&
    (forall (k:Z), 0 <= k && k < args_len => args_l[k] == args_l[k]@pre)
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