#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (prefix_match : Z -> Z -> Z -> Z -> Z) */

int foo124(const char * s, const char * t) 
/*@
With s_l t_l
Require store_int_ptr(s) && store_int_ptr(t)
Ensure Results(__return)
*/{

        int n = ((int)strlen(s)), m = ((int)strlen(t));
        int i = 0, j = 0;

       
  /*0*/ 
 /*@ Inv
    exists  s_l t_l,    
    store_int_ptr(s) && store_int_ptr(t) &&
    (0 <= i && i <= n) &&
    (0 <= j && j <= m) &&
    (forall (k:Z), 0 <= k && k < i => s_l[k] == t_l[k]) &&
    (forall (k:Z), 0 <= k && k < n => s_l[k] == s_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < m => t_l[k] == t_l[k]@pre) &&
    (prefix_match(s, t, i, j) == i) &&
    ((i < n && j < m) => (s_l[i] != t_l[j] => prefix_match(s, t, i, j) == i)) &&
    ((!(i < n && j < m)) => (prefix_match(s, t, i, j) == i))
    */
while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == n;
}