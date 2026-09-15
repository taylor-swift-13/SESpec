#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo350(int num);

int foo350(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int ret = 0;
		int total = num;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((num@pre > 0) => (0 <= ret)) &&
((num@pre > 0) => (0 <= total)) &&
((!(num@pre > 0)) => ((total == num@pre)&&(ret == 0)&&(result == 0)&&(num == num@pre))) &&
(num == num@pre
          loop assigns result, total, ret)
    */
    
        while (total > 0) {
			if (ret % 2 == 0) {
				result = result | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
		return num ^ result;
}