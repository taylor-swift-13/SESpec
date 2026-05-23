#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo375(int num, int p) 
/*@

Require emp
Ensure Results(__return)
*/{

		if (p > num - p)
			p = num - p;
		int b = 1;
	
 	/*@ Inv
    (1 <= r => r >= 1) &&
    (r <= p@pre => r <= p@pre) &&
    (1 <= r && r <= p@pre => num - r + 1 >= num - p@pre + 1) &&
    (r >= 1 => num - r + 1 <= num) &&
    ((r <= p@pre) => (num == num@pre)) &&
    (num == num@pre)
    */
for (int r = 1; r <= p; r++) {
        b = b * (num - r + 1) / r;
    }
		return b;
}