#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo209(int n);

int foo209(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int *lucas = (int *)malloc(sizeof(int) * (n + 1));
int lucas_len = n + 1;
        lucas[0] = 2;
        lucas[1] = 1;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (lucas_len == n + 1) &&
(2 <= i) &&
((i <= n) => i + 1 <= lucas_len) &&
(lucas_l[0] == lucas_val(0)) &&
(lucas_l[1] == lucas_val(1)) &&
((i <= n) => (lucas_l[i - 1] == lucas_val(i - 1) && lucas_l[i - 2] == lucas_val(i - 2))
          loop assigns i, lucas_l[0 .. lucas_len - 1])
    */
    
            for (int i = 2; i <= n; i++) {
            lucas[i] = lucas[i - 1] + lucas[i - 2];
        }
        return lucas[n];
}