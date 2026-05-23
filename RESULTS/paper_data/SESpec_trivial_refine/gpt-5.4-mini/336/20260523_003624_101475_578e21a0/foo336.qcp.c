#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (divides : Z -> Z -> Prop) */
int foo336(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Inv
    (c >= 2) &&
    (result == 0 || result >= 2) &&
    (result <= c)
    */
for (int c = 2; c <= num; c++) {
			
            /*@
          loop invariant num > 0 && c >= 2;
          loop invariant result == 0 || result >= 2;
          loop invariant result <= c;
          loop assigns result, num;
            */
            /*@ Inv
    (num > 0 && c >= 2) &&
    (result == 0 || result >= 2) &&
    (result <= c)
    */
while (num % c == 0) {
				result = c;
				num /= c;
			}
            
		}
		return result;
}