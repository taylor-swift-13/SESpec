#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo373(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

		int div = 0;
	
 	/*@ Inv
    (number == number@pre) &&
    (0 <= div && div <= index - 1) &&
    (forall (k:Z), 1 <= k && k < index => ( ( number@pre % k == 0 ) => 0 <= div )) &&
    (forall (k:Z), 1 <= k && k < index => ( ( number@pre % k == 0 ) => 1 <= k && k <= number@pre )) &&
    (forall (k1:Z), forall (k2:Z), 1 <= k1 && k1 < index && 1 <= k2 && k2 < index && k1 != k2 => !((number@pre % k1 == 0) && (number@pre % k2 == 0) && k1 == k2)) &&
    (forall (k:Z), 1 <= k && k < index && (number@pre % k == 0) => 1 <= div) &&
    ((index <= number@pre) => (index >= 1 && index <= number@pre)) &&
    ((index <= number@pre) => (0 <= div && div <= index - 1))
    */
for (int index = 1; index <= number; index++) {
        if (number % index == 0) {
            div++;
        }
    }
		return div;
}