#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (odd : Z -> Prop) */
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
    (c == 0 || 0 <= c && c <= number) &&
    (forall (i:Z), 0 <= i && i < c => result[i] == i + 1)
    */
for (c = 0; c < number; c++) {
			result[c] = c + 1;
		}
	
 	/*1*/ 
 /*@ Inv
    (0 <= c && c <= number) &&
    (forall (i:Z), 0 <= i && i < c => b[i] == result[i]) &&
    (j == \numof integer k 0 <= k && k < c && result[k] % 2 != 0)
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
	
 	/*2*/ 
 /*@ Inv
    (0 <= j && j <= number) &&
    (0 <= c && c <= number) &&
    (forall (i:Z), 0 <= i && i < c => b[i] == result[i])
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