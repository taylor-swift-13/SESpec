#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo1_c150(int value, int p);

int foo1_c150(int value, int p) 
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
/*@ Inv emp */ /*0*/ 
 for (c = 0; c < value; c++) {
			result[c] = c + 1;
		}
	
 	/*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
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
/*@ Inv emp */ /*2*/ 
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