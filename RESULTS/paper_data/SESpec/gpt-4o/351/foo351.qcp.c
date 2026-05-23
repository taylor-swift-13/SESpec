#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo351(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

		int i = 0;
		int ret = 0;
		int total = number;
	
 	/*@ Inv
    (total == number@pre >> ret) &&
    (0 <= ret) &&
    ((forall (k:Z), 0 <= k && k < ret => ((k % 2 == 0) => ((i & (1 << k)) != 0)))) &&
    ((forall (k:Z), 0 <= k && k < ret => ((k % 2 != 0) => ((i & (1 << k)) == 0) || (ret > k)))) &&
    ((number@pre > 0) => (total == number@pre >> ret)) &&
    ((number@pre > 0) => (ret >= 0)) &&
    ((!(number@pre > 0)) => ((total == number@pre) && (ret == 0) && (i == 0) && (number == number@pre)))
    */
while (total > 0) {
        if (ret % 2 == 0) {
            i = i | (1 << ret);
        }
        ret++;
        total >>= 1;
    }
		return number ^ i;
}