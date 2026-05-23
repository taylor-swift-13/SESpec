#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo226(int * args, int args_len, int array) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (1 <= remaining) &&
    (1 <= found && found <= remaining) &&
    ((found == 1 && (forall (t:Z), 1 <= t && t < remaining => args_l[t-1] != t)) || (1 <= found && found < remaining && args_l[found-1] == found && (forall (u:Z), found < u && u < remaining => args_l[u-1] != u))) &&
    ((forall (u:Z), found < u && u < remaining => args_l[u-1] != u)) &&
    ((remaining == array + 1) => ((found == 1 && (forall (t:Z), 1 <= t && t <= array => args_l[t-1] != t)) || (1 <= found && found <= array && args_l[found-1] == found && (forall (u:Z), found < u && u <= array => args_l[u-1] != u)))) &&
    (forall (k:Z), 0 <= k && k < args_len => args_l[k] == args_l[k]@pre)
    */
for (int remaining = 1; remaining <= array; remaining++) {
        if (args[remaining - 1] == remaining) {
            found = remaining;
        } else if (args[remaining - 1] != remaining) {
            return remaining;
        }
    }
		return found;
}