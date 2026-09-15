#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo279(int * args, int args_len) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int g = 0;
		int ret = args[0];
	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (1 <= j) &&
    (j <= args_len) &&
    (0 <= g) &&
    (forall (k:Z), 0 <= k && k < args_len => args_l[k] == args_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < j => ret <= args_l[k]) &&
    (exists (k:Z), 0 <= k && k < j && ret == args_l[k])
    */
for (int j = 1; j < args_len; j++) {
        if (args[j] > ret) {
            g = g > ret ? g : ret;
        } else {
            ret = args[j];
        }
    }
		return g;
}