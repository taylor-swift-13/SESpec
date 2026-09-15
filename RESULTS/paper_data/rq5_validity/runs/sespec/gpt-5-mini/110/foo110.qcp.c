#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo110(int num1, int num2) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 1;
	 	num1 = (0 <= num1) ? num1 : -num1;
		num2 = (0 <= num2) ? num2 : -num2;

		if (num1 == 0 && num2 == 0) {
			return -1;
		}

		if (num1 == 0 || num2 == 0) {
			return (num1 > num2) ? num1 : num2;
		}

	
 	/*@ Inv
    (1 <= i <= (num1 < num2 ? num1 : num2) + 1) &&
    (1 <= result) &&
    (num1 % result == 0 && num2 % result == 0) &&
    (forall (k:Z), 1 <= k && k < i => ( (num1 % k == 0 && num2 % k == 0) => k <= result ))
    */
for (int i = 1; i <= num1 && i <= num2; i++) {
		if (num1 % i == 0 && num2 % i == 0) {
			result = i;
		}
	}
		return result;
}