#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <string.h>

int foo124(const char * s, const char * t);

int foo124(const char * s, const char * t) 
/*@
With s_l t_l
Require store_int_array(s, t, s_l) && t > 0 && t < 100 && store_int_array(t, 100, t_l)
Ensure Results(__return)
*/{

        int n = ((int)strlen(s)), m = ((int)strlen(t));
        int i = 0, j = 0;

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  s_l t_l,    
    store_int_array(s, t, s_l) && t > 0 && t < 100 && store_int_array(t, 100, t_l) &&
    (forall (k:Z), 0 <= k && k < n => s_l[k] == s_l[k]@pre) &&
(forall (k:Z), 0 <= k && k < m => t_l[k] == t_l[k]@pre
          loop assigns i, j)
    */
    
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == n;
}