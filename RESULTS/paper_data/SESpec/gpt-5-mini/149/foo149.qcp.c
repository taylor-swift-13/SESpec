#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo149(int a);

int foo149(int a) 
/*@

Require emp
Ensure (exists i_62 mid_61, i_62 > mid_61 && i_62 >= 2 && (mid_61 >= 2 => i_62 <= mid_61 + 1) && mid_61 == a / 2 && (forall k_50, 2 <= k_50 && k_50 < i_62 => a % k_50 != 0) && (forall k_51, 2 <= k_51 && k_51 < i_62 => k_51 <= mid_61) && (i_62 > mid_61 => (forall k_52, 2 <= k_52 && k_52 <= mid_61 => a % k_52 != 0)) && __return == 1) || (exists i_62 mid_61, a % i_62 == 0 && i_62 <= mid_61 && i_62 >= 2 && (mid_61 >= 2 => i_62 <= mid_61 + 1) && mid_61 == a / 2 && (forall k_50, 2 <= k_50 && k_50 < i_62 => a % k_50 != 0) && (forall k_51, 2 <= k_51 && k_51 < i_62 => k_51 <= mid_61) && (i_62 > mid_61 => (forall k_52, 2 <= k_52 && k_52 <= mid_61 => a % k_52 != 0)) && __return == 0)
*/
{

		int i = 2;
		int mid = a/2;

	
 	/*@ Inv
    (i >= 2) &&
    ((mid >= 2) => i <= mid + 1) &&
    (mid == a@pre / 2) &&
    (a == a@pre) &&
    ((forall (k:Z), 2 <= k && k < i => a % k != 0)) &&
    ((forall (k:Z), 2 <= k && k < i => k <= mid)) &&
    ((i > mid) => (forall (k:Z), 2 <= k && k <= mid => a % k != 0))
    */
while (i <= mid) {
			if (a%i == 0)
				return 0;
			i++;
		}
		return 1;
}