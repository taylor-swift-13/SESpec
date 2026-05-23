#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sum : Z -> Z -> Z -> Z) */
/*@ Extern Coq (count_odd : Z -> Z -> Z -> Z) */
/*@ Extern Coq (count_even : Z -> Z -> Z -> Z) */
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
	
 	/*@ Inv
    (forall (k:Z), 0 <= k && k < c => result[k] == k + 1)
    */
for (c = 0; c < number; c++) {
        result[c] = c + 1;
    }
	
 	for (c = 0; c < number; c++) {
        b[c] = result[c];
        if (result[c] % 2 != 0) {
            j++;
            if (j == p) {
                return result[c];
            }
        }
    }
	
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