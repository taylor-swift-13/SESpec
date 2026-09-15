#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo149(int a);

int foo149(int a) 
/*@

Require emp
Ensure (exists i_62 mid_61, i_62 > mid_61 && 2 <= i_62 && i_62 <= mid_61 + 1 && (forall k_50, 2 <= k_50 && k_50 < i_62 => a % k_50 != 0) && __return == 1) || (exists i_62 mid_61, a % i_62 == 0 && i_62 <= mid_61 && 2 <= i_62 && i_62 <= mid_61 + 1 && (forall k_50, 2 <= k_50 && k_50 < i_62 => a % k_50 != 0) && __return == 0)
*/
{

		int i = 2;
		int mid = a/2;

	
 	/*0*/ 
 /*@ Inv
    (2 <= i && i <= mid + 1) &&
    (forall (k:Z), 2 <= k && k < i => a % k != 0)
    */
while (i <= mid) {
			if (a%i == 0)
				return 0;
			i++;
		}
		return 1;
}