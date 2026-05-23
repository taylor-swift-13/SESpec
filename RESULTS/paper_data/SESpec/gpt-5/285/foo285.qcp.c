#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (divcnt : Z -> Z -> Z -> Z) */
const char * foo285(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int count = 0;
       
  /*@ Inv
    (n == n@pre) &&
    ((i == 1) || (1 <= i && i <= n + 1)) &&
    (0 <= count <= (i - 1)) &&
    (count == divcnt(n@pre, 1, i - 1)) &&
    ((i <= n) => (count + ((n % i == 0) ? 1 : 0) == divcnt(n@pre, 1, i))) &&
    ((i == n + 1) => (count == divcnt(n@pre, 1, n)))
    */
for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
        if (count % 2 == 0) {
            return "Even";
        } else {
            return "Odd";
        }
}