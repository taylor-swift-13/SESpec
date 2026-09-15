#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo186_c294(int p);

int foo186_c294(int p) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *arr = (int *)malloc(sizeof(int) * (p + 1));
int arr_len = p + 1;
		arr[0] = 0;
		arr[1] = 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (2 <= count) &&
(arr_len == p + 1) &&
(arr_l[0] == 0) &&
((arr_len >= 2) => (arr_l[1] == 1)) &&
((count >= 3) => (arr_l[count - 1] == ((2 * arr_l[count - 2] + arr_l[count - 3]) % 1000000000))) &&
((count <= p) => (0 <= count && count < arr_len)
      loop assigns count, arr_l[2..p])
    */
    
    for (int count = 2; count <= p; count++) {
        arr[count] = (2 * arr[count - 1]
                      + arr[count - 2]) % 1000000000;
    }
		return arr[p];
}