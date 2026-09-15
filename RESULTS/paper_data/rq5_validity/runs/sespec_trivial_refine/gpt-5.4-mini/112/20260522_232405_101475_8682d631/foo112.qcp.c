#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (no_dup_lower : Z -> Z -> Prop) */

int foo112(const char * str) 
/*@
With str_l
Require store_int_ptr(str)
Ensure Results(__return)
*/{

        int len = ((int)strlen(str));
        if (len > 26) {
            return 0;
        }
        int num = 0;
       
  /*0*/ 
 /*@ Inv
    exists  str_l,    
    store_int_ptr(str) &&
    (0 <= i && i <= len) &&
    (num >= 0) &&
    (forall (k:Z), 0 <= k && k < i => (num & (1 << (str_l[k] - 'a'))) != 0)
    */
for (int i = 0; i < len; i++) {
            char c = str[i];
            int index = c - 'a';
            if ((num & (1 << index)) != 0) {
                return 0;
            } else {
                num |= (1 << index);
            }
        }
        return 1;
}