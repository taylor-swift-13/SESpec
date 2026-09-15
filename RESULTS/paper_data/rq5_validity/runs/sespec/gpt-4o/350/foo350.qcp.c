#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (compute_result : Z -> Z -> Z) */
/*@ Extern Coq (compute_total : Z -> Z -> Z) */

int foo350(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int ret = 0;
		int total = num;
	
 	/*0*/ 
 /*@ Inv
    (0 <= total && total <= num@pre) &&
    (0 <= ret) &&
    (result == compute_result(num@pre, ret)) &&
    (total == compute_total(num@pre, ret)) &&
    ((num@pre > 0) => (result == compute_result(num@pre, ret))) &&
    ((num@pre > 0) => (ret == (num@pre - total))) &&
    ((!(num@pre > 0)) => ((total == num@pre) && (ret == 0) && (result == 0) && (num == num@pre)))
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