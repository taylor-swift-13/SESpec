#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_div9 : Z -> Z) */
/*@ Extern Coq (count_div8_only : Z -> Z) */
/*@ Extern Coq (count_div7_only : Z -> Z) */
/*@ Extern Coq (count_div6_only : Z -> Z) */
/*@ Extern Coq (count_div5_only : Z -> Z) */
/*@ Extern Coq (count_div4_only : Z -> Z) */
/*@ Extern Coq (count_div3_only : Z -> Z) */
/*@ Extern Coq (count_div2_only : Z -> Z) */
/*@ Extern Coq (count_other : Z -> Z) */

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
    (0 <= l && l <= n) &&
    (0 <= j && j <= n) &&
    (0 <= i && i <= n) &&
    (0 <= k && k <= n) &&
    (0 <= v4 && v4 <= n) &&
    (0 <= v3 && v3 <= n) &&
    (0 <= v2 && v2 <= n) &&
    (0 <= v1 && v1 <= n) &&
    (0 <= v5 && v5 <= n) &&
    (0 <= v6 && v6 <= n) &&
    (v6 == count_div9(l)) &&
    (v5 == count_div8_only(l)) &&
    (v1 == count_div7_only(l)) &&
    (v2 == count_div6_only(l)) &&
    (v3 == count_div5_only(l)) &&
    (v4 == count_div4_only(l)) &&
    (i == count_div3_only(l)) &&
    (j == count_div2_only(l)) &&
    (k == count_other(l)) &&
    (l == v6 + v5 + v1 + v2 + v3 + v4 + i + j + k) &&
    ((l < n) => (l % 9 == 0 || l % 8 == 0 || l % 7 == 0 || l % 6 == 0 || l % 5 == 0 || l % 4 == 0 || l % 3 == 0 || l % 2 == 0 || l % 2 != 0)) &&
    ((l == 0) => (v6 == 0 && v5 == 0 && v1 == 0 && v2 == 0 && v3 == 0 && v4 == 0 && i == 0 && j == 0 && k == 0)) &&
    (n == n@pre)
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