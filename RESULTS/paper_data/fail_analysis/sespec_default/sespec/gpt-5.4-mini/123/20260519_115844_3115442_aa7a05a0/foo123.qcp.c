#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <string.h>

int foo123(const char * pat, const char * txt);

int foo123(const char * pat, const char * txt) 
/*@
With pat_l txt_l
Require store_int_array(pat, txt, pat_l) && txt > 0 && txt < 100 && store_int_array(txt, 100, txt_l)
Ensure Results(__return)
*/{

        int i = 0;

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  pat_l txt_l,    
    store_int_array(pat, txt, pat_l) && txt > 0 && txt < 100 && store_int_array(txt, 100, txt_l) &&
    (0 <= i) &&
(forall (k:Z), 0 <= k && k < i => pat_l[k] == txt_l[k]
          loop assigns i)
    */
    
            while(i < ((int)strlen(pat))) {
            if(i >= ((int)strlen(txt)) || pat[i] != txt[i])
                return 0;
            i = i + 1;
        }

        return 1;
}