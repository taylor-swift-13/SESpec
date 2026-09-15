#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (oddcount : Z -> Z -> Z -> Z) */
/*@ Extern Coq (oddret : Z -> Z -> Z -> Z) */
int foo267(int * args, int args_len, int array) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int ret = 0;
		int start = 0;
	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (0 <= index && index <= array) &&
    (0 <= start && start <= index) &&
    (start == oddcount(args, 0, index)) &&
    (ret == oddret(args, 0, index)) &&
    (forall (k:Z), 0 <= k && k < index => args_l[k] == args_l[k]@pre) &&
    (array == array@pre) &&
    (args_len == args_len@pre) &&
    (args == args@pre)
    */
for (int index = 0; index < array; index++) {
			if (args[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = args[index];
				}
			}
		}
		return ret;
}