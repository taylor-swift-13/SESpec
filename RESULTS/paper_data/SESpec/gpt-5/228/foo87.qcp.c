#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo87(int seed);

int foo87(int seed) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int *temp = (int *)malloc(sizeof(int) * (seed + 1));
int temp_len = seed + 1;
		temp[0] = 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (temp_len == seed + 1) &&
(temp_l[0] == 1) &&
(1 <= d && d <= temp_len => \true) &&
(forall (k:Z), 0 <= k && k < temp_len => (k == 0 => temp_l[k] == 1)
          loop assigns d, temp_l[0..temp_len-1])
    */
    
            for (int d = 1; d <= seed; d++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c;
          loop invariant d > 0 ==> c <= d;
          loop invariant temp[0] == 1;
          loop invariant \forall integer k; 0 <= k < d ==> (k < c ==> \true) && (k >= c ==> \true);
          loop invariant \forall integer k; 0 <= k < d ==> k != d ==> \true;
          loop invariant \forall integer k; d < k < temp_len ==> \true;
          loop assigns temp[d], c;
            */
            for (int c = 0; c < d; c++) {
				temp[d] = temp[d] + temp[c];
			}
            
		}
		return temp[seed];
}