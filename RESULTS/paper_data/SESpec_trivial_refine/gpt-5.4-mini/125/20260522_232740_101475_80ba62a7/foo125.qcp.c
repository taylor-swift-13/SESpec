#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (suffix_match : Z -> Z -> Z -> Prop) */

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
    (strlen(txt) >= strlen(pat)) &&
    (-1 <= i && i <= strlen(pat) - 1) &&
    (suffix_match(pat, txt, i))
    */
while(i >= 0) {
	    int j = i - ((int)strlen(pat)) + ((int)strlen(txt));
            if(j < 0 || pat[i] != txt[j])
                return 0;
            i = i - 1;
        }

        return 1;
}