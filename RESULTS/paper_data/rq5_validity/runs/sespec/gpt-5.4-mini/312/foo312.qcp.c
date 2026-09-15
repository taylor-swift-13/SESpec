#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo312(int count) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
	
 	/*@ Inv
    (count == count@pre) &&
    (diameter == 2 * count@pre) &&
    (center == 2 * count@pre * (2 * count@pre)) &&
    (1 <= i) &&
    (0 <= ret) &&
    (ret <= (i - 1) * (2 * count@pre)) &&
    ((i <= 2 * count@pre) => (ret >= 0)) &&
    ((i <= 2 * count@pre) => (ret <= (i - 1) * (2 * count@pre))) &&
    ((!(i <= 2 * count@pre)) => (ret <= (2 * count@pre) * (2 * count@pre)))
    */
for (int i = 1; i <= 2 * count; i++) {
			
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= ret;
          loop invariant 1 <= c <= 2 * count + 1;
          loop invariant ret <= (i - 1) * (2 * count) + (c - 1);
          loop assigns c, ret;
            */
            /*@ Inv
    (0 <= ret) &&
    (1 <= c && c <= 2 * count + 1) &&
    (ret <= (i - 1) * (2 * count) + (c - 1))
    */
for (int c = 1; c <= 2 * count; c++) {
				int diagnalLengthSquare = (i * i + c * c);
				if (diagnalLengthSquare <= center) {
					ret++;
				}
			}
            
		}
		return ret;
}