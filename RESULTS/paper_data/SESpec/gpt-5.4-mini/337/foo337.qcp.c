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
    (0 <= ret && ret <= j)
    */
for (int j = 2; j <= num; j++) {
			
            /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant j >= 2;
              loop invariant 0 <= ret <= j;
              loop assigns ret, num;
            */
            /*@ Inv
    (j >= 2) &&
    (0 <= ret && ret <= j)
    */
while (num % j == 0) {
				ret = j;
				num /= j;
			}
            
		}
		return ret;
}