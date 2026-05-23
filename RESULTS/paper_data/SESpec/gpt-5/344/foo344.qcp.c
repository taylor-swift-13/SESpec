#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo344(int code, int b, int l, int m) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
	
 	/*@ Inv
    (l == l@pre) &&
    (m == m@pre) &&
    (b == b@pre) &&
    (code == code@pre) &&
    (ret >= 0) &&
    (forall (k:Z), l <= k && k < c => ((k % code != 0) || (k % code == 0))) &&
    (ret == 0 => (forall (k:Z), l <= k && k < c => k % code == 0)) &&
    (c <= m@pre => ( ((c % code != 0) && ret + 1 >= ret) || ((c % code == 0) && ret >= 0) )) &&
    ((c <= m@pre) => ((ret < b) => (ret + ((c % code != 0) ? 1 : 0) <= b)))
    */
for (int c = l; c <= m; c++) {
        if (c % code != 0) {
            ret++;
        }
        if (ret == b) {
            return c;
        }
    }
		return -1;
}