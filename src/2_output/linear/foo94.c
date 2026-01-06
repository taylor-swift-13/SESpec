
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo94(int n,int k) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {
  
    int i = 0;
    int j = 0;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 <= n@pre) => (i >= 0 && i <= n@pre + 1)) &&
((0 <= n@pre) => (j == i * (i + 1) / 2)) &&
((!(0 <= n@pre)) => ((j == 0)&&(i == 0)&&(k == k@pre)&&(n == n@pre))) &&
(k == k@pre) &&
(n == n@pre
      loop assigns i, j)
    */
    
    while (i <= n) {
       i = i + 1;
       j = j + i;
    }
    
  
  }