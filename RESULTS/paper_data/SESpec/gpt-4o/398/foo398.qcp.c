#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo398(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
	
 	/*@ Inv
    (number >= 0 || number == number@pre) &&
    (ret >= 0) &&
    ((number@pre > 0) => (ret >= 0)) &&
    ((number@pre > 0) => (number >= 0)) &&
    ((!(number@pre > 0)) => ((ret == 0) && (number == number@pre)))
    */
while (number > 0) {
        number /= 10;
        ret++;
    }
		return ret;
}