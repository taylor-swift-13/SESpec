#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo338(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Inv
    (j >= 2)
    */
for (int j = 2; j <= num; j++) {
			
            /*@
          loop invariant \true;
          loop invariant j >= 2;
          loop assigns j, result, num;
            */
            /*@ Inv
    (j >= 2)
    */
while (num % j == 0) {
				result = j;
				num /= j;
			}
            
		}
		return result;
}