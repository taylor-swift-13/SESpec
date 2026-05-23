#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo149(int a) 
/*@

Require emp
Ensure Results(__return)
*/{

		int i = 2;
		int mid = a/2;

	
 	/*@ Inv
    (i == 2 + (i - 2)) &&
    (forall (k:Z), 2 <= k && k < i => (a % k != 0)) &&
    (i >= 2) &&
    (mid == a@pre / 2) &&
    (a == a@pre) &&
    (forall (k:Z), 2 <= k && k < i => !(a % k == 0)) &&
    (i <= mid => i == 2 || i > 2) &&
    ((2 <= a@pre / 2) => (i == mid + 1 => forall (k:Z), 2 <= k && k <= mid => (a % k != 0))) &&
    ((!(2 <= a@pre / 2)) => ((mid == a@pre / 2)&&(i == 2)&&(a == a@pre))) &&
    (mid == a@pre / 2) &&
    (a == a@pre)
    */
while (i <= mid) {
        if (a%i == 0)
            return 0;
        i++;
    }
		return 1;
}