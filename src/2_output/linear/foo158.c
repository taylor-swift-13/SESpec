
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo158(int m) 

            /*@
            Require m > 0
            Ensure Results(__return)
            */
            {

    int a;
    int j;

    a = 0;
    j = 1;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((1 <= m@pre) => (-j + 1 <= a && a <= j - 1)) &&
((1 <= m@pre) => (1 <= j && j <= m + 1)) &&
((!(1 <= m@pre)) => ((j == 1)&&(a == 0)&&(m == m@pre))) &&
(m == m@pre
          loop assigns a, j)
    */
    
            while(j <= m){
       if(unknown()){
       a = a + 1;
      }
       else{
       a = a - 1;
      }
       j = j + 1;
      }

    

  }