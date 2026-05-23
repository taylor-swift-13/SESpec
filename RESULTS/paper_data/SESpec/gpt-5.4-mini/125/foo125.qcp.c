#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <string.h>

int foo125(const char * pat, const char * txt);

int foo125(const char * pat, const char * txt) 
/*@
With pat_l txt_l
Require store_int_array(pat, txt, pat_l) && txt > 0 && txt < 100 && store_int_array(txt, 100, txt_l)
Ensure Results(__return)
*/{

        int i = ((int)strlen(pat)) - 1;

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  pat_l txt_l,    
    store_int_array(pat, txt, pat_l) && txt > 0 && txt < 100 && store_int_array(txt, 100, txt_l) &&
    (forall (k:Z), 0 <= k && k < ((int)strlen(pat)) => pat_l[k] == pat_l[k]@pre) &&
(forall (k:Z), 0 <= k && k < ((int)strlen(txt)) => txt_l[k] == txt_l[k]@pre
          loop assigns i)
    */
    
        while(i >= 0) {
	    int j = i - ((int)strlen(pat)) + ((int)strlen(txt));
            if(j < 0 || pat[i] != txt[j])
                return 0;
            i = i - 1;
        }

        return 1;
}