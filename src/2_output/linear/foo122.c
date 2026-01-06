
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo122(int size,int v1,int v2,int v3) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {
 
    int i = 1;
    int sn = 0;
    
     
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((1 <= size@pre) => (1 <= i && i <= size@pre + 1) ) &&
((1 <= size@pre) => (sn == i - 1) ) &&
((!(1 <= size@pre)) => ((sn == 0)&&(i == 1)&&(v3 == v3@pre)&&(v2 == v2@pre)&&(v1 == v1@pre)&&(size == size@pre))) &&
(v3 == v3@pre) &&
(v2 == v2@pre) &&
(v1 == v1@pre) &&
(size == size@pre
          loop assigns sn, i)
    */
    
            while (i <= size) {
  
      i  = (i + 1);
      sn  = (sn + 1);
      
    }
  
    
  
  }