#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (args_readable : Z -> Z -> Prop) */
int foo155(int * args, int args_len, int Array) 
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
			
            /*@
          loop invariant 0 <= k <= i;
          loop assigns k, mpis[i];
            */
            /*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (0 <= k && k <= i)
    */
for (int k = 0; k < i; k++) {
				if (args[i] > args[k]
						&& mpis[i] < (mpis[k] * args[i])) {
					mpis[i] = mpis[k] * args[i];
				}
			}
            
		}
		int num = mpis[0];
	
 	/*3*/ 
 /*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (1 <= i && i <= Array) &&
    (forall (j:Z), 0 <= j && j < i => num >= mpis[j])
    */
for (int i = 1; i < Array; i++) {
			if (mpis[i] > num) {
				num = mpis[i];
			}
		}
		return num;
}