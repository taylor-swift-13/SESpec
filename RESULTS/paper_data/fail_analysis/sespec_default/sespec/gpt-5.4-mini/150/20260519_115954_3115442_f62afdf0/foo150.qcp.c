#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo150(int value, int p);

int foo150(int value, int p) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *result = (int *)malloc(sizeof(int) * (value));
int result_len = value;
		int *b = (int *)malloc(sizeof(int) * (value));
int b_len = value;
		int c, j = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= j && j <= c) &&
(forall (k:Z), 0 <= k && k < c => result_l[k] == k + 1
          loop assigns c, result_l[0..value-1])
    */
    
            for (c = 0; c < value; c++) {
			result[c] = c + 1;
		}
	
 	/*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    (loop assigns c, b_l[0..value-1], j)
    */
    
            for (c = 0; c < value; c++) {
			b[c] = result[c];
			if (result[c] % 2 != 0) {
				j++;
				if (j == p) {
					return result[c];
				}
			}
		}
	
 	/*@ Print user assertion at number LoopEntry_2*/ 
/*@ Inv
    (loop assigns c, b_l[0..value-1], j)
    */
    
            for (c = 0; c < value; c++) {
			b[c] = result[c];
			if (result[c] % 2 == 0) {
				j++;
				if (j == p) {
					return result[c];
				}
			}
		}
		return 0;
}