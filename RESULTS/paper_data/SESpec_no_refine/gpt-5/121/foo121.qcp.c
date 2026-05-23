#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo121(int * bits, int bits_len);

int foo121(int * bits, int bits_len) 
/*@
With bits_l
Require store_int_array(bits, bits_len, bits_l) && bits_len > 0 && bits_len < 100
Ensure (0 == bits_len - 1 && 0 >= bits_len - 1 && bits_len > 0 && bits_len < 100 && __return == 1 && store_int_array(bits, bits_len, bits_l))
*/
{

        int n = bits_len, i = 0;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (i < n - 1) {
            i += bits[i] + 1;
        }
        return i == n - 1;
}