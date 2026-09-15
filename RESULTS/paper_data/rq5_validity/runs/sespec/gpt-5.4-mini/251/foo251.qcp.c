#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo251(int * args, int args_len, int start, int stop) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int found = start;
		int total = stop;
		int mid;

	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    ((start@pre <= stop@pre) => (found <= total + 1)) &&
    ((start@pre <= stop@pre) => (found >= start@pre)) &&
    ((start@pre <= stop@pre) => (total <= stop@pre)) &&
    ((start@pre <= stop@pre) => (found <= stop@pre + 1)) &&
    ((start@pre <= stop@pre) => (total >= start@pre - 1)) &&
    ((start@pre <= stop@pre) => (args_len == args_len@pre)) &&
    ((start@pre <= stop@pre) => (args == args@pre)) &&
    ((start@pre <= stop@pre) => (forall (k:Z), 0 <= k && k < args_len => args_l[k] == args_l[k]@pre)) &&
    ((start@pre <= stop@pre) => (((total == stop@pre)&&(found == start@pre)&&(stop == stop@pre)&&(start == start@pre)&&(args_len == args_len@pre)&&(args == args@pre)) || (found <= total + 1))) &&
    ((start@pre <= stop@pre) => (((total == stop@pre)&&(found == start@pre)&&(stop == stop@pre)&&(start == start@pre)&&(args_len == args_len@pre)&&(args == args@pre)) || (total <= stop@pre))) &&
    ((!(start@pre <= stop@pre)) => ((total == stop@pre)&&(found == start@pre)&&(stop == stop@pre)&&(start == start@pre)&&(args_len == args_len@pre)&&(args == args@pre))) &&
    (stop == stop@pre) &&
    (start == start@pre) &&
    (args_len == args_len@pre) &&
    (args == args@pre) &&
    ((forall (k:Z), 0 <= k && k < args_len => args_l[k] == args_l[k]@pre))
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