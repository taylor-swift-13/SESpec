#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (subseq : Z -> Z -> Z -> Z -> Prop) */
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
    (i <= j) &&
    (i == 0 || subseq((char *)s, (char *)t, i, j)) &&
    (forall (k:Z), 0 <= k && k < i => 0 <= k && k < n) &&
    (forall (k:Z), 0 <= k && k < j => 0 <= k && k < m) &&
    (forall (k:Z), 0 <= k && k < n => s_l[k] == s_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < m => t_l[k] == t_l[k]@pre) &&
    ((i < n && j < m) => (s_l[i] != t_l[j] || subseq((char *)s, (char *)t, i + 1, j + 1))) &&
    ((!(i < n && j < m)) => (i >= 0 && j >= 0))
    */
while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == n;
}