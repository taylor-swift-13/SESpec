#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (cstring : Z -> Prop) */

int foo122(const char * s) 
/*@
With s_l
Require store_int_ptr(s)
Ensure Results(__return)
*/{

        int n = ((int)strlen(s));

       
  /*0*/ 
 /*@ Inv
    exists  s_l,    
    store_int_ptr(s) &&
    (0 <= i && i <= n) &&
    (forall (k:Z), 0 <= k && k < i => s_l[k] == s_l[n - 1 - k])
    */
for(int i = 0; i < ((int)strlen(s)); i++) {
            if(s[i] != s[n - 1 - i]) {
                return 0;
            }
        }

        return 1;
}