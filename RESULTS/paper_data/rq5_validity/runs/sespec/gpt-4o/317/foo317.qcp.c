#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo317(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		if (num == 1)
			return 1;
	
 	/*@ Inv
    (2 <= size && size <= num + 1) &&
    (result >= 0) &&
    (forall (k:Z), 2 <= k && k < size => (num % k == 0 => k * (num / k) == num)) &&
    (forall (k:Z), 2 <= k && k < size => (num % k == 0 => num / k >= k)) &&
    (forall (k:Z), 2 <= k && k < size => (num % k == 0 => exists (r:Z), r >= 0 && r == result))
    */
for (int size = 2; size <= num / size; size++) {
        if (num % size == 0) {
            result++;
            if (num / size == size) {
                break;
            }
        }
    }
		return result;
}