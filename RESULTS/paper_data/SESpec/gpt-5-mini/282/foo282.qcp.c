#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_divs : Z -> Z -> Z -> Z) */
const char * foo282(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Inv
    (1 <= c) &&
    (0 <= result && result <= c - 1) &&
    (result == count_divs(num, 1, c)) &&
    (forall (p:Z), forall (q:Z), 1 <= p && p <= q && q < c => (count_divs(num, 1, p) <= count_divs(num, 1, q))) &&
    ((result > 0) => (exists (k:Z), 1 <= k && k < c && num % k == 0)) &&
    (num == num@pre)
    */
for (int c = 1; c <= num; c++) {
        if (num % c == 0) {
            result++;
        }
    }
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
}