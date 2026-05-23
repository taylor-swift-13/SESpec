#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo151(int number, int p) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *result = (int *)malloc(sizeof(int) * (number));
int result_len = number;
		int *b = (int *)malloc(sizeof(int) * (number));
int b_len = number;
		int c, ii = 0;
	
 	/*0*/ 
 /*@ Inv
    (0 <= c && c <= number) &&
    (forall (k:Z), 0 <= k && k < c => result[k] == k + 1)
    */
for (c = 0; c < number; c++) {
			result[c] = c + 1;
		}
	
 	/*1*/ 
 /*@ Inv
    (0 <= c && c <= number)
    */
for (c = 0; c < number; c++) {
			b[c] = result[c];
			if (result[c] % 2 != 0) {
				ii++;
				if (ii == p) {
					return result[c];
				}
			}
		}
	
 	/*@ Inv
    (0 <= c && c <= number)
    */
for (c = 0; c < number; c++) {
			b[c] = result[c];
			if (result[c] % 2 == 0) {
				ii++;
				if (ii == p) {
					return result[c];
				}
			}
		}
		return 0;
}