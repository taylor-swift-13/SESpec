#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
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
    (0 <= i) &&
    (count >= -1) &&
    (count <= strlen(s1) - 1) &&
    (i == (strlen(s1) - 1) - count) &&
    ((count < 0) => (i == strlen(s1))) &&
    (forall (p:Z), 0 <= p && p <= strlen(s1) => s1_l[p] == s1_l[p]@pre) &&
    (forall (q:Z), 0 <= q && q <= strlen(s2) => s2_l[q] == s2_l[q]@pre)
    */
for (int count = ((int)strlen(s1)) - 1; count >= 0; count--) {
        if (s1[count] == s2[i]) return 0;
        ++i;
    }
    return 1;
}