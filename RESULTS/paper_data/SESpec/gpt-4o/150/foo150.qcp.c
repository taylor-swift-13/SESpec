#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
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
	
 	/*@ Inv
    (0 <= c && c <= value) &&
    (forall (i:Z), 0 <= i && i < c => result[i] == i + 1)
    */
for (c = 0; c < value; c++) {
        result[c] = c + 1;
    }
	
 	/*@ Inv
    (0 <= c && c <= value) &&
    (0 <= j)
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
	
 	/*@ Inv
    (0 <= c && c <= value) &&
    (0 <= j)
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