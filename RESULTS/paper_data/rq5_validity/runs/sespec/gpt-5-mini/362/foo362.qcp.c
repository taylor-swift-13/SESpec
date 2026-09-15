#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sum_even_upto : Z -> Z) */
/*@ Extern Coq (count_even_upto : Z -> Z) */
int foo362(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int total = 0;
	
 	/*@ Inv
    (1 <= c) &&
    (( size@pre >= 1 ) => ( c <= size@pre + 1 )) &&
    (0 <= total) &&
    (0 <= result) &&
    (result == sum_even_upto(c)) &&
    (total == count_even_upto(c)) &&
    (size == size@pre)
    */
for (int c = 1; c <= size; c++) {
		if (c % 2 == 0) {
			result += c;
			total++;
		}
	}
		return result / total;
}