#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo339(int num, int z) 
/*@

Require emp
Ensure Results(__return)
*/{

		if (z < 0) {
			z = -z;
		}
		int result = 0;
	
 	/*@ Inv
    (1 <= index && index <= z + 1) &&
    (0 <= result && result <= index - 1) &&
    (forall (k:Z), 1 <= k && k < index => k <= z) &&
    (forall (k:Z), 1 <= k && k < index => ((num % k == 0) => 0 <= result)) &&
    (forall (k:Z), 1 <= k && k < index => ((num % k != 0) => 0 <= result)) &&
    (forall (k:Z), 1 <= k && k < index => ((num % k == 0) => result <= index - 1)) &&
    (forall (k:Z), 1 <= k && k < index => ((num % k != 0) => result <= index - 1)) &&
    (forall (k:Z), 1 <= k && k < index => (k <= z)) &&
    (exists (m:Z), m == result && 0 <= m && m <= index - 1) &&
    (forall (k:Z), 1 <= k && k < index => ((num % k == 0) => 1 <= result + 1)) &&
    (forall (k:Z), 1 <= k && k < index => ((num % k != 0) => result == result)) &&
    (forall (k:Z), 1 <= k && k < index => (num % k == 0 || num % k != 0)) &&
    ((index <= z@pre) => (0 <= index && index <= z)) &&
    ((index <= z@pre) => (0 <= result && result <= index - 1)) &&
    (num == num@pre)
    */
for (int index = 1; index <= z; index++) {
        if (num % index == 0) {
            result = result + 1;
        }
    }
		return result;
}