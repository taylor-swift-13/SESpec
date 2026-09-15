#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_row_prefix : Z -> Z -> Z -> Z) */
/*@ Extern Coq (count_row : Z -> Z -> Z -> Z) */
/*@ Extern Coq (pairs_leq : Z -> Z -> Z -> Z) */
int foo311(int count) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
	
 	/*@ Inv
    (1 <= index && index <= 2 * count + 1) &&
    (0 <= result) &&
    (center == (2 * count) * (2 * count)) &&
    (diameter == 2 * count) &&
    (result == pairs_leq(index - 1, count, center))
    */
for (int index = 1; index <= 2 * count; index++) {
		
		/*@
		  loop invariant 1 <= i && i <= 2 * count + 1;
		  loop invariant 0 <= result;
		  loop invariant center == (2 * count) * (2 * count);
		  loop invariant diameter == 2 * count;
		  loop invariant result == pairs_leq(index - 1, count, center) + count_row_prefix(index, i - 1, center);
		  loop assigns i, result;
		*/
		/*@ Inv
    (1 <= i && i <= 2 * count + 1) &&
    (0 <= result) &&
    (center == (2 * count) * (2 * count)) &&
    (diameter == 2 * count) &&
    (result == pairs_leq(index - 1, count, center) + count_row_prefix(index, i - 1, center))
    */
for (int i = 1; i <= 2 * count; i++) {
			int diagnalLengthSquare = (index * index + i * i);
			if (diagnalLengthSquare <= center) {
				result++;
			}
		}
		
	}
		return result;
}