#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo385(int n, int m) 
/*@

Require emp
Ensure Results(__return)
*/{

       
  /*@ Inv
    (i <= n@pre) &&
    (i >= (n@pre < 0 ? n@pre : -1)) &&
    (forall (k:Z), i < k && k <= n@pre => (k % m@pre != 0)) &&
    (forall (k1:Z), forall (k2:Z), i < k1 && k1 <= k2 && k2 <= n@pre => ((k1 % m@pre != 0) => (k2 % m@pre != 0))) &&
    ((i < 0) => (forall (k:Z), 0 <= k && k <= n@pre => (k % m@pre != 0))) &&
    (m == m@pre) &&
    (n == n@pre) &&
    ((i >= 0) => (forall (k:Z), i < k && k <= n@pre => (k % m@pre != 0)))
    */
for (int i = n; i >= 0; i--) {
        if (i % m == 0) {
            return i;
        }
    }
        return -1;
}