#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (sorted : Z -> Z -> Z -> Z) */

int foo215(int * args, int args_len, int x, int y) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int i = 0;
		int r = y - 1;
		int p = -1;

	
 	/*0*/ 
 /*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (0 <= i && i <= args_len) &&
    (-1 <= r && r < args_len) &&
    (-1 <= p && p < args_len) &&
    (forall (k:Z), 0 <= k && k < args_len => args_l[k] == args_l[k]@pre) &&
    (sorted(args, 0, args_len)) &&
    (forall (k:Z), 0 <= k && k < i => args_l[k] < x) &&
    (forall (k:Z), r < k && k < args_len => args_l[k] > x) &&
    (p == -1 || args_l[p] == x) &&
    (p == -1 || (i > p && r < p))
    */
while (i <= r) {
			int tmp = (i + r) / 2;
			if (args[tmp] == x) {
				p = tmp;
				i = tmp + 1;
			} else if (args[tmp] < x) {
				i = tmp + 1;
			} else {
				r = tmp - 1;
			}
		}

		return p;
}