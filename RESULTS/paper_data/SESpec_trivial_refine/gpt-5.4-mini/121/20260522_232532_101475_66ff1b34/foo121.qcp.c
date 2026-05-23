#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo121(int * bits, int bits_len) 
/*@
With bits_l
Require store_int_array(bits, bits_len, bits_l)
Ensure Results(__return)
*/{

        int n = bits_len, i = 0;
       
  /*@ Inv
    exists  bits_l,    
    store_int_array(bits, bits_len, bits_l) &&
    (0 <= i && i <= n - 1)
    */
while (i < n - 1) {
            i += bits[i] + 1;
        }
        return i == n - 1;
}