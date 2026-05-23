#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sum_odd : Z -> Z) */
/*@ Extern Coq (count_odd : Z -> Z) */
/*@ Extern Coq (valid_average_total : Z -> Z -> Z -> Prop) */
int foo360(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

		int average = 0;
		int total = 0;
	
 	/*@ Inv
    (size == size@pre)
    */
for (int c = 1; c <= size; c++) {
        if (c % 2 != 0) {
            average += c;
            total++;
        }
    }
		return average / total;
}