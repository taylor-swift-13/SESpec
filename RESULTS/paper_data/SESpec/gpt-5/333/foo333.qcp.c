#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo333(int n, int c) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 1;
		if (n == c) {
			return 1;
		} else if ((c - n) >= 5) {
			return 0;
		} else {
		
 	/*@ Inv
    (n == n@pre) &&
    (c == c@pre) &&
    (c@pre - n@pre < 5) &&
    ((var == n@pre + 1) => (result == 1)) &&
    (var >= n@pre + 1) &&
    (c == c@pre) &&
    (n == n@pre)
    */
for (int var = n + 1; var < c + 1; var++) {
				result = (result * (var % 10)) % 10;
			}
			return result % 10;
		}
}