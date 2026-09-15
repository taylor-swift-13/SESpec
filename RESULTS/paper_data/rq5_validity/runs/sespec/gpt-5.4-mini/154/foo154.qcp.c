#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo154(int * args, int args_len, int Array) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int *mpis = (int *)malloc(sizeof(int) * (Array));
int mpis_len = Array;
	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (0 <= array) &&
    (Array < 0 || array <= Array)
    */
for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (Array < 1 || i <= Array) &&
    (0 <= p)
    */
for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
            
		/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (Array < 1 || i <= Array) &&
    (result >= mpis[0]) &&
    (forall (k:Z), 0 <= k && k < i => result >= mpis[k]) &&
    (exists (k:Z), 0 <= k && k < i && result == mpis[k])
    */
for (int i = 1; i < Array; i++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            for (int i = 1; i < Array; i++) {
			if (mpis[i] > result) {
				result = mpis[i];
			}
		}
            
		}
		int result = mpis[0];
	
 	/*3*/ 
 for (int i = 1; i < Array; i++) {
			if (mpis[i] > result) {
				result = mpis[i];
			}
		}
		return result;
}