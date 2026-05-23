#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo70(unsigned int n) 
/*@

Require emp
Ensure emp
*/{

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int v4;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= l && l <= n) &&
    (0 <= i && 0 <= j && 0 <= k && 0 <= v4) &&
    (i <= l && j <= l && k <= l && v4 <= l) &&
    (v4 + i + j + k == l) &&
    (0 <= v4 && 0 <= i && 0 <= j && 0 <= k) &&
    ((l == n) => (v4 + i + j + k == n@pre && n == n@pre)) &&
    ((0 < n@pre) => (v4 + i + j + k <= n@pre)) &&
    ((0 < n@pre) => (j <= n@pre && 0 <= j)) &&
    ((0 < n@pre) => (i <= n@pre && 0 <= i)) &&
    ((0 < n@pre) => (k <= n@pre && 0 <= k)) &&
    ((0 < n@pre) => (v4 <= n@pre && 0 <= v4)) &&
    ((0 < n@pre) => (l <= n@pre && 0 <= l)) &&
    ((!(0 < n@pre)) => ((l == 0) && (v4 == 0) && (k == 0) && (i == 0) && (j == 0) && (n == n@pre))) &&
    (n == n@pre)
    */
    
    while (l < n) {
       if ((l % 4) == 0) {
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