#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_divisors_upto : Z -> Z -> Z) */
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
    (result == count_divisors_upto(num, size))
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