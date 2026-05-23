#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo227(int b);

int foo227(int b) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int *arr = (int *)malloc(sizeof(int) * (b + 1));
int arr_len = b + 1;
		arr[0] = 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((!(d <= b)) => (\true)
          loop assigns d, arr_l[0 .. b])
    */
    
            for (int d = 1; d <= b; d++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop assigns d, arr[0 .. b];
              loop variant b - d + 1;
            */
            for (int c = 0; c < d; c++) {
				arr[d] = arr[d] + arr[c];
			}
            
		}
		return arr[b];
}