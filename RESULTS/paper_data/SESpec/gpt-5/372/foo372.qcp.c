#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_div : Z -> Z -> Z) */
int foo372(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int div = 0;
	
 	/*@ Inv
    (num == num@pre) &&
    (c >= 1) &&
    ((num >= 1) => (1 <= c && c <= num + 1)) &&
    ((num < 1) => (c == 1)) &&
    (div >= 0) &&
    ((c <= num@pre) => (div <= c - 1)) &&
    ((c <= num@pre) => (div > 0 => exists (k:Z), 1 <= k && k < c && num % k == 0)) &&
    ((c <= num@pre) => (forall (k:Z), 1 <= k && k < c => ((num % k == 0) => div >= 1))) &&
    (div == count_div(num, c - 1))
    */
for (int c = 1; c <= num; c++) {
    if (num % c == 0) {
      div++;
    }
  }
		return div;
}