#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_eq : Z -> Z -> Z -> Z -> Z) */
int foo249(int * args, int args_len, int start, int stop) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int found = start;
		int num = stop;
		int mid;

	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (start <= found && found <= stop + 1 || start > stop) &&
    (start - 1 <= num && num <= stop || start > stop) &&
    (forall (k:Z), 0 <= k && k < args_len => args_l[k] == args_l[k]@pre) &&
    ((start@pre <= stop@pre) => (found >= start && num <= stop)) &&
    ((start@pre <= stop@pre) => (num >= found - 1)) &&
    (stop == stop@pre) &&
    (start == start@pre) &&
    (args_len == args_len@pre) &&
    (args == args@pre)
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