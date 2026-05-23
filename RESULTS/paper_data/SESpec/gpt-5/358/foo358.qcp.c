#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo358(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

		int average = 0;
		int total = 0;
	
 	/*@ Inv
    (size == size@pre) &&
    (average >= 0) &&
    (total >= 0) &&
    (total <= index - 1) &&
    (average >= total) &&
    (forall (k:Z), 1 <= k && k < index => (total >= 0)) &&
    (forall (k:Z), 1 <= k && k < index && (k % 2 == 0) => (average == average)) &&
    (forall (k:Z), 1 <= k && k < index && (k % 2 != 0) => (average >= k))
    */
for (int index = 1; index <= size; index++) {
        if (index % 2 != 0) {
            average += index;
            total++;
        }
    }
		return average / total;
}