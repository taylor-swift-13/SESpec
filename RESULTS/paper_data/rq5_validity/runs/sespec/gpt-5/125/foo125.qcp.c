#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo125(const char * pat, const char * txt) 
/*@
With pat_l txt_l
Require store_int_ptr(pat) && store_int_ptr(txt)
Ensure Results(__return)
*/{

        int i = ((int)strlen(pat)) - 1;

       
  /*0*/ 
 /*@ Inv
    exists  pat_l txt_l,    
    store_int_ptr(pat) && store_int_ptr(txt) &&
    (i + 1 <= strlen(pat)@pre) &&
    (strlen(pat) == strlen(pat)@pre) &&
    (strlen(txt) == strlen(txt)@pre) &&
    (forall (k:Z), 0 <= k && k < strlen(pat)@pre => pat_l[k] == pat_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < strlen(txt)@pre => txt_l[k] == txt_l[k]@pre)
    */
while(i >= 0) {
	    int j = i - ((int)strlen(pat)) + ((int)strlen(txt));
            if(j < 0 || pat[i] != txt[j])
                return 0;
            i = i - 1;
        }

        return 1;
}