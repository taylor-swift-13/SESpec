#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo238(int * a, int a_len, int n) 
/*@
With a_l
Require store_int_array(a, a_len, a_l)
Ensure Results(__return)
*/{

        int count = 0;
        int length = a_len;
       
  /*0*/ 
 /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (0 <= i && i <= length) &&
    (count >= 0)
    */
for (int i = 0; i < length; i++) {
           
  /*1*/ 
 /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (0 <= i && i <= length) &&
    (i + 1 <= j && j <= length) &&
    (count >= 0)
    */
for (int j = i + 1; j < length; j++) {
                if ((a[i] ^ a[j]) % 2 == 1) {
                    count++;
                }
            }
        }
        return count;
}