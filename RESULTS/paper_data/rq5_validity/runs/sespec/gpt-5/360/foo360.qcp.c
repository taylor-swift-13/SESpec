#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_odds : Z -> Z) */
/*@ Extern Coq (sum_odds : Z -> Z) */
int foo360(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

		int average = 0;
		int total = 0;
	
 	/*@ Inv
    (1 <= c && c <= size@pre + 1) &&
    (size == size@pre) &&
    (0 <= total && total <= c - 1) &&
    (0 <= average) &&
    (total == count_odds(c - 1)) &&
    (average == sum_odds(c - 1)) &&
    ((c <= size@pre) => (total == count_odds(c - 1))) &&
    ((c <= size@pre) => (average == sum_odds(c - 1))) &&
    ((c <= size@pre) => (average == sum_odds(c - 1))) &&
    ((c <= size@pre) => (total == count_odds(c - 1))) &&
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