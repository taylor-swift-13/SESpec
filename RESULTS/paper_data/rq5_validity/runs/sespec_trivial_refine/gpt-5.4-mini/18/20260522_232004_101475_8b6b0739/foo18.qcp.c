#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
void foo18(int * a, int a_len) 
/*@
With a_l
Require store_int_array(a, a_len, a_l)
Ensure emp
*/{

    int N = a_len;
   
  /*0*/ 
 /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (1 <= i && i <= N) &&
    (forall (k:Z), 0 <= k && k < i - 1 => a_l[k] <= a_l[k + 1])
    */
for (int i = 1; i < N; i++) { // N branches
      int j = i - 1;
      int x = a[i];

     
  /*1*/ 
 /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (-1 <= j && j < i) &&
    (1 <= i && i <= N) &&
    (forall (k:Z), j + 1 <= k && k <= i - 1 => a_l[k] > x)
    */
while ((j >= 0) && (a[j] > x)) {
        a[j + 1] = a[j];
        j--;
      }
      a[j + 1] = x;
    }
}