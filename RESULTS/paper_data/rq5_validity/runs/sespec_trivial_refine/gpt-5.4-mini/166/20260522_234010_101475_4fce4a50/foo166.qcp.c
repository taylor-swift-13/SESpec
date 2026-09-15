#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo166(int * a, int a_len, int n) 
/*@
With a_l
Require store_int_array(a, a_len, a_l)
Ensure Results(__return)
*/{

        if (a == NULL) {
            return -1;
        }
        if (a_len == 1) {
            return 0;
        }

        int evenPairCount = 0;
       
  /*0*/ 
 /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (0 <= i && i <= a_len) &&
    (evenPairCount >= 0)
    */
for (int i = 0; i < a_len; i++) {
           
  /*1*/ 
 /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (0 <= j && j <= a_len) &&
    (evenPairCount >= 0)
    */
for (int j = i + 1; j < a_len; j++) {
                int x = a[i];
                int y = a[j];
                int v = x ^ y;
                if ((v & 1) == 0) {
                    evenPairCount++;
                }
            }
        }
        return evenPairCount;
}