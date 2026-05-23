#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo214_c351(int number);

int foo214_c351(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

		int i = 0;
		int ret = 0;
		int total = number;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= ret) &&
((number@pre > 0) => (number == number@pre)) &&
((number@pre > 0) => (0 <= ret && 0 <= total)) &&
((!(number@pre > 0)) => ((total == number@pre)&&(ret == 0)&&(i == 0)&&(number == number@pre))) &&
(number == number@pre
          loop assigns i, total, ret)
    */
    
        while (total > 0) {
			if (ret % 2 == 0) {
				i = i | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
		return number ^ i;
}