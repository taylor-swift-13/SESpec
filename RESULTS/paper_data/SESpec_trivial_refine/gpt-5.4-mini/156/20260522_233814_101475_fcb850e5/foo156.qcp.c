#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (valid_array : Z -> Z -> Prop) */
int foo156(int * args, int args_len, int Array) 
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
    (0 <= array && array <= Array)
    */
for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (1 <= i && i <= Array)
    */
for (int i = 1; i < Array; i++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= p <= i;
          loop assigns p, mpis[i];
            */
            /*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (0 <= p && p <= i)
    */
for (int p = 0; p < i; p++) {
				if (args[i] > args[p]
						&& mpis[i] < (mpis[p] * args[i])) {
					mpis[i] = mpis[p] * args[i];
				}
			}
            
		}
		int num = mpis[0];
	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (1 <= i && i <= Array) &&
    (forall (k:Z), 0 <= k && k < i => num >= mpis[k])
    */
for (int i = 1; i < Array; i++) {
			if (mpis[i] > num) {
				num = mpis[i];
			}
		}
		return num;
}