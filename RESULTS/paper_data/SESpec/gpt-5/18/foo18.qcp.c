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
   
  /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (N == a_len@pre) &&
    (a_len == a_len@pre) &&
    (a == a@pre)
    */
for (int i = 1; i < N; i++) { // N branches
      int j = i - 1;
      int x = a[i];

      
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= j + 1 <= i;
          loop assigns a[0..N-1], j;
            */
            /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (0 <= j + 1 <= i)
    */
while ((j >= 0) && (a[j] > x)) {
        a[j + 1] = a[j];
        j--;
      }
            
      a[j + 1] = x;
    }
}