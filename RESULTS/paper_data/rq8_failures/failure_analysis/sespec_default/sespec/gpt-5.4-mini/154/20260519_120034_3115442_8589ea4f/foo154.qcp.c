#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo154(int * args, int args_len, int Array);

int foo154(int * args, int args_len, int Array) 
/*@
With args_l
Require store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100
Ensure Results(__return)
*/{

		int *mpis = (int *)malloc(sizeof(int) * (Array));
int mpis_len = Array;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100 &&
    (0 <= array
          loop assigns array, mpis_l[0..Array-1])
    */
    
            for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
	
 	/*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 for (int i = 1; i < Array; i++) {
		
 	/*@ Print user assertion at number LoopEntry_2*/ 
/*@ Inv emp */ /*2*/ 
 for (int p = 0; p < i; p++) {
				if (args[i] > args[p]
						&& mpis[i] < (mpis[p] * args[i])) {
					mpis[i] = mpis[p] * args[i];
				}
			}
		}
		int result = mpis[0];
	
 	/*@ Print user assertion at number LoopEntry_3*/ 
/*@ Inv emp */ /*3*/ 
 for (int i = 1; i < Array; i++) {
			if (mpis[i] > result) {
				result = mpis[i];
			}
		}
		return result;
}