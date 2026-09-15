#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (c_string : Z -> Prop) */

int foo20(const char *s1, const char *s2) 
/*@
With s1_l s2_l
Require store_int_ptr(s1) && store_int_ptr(s2)
Ensure Results(__return)
*/{
    int i = 0;
   
  /*0*/ 
 /*@ Inv
    exists  s1_l s2_l,    
    store_int_ptr(s1) && store_int_ptr(s2) &&
    (0 <= i <= \strlen(s1)) &&
    (-1 <= count <= \strlen(s1) - 1) &&
    (i + count == \strlen(s1) - 1)
    */
for (int count = ((int)strlen(s1)) - 1; count >= 0; count--) {
        if (s1[count] == s2[i]) return 0;
        ++i;
    }
    return 1;
}