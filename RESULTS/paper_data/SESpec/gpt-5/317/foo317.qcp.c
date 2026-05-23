#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo317(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		if (num == 1)
			return 1;
	
 	/*@ Inv
    (2 <= size) &&
    (0 <= result) &&
    (result <= size - 2) &&
    (forall (k:Z), k < 2 => true) &&
    (forall (k:Z), 2 <= k && k < size => (k <= num / k => (num % k == 0 || num % k != 0))) &&
    (forall (k:Z), size <= k => true)
    */
for (int size = 2; size <= num / size; size++) {
        if (num % size == 0) {
            result++;
            if (num / size == size) {
                break;
            }
        }
    }
		return result;
}