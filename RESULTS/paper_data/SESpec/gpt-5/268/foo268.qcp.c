#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo268(int count, int w) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 1000000007;
		int *div = (int *)malloc(sizeof(int) * (count + 1));
int div_len = count + 1;
		div[0] = 1;
		div[1] = w;
		div[2] = w * w;
	
 	/*@ Inv
    (3 <= d) &&
    (div[0] == 1) &&
    (div[1] == w) &&
    (d >= 2 => div[2] == w * w) &&
    (forall (k:Z), 0 <= k && k < div_len => (k < d || k <= 2) => ( (k == 0 => div[0] == 1) && (k == 1 => div[1] == w) && (k == 2 => (div[2] == w * w || d <= 2)) )) &&
    (forall (k:Z), 3 <= k && k < d => (k-1 >= 0 && k-2 >= 0 && k-1 < d && k-2 < d)) &&
    (forall (k:Z), 0 <= k && k < div_len => (k > count => div[k] == div[k]))
    */
for (int d = 3; d <= count; d++) {
        div[d] = ((w - 1)
                * (div[d - 1] + div[d - 2])) % result;
    }
		return div[count];
}