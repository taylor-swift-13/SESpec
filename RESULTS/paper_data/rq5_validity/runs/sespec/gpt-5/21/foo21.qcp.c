#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int starts_with_te(const char *s) /*@
With s_l
Require store_int_ptr(s)
Ensure Results(__return)
*/
{
    return s[0] == 't' && s[1] == 'e';
}

int foo21(const char **args, int args_len) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{
    if (args_len < 4) return 0;
    int i = 0;
   
  /*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (0 <= j && j <= 4) &&
    (0 <= i && i <= j) &&
    (forall (k:Z), 0 <= k && k < 4 => true)) &&
    (forall (k:Z), 0 <= k && k < 4 => args_l[k] == args_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < j => ((args_l[k][0] == 't' && args_l[k][1] == 'e') => (i >= 1))) &&
    (forall (k:Z), 0 <= k && k < j => (!(args_l[k][0] == 't' && args_l[k][1] == 'e') => (i >= 0))) &&
    ((j < 4) => (0 <= j && j <= 3)) &&
    ((!(j < 4)) => (j >= 4))
    */
for (int j = 0; j < 4; j++) {
        if (starts_with_te(args[j])) ++i;
    }
    return i == 1;
}