#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (prefix_equal : Z -> Z -> Z -> Prop) */
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
    (prefix_equal((char *)pat, (char *)txt, i)) &&
    (i == 0 || pat_l[i-1] == txt_l[i-1]) &&
    (pat == pat@pre) &&
    (txt == txt@pre)
    */
while(i < ((int)strlen(pat))) {
            if(i >= ((int)strlen(txt)) || pat[i] != txt[i])
                return 0;
            i = i + 1;
        }

        return 1;
}