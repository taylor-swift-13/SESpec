#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (prefix_matches : Z -> Z -> Z) */
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
    (1 <= remaining) &&
    (1 <= find && find <= remaining) &&
    ((remaining <= array) => (remaining >= 1)) &&
    (forall (k:Z), 0 <= k && k < args_len => args_l[k] == args_l[k]@pre) &&
    (forall (j:Z), 1 <= j && j < remaining && args_l[j-1] == j => find >= j) &&
    (forall (j:Z), 1 <= j && j < remaining && find < j => args_l[j-1] != j) &&
    ((exists (j:Z), 1 <= j && j < remaining && args_l[j-1] != j) => (exists (t:Z), 1 <= t && t < remaining && args_l[t-1] != t)) &&
    ((!(remaining <= array)) => true)
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