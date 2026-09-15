#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo123(const char * pat, const char * txt) 
/*@
With pat_l txt_l
Require store_int_ptr(pat) && store_int_ptr(txt)
Ensure Results(__return)
*/{

        int i = 0;

       
  /*@ Inv
    exists  pat_l txt_l,    
    store_int_ptr(pat) && store_int_ptr(txt) &&
    (0 <= i) &&
    (forall (k:Z), 0 <= k && k < strlen(pat) => pat_l[k] == pat_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < strlen(txt) => txt_l[k] == txt_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < i => k < strlen(txt)) &&
    (forall (k:Z), 0 <= k && k < i => pat_l[k] != '\0' && txt_l[k] != '\0') &&
    ((!(i < (strlen(pat)))) => true)
    */
while(i < ((int)strlen(pat))) {
            if(i >= ((int)strlen(txt)) || pat[i] != txt[i])
                return 0;
            i = i + 1;
        }

        return 1;
}