#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_mod5 : Z -> Z) */
/*@ Extern Coq (count_mod4 : Z -> Z) */
/*@ Extern Coq (count_mod3 : Z -> Z) */
/*@ Extern Coq (count_mod2 : Z -> Z) */

void foo71(unsigned int n) 
/*@

Require emp
Ensure emp
*/{

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int v4;
    unsigned int v3;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;
    v3 = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= l && l <= n) &&
    (0 <= j && j <= l) &&
    (0 <= i && i <= l) &&
    (0 <= k && k <= l) &&
    (0 <= v4 && v4 <= l) &&
    (0 <= v3 && v3 <= l) &&
    (n == n@pre) &&
    (l + j + i + k + v4 + v3 >= l) &&
    (j == count_mod2(l)) &&
    (i == count_mod3(l)) &&
    (v4 == count_mod4(l)) &&
    (v3 == count_mod5(l)) &&
    (k + j + i + v4 + v3 == l) &&
    (forall (t:Z), 0 <= t && t < l && t % 5 == 0 => v3 >= 1) &&
    (forall (t:Z), 0 <= t && t < l && t % 4 == 0 && t % 5 != 0 => v4 >= 1) &&
    (forall (t:Z), 0 <= t && t < l && t % 3 == 0 && t % 5 != 0 && t % 4 != 0 => i >= 1) &&
    (forall (t:Z), 0 <= t && t < l && t % 2 == 0 && t % 5 != 0 && t % 4 != 0 && t % 3 != 0 => j >= 1)
    */
    
    while (l < n) {
       if ((l % 5) == 0){
       v3 = v3 + 1;
      }
       else if ((l % 4) == 0) {
       v4 = v4 + 1;
      }
       else if((l % 3) == 0){
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