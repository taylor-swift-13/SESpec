#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_eq : Z -> Z -> Z -> Z -> Z) */
int foo225(int * args, int args_len, int array) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int find = 1;
		if (array == 0 || array == 1) {
			return find;
		}
	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (1 <= remaining && remaining <= array + 1) &&
    (1 <= find && find <= remaining) &&
    (forall (k:Z), 0 <= k && k < args_len => args_l[k] == args_l[k]@pre) &&
    (forall (k:Z), 1 <= k && k < remaining => (args_l[k - 1] == k => find >= k)) &&
    (forall (k:Z), 1 <= k && k < remaining => (args_l[k - 1] == k => find == \max(find, k)))
    */
for (int remaining = 1; remaining <= array; remaining++) {
        if (args[remaining - 1] == remaining) {
            find = remaining;
        } else if (args[remaining - 1] != remaining) {
            return remaining;
        }
    }
		return find;
}