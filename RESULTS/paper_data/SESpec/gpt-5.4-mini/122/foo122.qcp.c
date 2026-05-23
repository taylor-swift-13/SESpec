#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo122(const char * s) 
/*@
With s_l
Require store_int_array(s, 100, s_l)
Ensure Results(__return)
*/{

        int n = ((int)strlen(s));

       
  /*@ Inv
    exists  s_l,    
    store_int_array(s, 100, s_l) &&
    (0 <= i) &&
    (forall (k:Z), 0 <= k && k < i => s_l[k] == s_l[n - 1 - k]) &&
    (forall (k:Z), 0 <= k && k < n => s_l[k] == s_l[k]@pre)
    */
for(int i = 0; i < ((int)strlen(s)); i++) {
            if(s[i] != s[n - 1 - i]) {
                return 0;
            }
        }

        return 1;
}