
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo118(int size) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {
 
    int i = 1;
    int sn = 0;
    
     
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((1 <= size@pre) => (sn == i - 1)) &&
((1 <= size@pre) => (i <= size + 1)) &&
((!(1 <= size@pre)) => ((sn == 0)&&(i == 1)&&(size == size@pre))) &&
(size == size@pre
      loop assigns sn, i)
    */
    
    while (i <= size) {
        i = (i + 1);
        sn = (sn + 1);
    }
  
    
  
  }