#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int starts_with_te(const char *s);
int foo21(const char **args, int args_len);

int starts_with_te(const char *s) /*@
With s_l
Require store_int_array(s, 100, s_l)
Ensure Results(__return)
*/
{
    return s[0] == 't' && s[1] == 'e';
}

int foo21(const char **args, int args_len) 
/*@
With args_l
Require store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100
Ensure Results(__return)
*/{
    if (args_len < 4) return 0;
    int i = 0;
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int j = 0; j < 4; j++) {
        if (starts_with_te(args[j])) ++i;
    }
    return i == 1;
}