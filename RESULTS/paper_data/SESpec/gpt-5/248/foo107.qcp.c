#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo107(int * args, int args_len, int num);

int foo107(int * args, int args_len, int num) 
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
    (index >= 0) &&
(ret >= 0) &&
(num == num@pre) &&
(args_len == args_len@pre) &&
(args == args@pre) &&
(forall (k:Z), 0 <= k && k < args_len => args_l[k] == args_l[k]@pre
          loop assigns index, ret)
    */
    
            for (int index = 0; index < num; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant index + 1 <= c <= num;
          loop invariant 0 <= index <= num;
          loop invariant ret >= 0;
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre);
          loop assigns ret, c;
            */
            for (int c = index + 1; c < num; c++) {
				if (args[index] > args[c]) {
					ret++;
				}
			}
            
		}
		return ret;
}