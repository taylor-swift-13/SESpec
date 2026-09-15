#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo228(int seed) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int *temp = (int *)malloc(sizeof(int) * (seed + 1));
int temp_len = seed + 1;
		temp[0] = 1;
	
 	/*@ Inv
    (1 <= d && d <= seed + 1) &&
    (temp_len == seed + 1) &&
    (temp[0] == 1) &&
    ((d <= seed) => temp[0] == 1) &&
    ((!(d <= seed)) => d == seed + 1) &&
    (forall (k:Z), 0 <= k && k < d => k < temp_len) &&
    (forall (k:Z), 0 <= k && k < d => temp_len == seed + 1)
    */
for (int d = 1; d <= seed; d++) {
			
            /*@
              loop assigns c, temp[d];
              loop invariant 0 <= c <= d;
            */
            /*@ Inv
    (0 <= c && c <= d)
    */
for (int c = 0; c < d; c++) {
				temp[d] = temp[d] + temp[c];
			}
            
		}
		return temp[seed];
}