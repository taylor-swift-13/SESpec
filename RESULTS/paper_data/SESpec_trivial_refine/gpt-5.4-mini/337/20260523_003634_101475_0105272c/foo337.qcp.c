#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo337(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
	
 	/*@ Inv
    (j >= 2) &&
    (ret >= 0)
    */
for (j = 2; j <= num; j++) {

        /*@
          loop invariant j >= 2;
          loop invariant ret >= 0;
          loop assigns ret, num;
        */
        /*@ Inv
    (j >= 2) &&
    (ret >= 0)
    */
while (num % j == 0) {
            ret = j;
            num /= j;
        }
    }
		return ret;
}