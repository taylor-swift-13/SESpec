#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <string.h>

int foo122(const char * s);

int foo122(const char * s) 
/*@
With s_l
Require store_int_array(s, 100, s_l)
Ensure Results(__return)
*/{

        int n = ((int)strlen(s));

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for(int i = 0; i < ((int)strlen(s)); i++) {
            if(s[i] != s[n - 1 - i]) {
                return 0;
            }
        }

        return 1;
}