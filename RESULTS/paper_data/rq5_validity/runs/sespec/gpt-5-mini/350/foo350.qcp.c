#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
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
    (0 <= ret) &&
    (num == num@pre) &&
    (total == (num@pre >> ret)) &&
    (((exists (i:Z), 0 <= i && i < ret && i % 2 == 0 && (((num@pre >> i) & 1) == 1)) => (exists (j:Z), 0 <= j && j < ret && j % 2 == 0 && (((result >> j) & 1) == 1)))) &&
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