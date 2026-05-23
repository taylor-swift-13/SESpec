#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo248(int * args, int args_len, int num);

int foo248(int * args, int args_len, int num) 
/*@
With args_l
Require store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100
Ensure Results(__return)
*/{

		int ret = 0;

	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100 &&
    ((index < num@pre) => (ret >= 0)) &&
(num == num@pre) &&
(args_len == args_len@pre) &&
(args == args@pre) &&
(forall (i:Z), 0 <= i && i < args_len => 0 <= args_l[i] <= 100
          loop assigns index, ret)
    */
    
            for (int index = 0; index < num; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant ret >= 0;
              loop assigns index, ret;
              loop variant num - index;
            */
            for (int c = index + 1; c < num; c++) {
				if (args[index] > args[c]) {
					ret++;
				}
			}
            
		}
		return ret;
}