#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo78_c149(int a);

int foo78_c149(int a) 
/*@

Require emp
Ensure Results(__return)
*/{

		int i = 2;
		int mid = a/2;

	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((2 <= a@pre / 2) => (2 <= i && i <= mid + 1)) &&
((!(2 <= a@pre / 2)) => ((mid == a@pre / 2)&&(i == 2)&&(a == a@pre))) &&
(mid == a@pre / 2) &&
(a == a@pre
          loop assigns i)
    */
    
            while (i <= mid) {
			if (a%i == 0)
				return 0;
			i++;
		}
		return 1;
}