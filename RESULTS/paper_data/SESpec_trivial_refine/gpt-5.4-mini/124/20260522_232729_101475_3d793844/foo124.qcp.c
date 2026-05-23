#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo124(const char * s, const char * t) 
/*@
With s_l t_l
Require store_int_ptr(s) && store_int_ptr(t)
Ensure Results(__return)
*/{

        int n = ((int)strlen(s)), m = ((int)strlen(t));
        int i = 0, j = 0;

       
  /*@ Inv
    exists  s_l t_l,    
    store_int_ptr(s) && store_int_ptr(t) &&
    (0 <= i) &&
    (0 <= j) &&
    (i <= j)
    */
while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == n;
}