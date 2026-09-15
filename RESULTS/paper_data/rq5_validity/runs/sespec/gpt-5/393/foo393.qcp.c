#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo393(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 1;
	
 	/*@ Inv
    (ret >= 1) &&
    ((loop == 1) => (ret == 1)) &&
    ((loop > 1) => (ret >= loop - 1)) &&
    (forall (k:Z), 1 <= k && k < loop => ret >= k) &&
    (((loop <= num@pre) => (ret * (loop) >= ret))) &&
    (((loop <= num@pre) => (ret * loop >= loop))) &&
    (((loop > num@pre) => (ret >= num@pre))) &&
    (((loop > num@pre) => (ret >= 1))) &&
    (((loop > num@pre) => (ret % 1 == 0))) &&
    (((loop <= num@pre) => (ret == 1 || ret >= loop - 1))) &&
    ((loop <= num@pre) => (ret >= 1)) &&
    (num == num@pre)
    */
for (int loop = 1; loop <= num; loop++) {
        ret *= loop;
    }
		int remainder = (int) (ret % 100);
		return remainder;
}