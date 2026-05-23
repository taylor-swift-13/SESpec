#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo355(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int end = 0;
		int sum = num;
	
 	/*@ Inv
    (0 <= result) &&
    (num == num@pre) &&
    ((num@pre > 0) => (0 <= result)) &&
    ((num@pre > 0) => (sum > 0 => result >= 0)) &&
    ((num@pre > 0) => (sum > 0 => (result == 0 || result > 0))) &&
    ((num@pre > 0) => (sum == 0 => result >= 0))
    */
while (sum > 0) {
        if (result % 2 == 1) {
            end |= (1 << result);
        }
        result++;
        sum >>= 1;
    }
		return (num | end);
}