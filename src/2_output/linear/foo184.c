
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo184(int n) 

            /*@
            Require n == 1 || n == 2
            Ensure Results(__return)
            */
            {

    int i;
    int j;
    int k;

    i = 0;
    j = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 <= k) => (i >= 0 && i <= k + 1)) &&
((0 <= k) => (j == i * n)) &&
((!(0 <= k)) => ((j == 0)&&(i == 0)&&(n == n@pre))) &&
(n == n@pre
          loop assigns i, j)
    */
    
            while(i <= k){
       i = i + 1;
       j = j + n;
      }

    

  }