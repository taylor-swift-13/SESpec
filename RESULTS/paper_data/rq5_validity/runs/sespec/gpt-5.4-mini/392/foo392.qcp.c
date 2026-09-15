#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (fact : Z -> Z) */
int foo392(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 1;
	
 	/*@ Inv
    (number >= 1) &&
    (num == num@pre) &&
    (ret == fact(number - 1)) &&
    (ret >= 1) &&
    (ret == fact(number - 1) && (number - 1) >= 0) &&
    (forall (k:Z), 1 <= k && k < number => fact(k) > 0) &&
    ((number > num) => ret == fact(num)) &&
    ((number <= num@pre) => (ret == fact(number - 1))) &&
    ((!(number <= num@pre)) => (num == num@pre))
    */
for (int number = 1; number <= num; number++) {
		ret *= number;
	}
		int result = (int) (ret % 100);
		return result;
}