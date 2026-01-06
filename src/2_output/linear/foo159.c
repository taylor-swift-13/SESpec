
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo159(int k, int n) 

            /*@
            Require n > 0 && k > n
            Ensure Results(__return)
            */
            {

    int j;

    j = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < n@pre) => (k == k@pre - j)) &&
((0 < n@pre) => (0 <= j && j <= n@pre)) &&
((!(0 < n@pre)) => ((j == 0)&&(n == n@pre)&&(k == k@pre))) &&
(n == n@pre
          loop assigns j, k)
    */
    
            while(j < n){
       j = j + 1;
       k = k - 1;
      }

    

  }