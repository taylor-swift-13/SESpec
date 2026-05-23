#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_div3 : Z -> Z) */
/*@ Extern Coq (count_div2not3 : Z -> Z) */
/*@ Extern Coq (count_other : Z -> Z) */

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
    (0 <= i) &&
    (0 <= j) &&
    (0 <= k) &&
    (i + j + k == l) &&
    (i == count_div3(l)) &&
    (j == count_div2not3(l)) &&
    (k == count_other(l)) &&
    (l == i + j + k) &&
    (l <= n) &&
    ((0 < n@pre) => (i + j + k == l)) &&
    ((0 < n@pre) => (0 <= j && j <= n)) &&
    ((0 < n@pre) => (0 <= i && i <= n)) &&
    ((0 < n@pre) => (0 <= k && k <= n)) &&
    ((0 < n@pre) => (0 <= l && l <= n)) &&
    ((!(0 < n@pre)) => ((l == 0) && (k == 0) && (i == 0) && (j == 0) && (n == n@pre))) &&
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