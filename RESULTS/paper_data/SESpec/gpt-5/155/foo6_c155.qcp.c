#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo6_c155(int * args, int args_len, int Array);

int foo6_c155(int * args, int args_len, int Array) 
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
    (0 <= array && array <= Array) &&
(\valid_read(args + (0..args_len-1))) &&
(Array <= args_len
      loop assigns array, mpis_l[0..Array-1])
    */
    
    for (int array = 0; array < Array; array++) {
        mpis[array] = args[array];
    }
	
 	/*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100 &&
    (loop assigns i, mpis_l[0..Array-1])
    */
    
            for (int i = 1; i < Array; i++) {
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop assigns k, mpis[0..i];
            */
            for (int k = 0; k < i; k++) {
            if (args[i] > args[k]
                    && mpis[i] < (mpis[k] * args[i])) {
                mpis[i] = mpis[k] * args[i];
            }
        }
            
    }
		int num = mpis[0];
	
 	/*@ Print user assertion at number LoopEntry_3*/ 
/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100 &&
    (forall (k:Z), 0 <= k && k < i => num >= mpis_l[k]
          loop assigns i, num)
    */
    
            for (int i = 1; i < Array; i++) {
        if (mpis[i] > num) {
            num = mpis[i];
        }
    }
		return num;
}