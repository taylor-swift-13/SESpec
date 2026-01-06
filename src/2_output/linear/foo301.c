
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo301(int n) 

            /*@
            Require n <= 50000001
            Ensure Results(__return)
            */
            {

    int i;
    int j;

    i = 0;
    j = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < n@pre) => (i % 3 == 0 && i >= 0)) &&
((!(0 < n@pre)) => ((j == 0)&&(i == 0)&&(n == n@pre))) &&
(j == 0) &&
(n == n@pre
          loop assigns i)
    */
    
            while(i < n){
       if(unknown())
       i = i + 6;
       else
       i = i + 3;
      }

    

  }