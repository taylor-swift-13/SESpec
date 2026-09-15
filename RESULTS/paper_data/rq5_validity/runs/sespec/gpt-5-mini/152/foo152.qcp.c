#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo152(int number, int p);

int foo152(int number, int p) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *result = (int *)malloc(sizeof(int) * (number));
int result_len = number;
		int *b = (int *)malloc(sizeof(int) * (number));
int b_len = number;
		int c, j = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= c && c <= number
      loop assigns c, result_l[0..number-1])
    */
    
    for (c = 0; c < number; c++) {
        result[c] = c + 1;
    }
	
 	/*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    (0 <= c && c <= number
      loop assigns c, b_l[0..number-1], j)
    */
    
    for (c = 0; c < number; c++) {
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
    (0 <= c && c <= number
      loop assigns c, b_l[0..number-1], j)
    */
    
    for (c = 0; c < number; c++) {
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