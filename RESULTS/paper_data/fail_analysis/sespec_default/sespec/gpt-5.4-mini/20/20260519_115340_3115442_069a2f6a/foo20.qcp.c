#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <string.h>

int foo20(const char *s1, const char *s2);

int foo20(const char *s1, const char *s2) 
/*@
With s1_l s2_l
Require store_int_array(s1, s2, s1_l) && s2 > 0 && s2 < 100 && store_int_array(s2, 100, s2_l)
Ensure Results(__return)
*/{
    int i = 0;
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int count = ((int)strlen(s1)) - 1; count >= 0; count--) {
        if (s1[count] == s2[i]) return 0;
        ++i;
    }
    return 1;
}