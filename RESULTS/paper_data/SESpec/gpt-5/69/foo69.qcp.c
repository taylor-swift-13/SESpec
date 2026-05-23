#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo69(unsigned int n) 
/*@

Require emp
Ensure emp
*/{

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= l && l <= n) &&
    (0 <= i && i <= l) &&
    (0 <= j && j <= l) &&
    (0 <= k && k <= l) &&
    (i + j + k == l) &&
    (forall (t:Z), 0 <= t && t < l => ((t % 3) == 0 => exists (p:Z), t == 3*p)) &&
    (forall (t:Z), 0 <= t && t < l => (((t % 3) == 0) || (((t % 2) == 0) && ((t % 3) != 0)) || ((t % 2) == 1))) &&
    (forall (t:Z), 0 <= t && t < l => !(((t % 3) == 0) && (((t % 2) == 0) && ((t % 3) != 0)))) &&
    ((l == n) => (i + j + k == n)) &&
    (n == n@pre)
    */
    
    while (l < n) {
        if ((l % 3) == 0) {
            i = i + 1;
        }
        else if((l % 2) == 0){
            j = j + 1;
        }
        else{
            k = k + 1;
        }
        l = l + 1;
    }

  }