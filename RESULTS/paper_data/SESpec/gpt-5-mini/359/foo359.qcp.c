#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (odd_sum : Z -> Z -> Z) */
/*@ Extern Coq (odd_count : Z -> Z -> Z) */
int foo359(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
		int total = 0;
	
 	/*@ Inv
    (1 <= c) &&
    (ret == odd_sum(c, size@pre)) &&
    (total == odd_count(c, size@pre)) &&
    (0 <= ret) &&
    (0 <= total) &&
    ((!(c <= size@pre)) => (ret == odd_sum(size@pre + 1, size@pre) && total == odd_count(size@pre + 1, size@pre) && size == size@pre))
    */
for (int c = 1; c <= size; c++) {
        if (c % 2 != 0) {
            ret += c;
            total++;
        }
    }
		return ret / total;
}