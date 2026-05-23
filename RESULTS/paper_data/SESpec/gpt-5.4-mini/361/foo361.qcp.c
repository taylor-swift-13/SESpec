#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (even_sum : Z -> Z) */
/*@ Extern Coq (even_count : Z -> Z) */
int foo361(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

		int average = 0;
		int total = 0;
	
 	/*@ Inv
    (0 <= j) &&
    (average >= 0) &&
    (total >= 0) &&
    (average == even_sum(j - 1)) &&
    (total == even_count(j - 1)) &&
    (total <= j - 1) &&
    (average >= total) &&
    ((j == 1) || (j <= size + 1)) &&
    ((j <= size) => (average >= total)) &&
    ((j <= size) => (average >= 0)) &&
    ((j <= size) => (total >= 0)) &&
    ((j <= size) => (total <= j - 1)) &&
    ((j <= size) => (average == even_sum(j - 1))) &&
    ((j <= size) => (total == even_count(j - 1))) &&
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