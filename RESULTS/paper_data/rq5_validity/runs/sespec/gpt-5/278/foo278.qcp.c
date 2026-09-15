#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (min_prefix : Z -> Z -> Z -> Z) */
int foo278(int * args, int args_len) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int ret = 0;
		int tmp = args[0];
	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (1 <= j && j <= args_len) &&
    (0 <= j && j <= args_len) &&
    (forall (k:Z), 0 <= k && k < args_len => args_l[k] == args_l[k]@pre) &&
    (j > 0 => tmp == min_prefix(args, 0, j-1)) &&
    (j > 0 => forall (k:Z), 0 <= k && k < j => args_l[k] >= tmp) &&
    (0 <= ret) &&
    (ret >= 0 && (j >= 1 => ret <= \max(ret, tmp))) &&
    ((j == args_len) => (tmp == min_prefix(args, 0, args_len-1)))
    */
for (int j = 1; j < args_len; j++) {
        if (args[j] > tmp) {
            ret = ret > tmp ? ret : tmp;
        } else {
            tmp = args[j];
        }
    }
		return ret;
}