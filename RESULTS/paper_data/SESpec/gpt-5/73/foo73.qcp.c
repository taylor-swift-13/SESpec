#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (class7 : Z -> Prop) */
/*@ Extern Coq (class6 : Z -> Prop) */
/*@ Extern Coq (class5 : Z -> Prop) */
/*@ Extern Coq (class4 : Z -> Prop) */
/*@ Extern Coq (class3 : Z -> Prop) */
/*@ Extern Coq (class2 : Z -> Prop) */
/*@ Extern Coq (class1 : Z -> Prop) */
/*@ Extern Coq (classes_partition : Z -> Prop) */
/*@ Extern Coq (classes_disjoint : Z -> Prop) */

void foo73(unsigned int n) 
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
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;
    v3 = 0;
    v2 = 0;
    v1 = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (forall (t:Z), 0 <= t && t < l => classes_partition(t)) &&
    (forall (t:Z), 0 <= t && t < l => classes_disjoint(t)) &&
    (forall (t:Z), 0 <= t && t < l => ((t % 7 == 0) <=> class7(t))) &&
    (forall (t:Z), 0 <= t && t < l => ((t % 7 != 0 && t % 6 == 0) <=> class6(t))) &&
    (forall (t:Z), 0 <= t && t < l => ((t % 7 != 0 && t % 6 != 0 && t % 5 == 0) <=> class5(t))) &&
    (forall (t:Z), 0 <= t && t < l => ((t % 7 != 0 && t % 6 != 0 && t % 5 != 0 && t % 4 == 0) <=> class4(t))) &&
    (forall (t:Z), 0 <= t && t < l => ((t % 7 != 0 && t % 6 != 0 && t % 5 != 0 && t % 4 != 0 && t % 3 == 0) <=> class3(t))) &&
    (forall (t:Z), 0 <= t && t < l => ((t % 7 != 0 && t % 6 != 0 && t % 5 != 0 && t % 4 != 0 && t % 3 != 0 && t % 2 == 0) <=> class2(t))) &&
    (forall (t:Z), 0 <= t && t < l => ((t % 7 != 0 && t % 6 != 0 && t % 5 != 0 && t % 4 != 0 && t % 3 != 0 && t % 2 != 0) <=> class1(t))) &&
    (v1 + v2 + v3 + v4 + i + j + k == l) &&
    (0 <= l && l <= n) &&
    (0 <= v1 && v1 <= l) &&
    (0 <= v2 && v2 <= l) &&
    (0 <= v3 && v3 <= l) &&
    (0 <= v4 && v4 <= l) &&
    (0 <= i && i <= l) &&
    (0 <= j && j <= l) &&
    (0 <= k && k <= l) &&
    ((0 < n@pre) => (l <= n)) &&
    ((0 < n@pre) => (v1 + v2 + v3 + v4 + i + j + k == l)) &&
    ((0 < n@pre) => (0 <= j && j <= l)) &&
    ((0 < n@pre) => (0 <= i && i <= l)) &&
    ((0 < n@pre) => (0 <= k && k <= l)) &&
    ((0 < n@pre) => (0 <= v4 && v4 <= l)) &&
    ((0 < n@pre) => (0 <= v3 && v3 <= l)) &&
    ((0 < n@pre) => (0 <= v2 && v2 <= l)) &&
    ((0 < n@pre) => (0 <= v1 && v1 <= l)) &&
    ((0 < n@pre) => (0 <= l && l <= n)) &&
    ((!(0 < n@pre)) => ((l == 0)&&(v1 == 0)&&(v2 == 0)&&(v3 == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == n@pre))) &&
    (n == n@pre)
    */
    
    while (l < n) {
      if((l % 7) == 0){
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