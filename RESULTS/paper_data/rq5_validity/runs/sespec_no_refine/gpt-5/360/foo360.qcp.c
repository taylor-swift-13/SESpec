#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo360(int size);

int foo360(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

		int average = 0;
		int total = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (1 <= c) &&
(average == odd_sum_upto(c - 1)) &&
(total == odd_count_upto(c - 1)) &&
((c <= size@pre) => (average == odd_sum_upto(c - 1) && total == odd_count_upto(c - 1))) &&
((c <= size@pre) => (average == odd_sum_upto(c - 1))) &&
((c <= size@pre) => (total == odd_count_upto(c - 1))) &&
((!(c <= size@pre)) => ((total == odd_count_upto(size@pre))&&(average == odd_sum_upto(size@pre))&&(size == size@pre))) &&
(size == size@pre
      loop assigns c, average, total)
    */
    
    for (int c = 1; c <= size; c++) {
        if (c % 2 != 0) {
            average += c;
            total++;
        }
    }
		return average / total;
}