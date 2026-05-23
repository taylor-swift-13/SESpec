#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo217(int * args, int args_len, int x, int y);

int foo217(int * args, int args_len, int x, int y) 
/*@
With args_l
Require store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100
Ensure Results(__return)
*/{

		int i = 0;
		int r = y - 1;
		int k = -1;

	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100 &&
    ((0 <= y@pre - 1) => (((k == -1)&&(r == y@pre - 1)&&(i == 0)&&(y == y@pre)&&(x == x@pre)&&(args_len == args_len@pre)&&(args == args@pre)) || (i <= r + 1))) &&
((!(0 <= y@pre - 1)) => ((k == -1)&&(r == y@pre - 1)&&(i == 0)&&(y == y@pre)&&(x == x@pre)&&(args_len == args_len@pre)&&(args == args@pre))) &&
(y == y@pre) &&
(x == x@pre) &&
(args_len == args_len@pre) &&
(args == args@pre)
    */
    
            while (i <= r) {
			int tmp = (i + r) / 2;
			if (args[tmp] == x) {
				k = tmp;
				i = tmp + 1;
			} else if (args[tmp] < x) {
				i = tmp + 1;
			} else {
				r = tmp - 1;
			}
		}

		return k;
}