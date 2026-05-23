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
    (2 <= j) &&
    (0 <= result) &&
    (num >= 0) &&
    (result == 0 || result >= 2)
    */
for (int j = 2; j <= num; j++) {

        /*@
          loop invariant 2 <= j;
          loop invariant 0 <= result;
          loop invariant num >= 0;
          loop invariant result == 0 || result >= 2;
          loop assigns result, num;
        */
        /*@ Inv
    (2 <= j) &&
    (0 <= result) &&
    (num >= 0) &&
    (result == 0 || result >= 2)
    */
while (num % j == 0) {
            result = j;
            num /= j;
        }
    }
		return result;
}