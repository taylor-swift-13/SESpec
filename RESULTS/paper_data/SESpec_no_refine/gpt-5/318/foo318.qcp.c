#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo318(int num);

int foo318(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		if (num == 1)
			return 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (2 <= num => result >= 0) &&
(2 <= num => forall (k:Z), 2 <= k && k < c => (k <= num / k)) &&
(2 <= num => forall (k:Z), 2 <= k && k < c => ((num % k == 0) => (num / k >= k))) &&
(2 <= num => forall (k:Z), 2 <= k && k < c => ((num % k == 0 && num / k == k) => (num >= 4))) &&
(2 <= num => forall (k:Z), 2 <= k && k < c => ((num % k == 0 && num / k != k) => (num >= 4))) &&
(2 <= num => c >= 2
      loop assigns c, result)
    */
    
    for (int c = 2; c <= num / c; c++) {
        if (num % c == 0) {
            result++;
            if (num / c == c) {
                break;
            }
        }
    }
		return result;
}