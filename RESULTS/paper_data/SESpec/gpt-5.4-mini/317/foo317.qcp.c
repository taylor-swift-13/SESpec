#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_divs : Z -> Z -> Z) */
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
    (result >= 0) &&
    (result == count_divs(num, size - 1)) &&
    (result <= size - 2) &&
    (forall (d:Z), 2 <= d && d < size && d <= num / d && num % d == 0 => result >= 1) &&
    ((size > 2) => result <= size - 2) &&
    ((size <= num / size) => (result == count_divs(num, size - 1))) &&
    ((!(size <= num / size)) => (result == count_divs(num, size - 1)))
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