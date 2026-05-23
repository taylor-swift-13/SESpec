#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo359(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
		int total = 0;
	
 	/*@ Inv
    (size == size@pre) &&
    ((c <= size@pre) => (0 <= ret)) &&
    ((c <= size@pre) => (0 <= total && total <= c - 1)) &&
    ((c <= size@pre) => (forall (k:Z), 1 <= k && k < c && k % 2 == 1 => 1 <= k && k < c)) &&
    ((c <= size@pre) => (ret >= total)) &&
    ((c <= size@pre) => (ret >= 0 && total >= 0)) &&
    ((c <= size@pre) => ((c % 2 == 0) => (ret == (c/2) * (c/2)))) &&
    ((c <= size@pre) => ((c % 2 == 1) => (ret == (c/2) * (c/2)))) &&
    ((c <= size@pre) => ((ret == 0) => (total == 0) => (c == 1))) &&
    ((c <= size@pre) => (1 <= c => ret >= (c >= 2 ? 1 : 0))) &&
    ((c <= size@pre) => (total <= size)) &&
    ((c <= size@pre) => (ret > 0 || total == 0)) &&
    ((c <= size@pre) => (total == 0 => c <= 1)) &&
    ((c <= size@pre) => (c >= 1)) &&
    ((c <= size@pre) => (total <= c - 1))
    */
for (int c = 1; c <= size; c++) {
        if (c % 2 != 0) {
            ret += c;
            total++;
        }
    }
		return ret / total;
}