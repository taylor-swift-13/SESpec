#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (cnt_char : Z -> Z -> Z -> Z -> Z) */
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
    (0 <= i && i <= n) &&
    (0 <= j && j <= m) &&
    (i <= j) &&
    (forall (k:Z), 0 <= k && k < n => s_l[k] == s_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < m => t_l[k] == t_l[k]@pre) &&
    (forall (v:Z), -128 <= v && v < 128 => cnt_char((char*)t, 0, j, v) >= cnt_char((char*)s, 0, i, v)) &&
    ((!(i < n && j < m)) => (i >= n || j >= m))
    */
while (i < n && j < m) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }
        return i == n;
}