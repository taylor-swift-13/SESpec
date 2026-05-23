#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo68(unsigned int n) 
/*@

Require emp
Ensure emp
*/{

    unsigned int j;
    unsigned int i;
    unsigned int l;

    i = 0;
    j = 0;
    l = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= l && l <= n) &&
    (0 <= i && i <= l) &&
    (0 <= j && j <= l) &&
    (i + j == l) &&
    (forall (k:Z), 0 <= k && k < l => ((k % 2 == 0) => (i >= 1)) || ((k % 2 == 1) => (j >= 1)) || (l == 0)) &&
    (i == (l + 1) / 2 && j == l / 2 || i == l / 2 && j == (l + 1) / 2) &&
    ((l % 2 == 0) => (i == j)) &&
    ((l % 2 == 1) => (i == j + 1)) &&
    (forall (k:Z), 0 <= k && k < l => ((k % 2 == 0) || (k % 2 == 1))) &&
    ((l == n) => (i + j == n)) &&
    ((0 < n@pre) => (i + j == l)) &&
    ((0 < n@pre) => (0 <= j && j <= l)) &&
    ((0 < n@pre) => (0 <= i && i <= l)) &&
    ((0 < n@pre) => (0 <= l && l <= n)) &&
    ((!(0 < n@pre)) => ((l == 0)&&(i == 0)&&(j == 0)&&(n == n@pre))) &&
    (n == n@pre)
    */
    
    while (l < n) {
        if ((l % 2) == 0) {
            i = i + 1;
        }
        else{
            j = j + 1;
        }
        l = l + 1;
    }

  }