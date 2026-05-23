#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo362(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int total = 0;
	
 	/*@ Inv
    (size == size@pre) &&
    (0 <= result) &&
    (0 <= total && total <= (c - 1)) &&
    (forall (k:Z), (1 <= k && k < c && k % 2 == 0) => (result >= k)) &&
    (forall (k1:Z), forall (k2:Z), (1 <= k1 && k1 < c && 1 <= k2 && k2 < c && k1 % 2 == 0 && k2 % 2 == 0 && k1 != k2) => (result >= k1 + k2)) &&
    (forall (k:Z), (1 <= k && k < c && k % 2 == 0) => (total >= 1)) &&
    ((c <= size@pre) => (total <= c - 1)) &&
    ((c <= size@pre) => (forall (k:Z), (1 <= k && k < c && k % 2 == 0) => (result >= k))) &&
    ((c <= size@pre) => (0 <= result)) &&
    ((c <= size@pre) => (0 <= total && total <= c - 1)) &&
    (size == size@pre)
    */
for (int c = 1; c <= size; c++) {
        if (c % 2 == 0) {
            result += c;
            total++;
        }
    }
		return result / total;
}