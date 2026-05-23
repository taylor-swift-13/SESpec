#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo331(int n, int c) 
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
    (c == c@pre) &&
    (n == n@pre) &&
    (n < c => (index >= n + 1 && index <= c + 1)) &&
    (n < c => (0 <= index - (n + 1) <= c - n)) &&
    (index <= c + 1 => c - n < 5) &&
    ((index == n + 1) => (result == 1)) &&
    (index > n + 1 && index <= c + 1 => ((result * 1) % 10) == result)
    */
for (int index = n + 1; index < c + 1; index++) {
				result = (result * (index % 10)) % 10;
			}
			return result % 10;
		}
}