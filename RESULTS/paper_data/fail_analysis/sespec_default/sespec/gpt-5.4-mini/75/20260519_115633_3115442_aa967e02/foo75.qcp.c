#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo75(unsigned int n) 
/*@

Require emp
Ensure emp
*/{

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int v4;
    unsigned int v3;
    unsigned int v2;
    unsigned int v1;
    unsigned int v5;
    unsigned int v6;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;
    v3 = 0;
    v2 = 0;
    v1 = 0;
    v5 = 0;
    v6 = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < n@pre) => (l == i + j + k + v4 + v3 + v2 + v1 + v5 + v6)) &&
((0 < n@pre) => (j >= 0)) &&
((0 < n@pre) => (i >= 0)) &&
((0 < n@pre) => (k >= 0)) &&
((0 < n@pre) => (v4 >= 0)) &&
((0 < n@pre) => (v3 >= 0)) &&
((0 < n@pre) => (v2 >= 0)) &&
((0 < n@pre) => (v1 >= 0)) &&
((0 < n@pre) => (v5 >= 0)) &&
((0 < n@pre) => (v6 >= 0)) &&
((0 < n@pre) => (l <= n)) &&
((!(0 < n@pre)) => ((l == 0)&&(v6 == 0)&&(v5 == 0)&&(v1 == 0)&&(v2 == 0)&&(v3 == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == n@pre))) &&
(n == n@pre
          loop assigns v6, v5, v1, v2, v3, v4, i, j, k, l)
    */
    
            while (l < n) {
       if((l % 9) == 0){
       v6 = v6 + 1;
      }
       else if((l % 8) == 0){
       v5 = v5 + 1;
      }
       else if((l % 7) == 0){
       v1 = v1 + 1;
      }
       else if((l % 6) == 0){
       v2 = v2 + 1;
      }
       else if ((l % 5) == 0){
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