
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo154(int x) 

            /*@
            Require x > 0
            Ensure Results(__return)
            */
            {

    int i;
    int j;

    j = 0;
    i = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < x@pre) => (i >= 0 && i <= x && j == 2 * i)) &&
((0 < x@pre) => (j >= 0 && j <= 2 * x)) &&
((!(0 < x@pre)) => ((j == 0)&&(i == 0)&&(x == x@pre))) &&
(x == x@pre
        loop assigns j, i)
    */
    
    while(i < x) {
        j = j + 2;
        i = i + 1;
    }

    

  }