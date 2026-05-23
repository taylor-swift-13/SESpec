#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sum_evens : Z -> Z) */
/*@ Extern Coq (count_evens : Z -> Z) */
int foo361(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

		int average = 0;
		int total = 0;
	
 	/*@ Inv
    (0 <= total) &&
    (total <= j - 1) &&
    (0 <= average) &&
    (average == sum_evens(j-1)) &&
    (total == count_evens(j-1)) &&
    ((j == size@pre + 1) => ( average == sum_evens(size@pre) && total == count_evens(size@pre) )) &&
    (size == size@pre)
    */
for (int j = 1; j <= size; j++) {
        if (j % 2 == 0) {
            average += j;
            total++;
        }
    }
		return average / total;
}