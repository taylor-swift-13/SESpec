#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo316(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		if (number == 1)
			return 1;
	
 	/*@ Inv
    (result >= 0) &&
    (forall (k:Z), 2 <= k && k < c => (number % k == 0 => result >= 1)) &&
    ((!(c <= number / c)) => (result >= 0))
    */
for (int c = 2; c <= number / c; c++) {
        if (number % c == 0) {
            result++;
            if (number / c == c) {
                break;
            }
        }
    }
		return result;
}