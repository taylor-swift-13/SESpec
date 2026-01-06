
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo175(int n) 

            /*@
            Require n > 0
            Ensure Results(__return)
            */
            {

    int i;
    int c;

    i = 0;
    c = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < n@pre) => (0 <= i && i <= n)) &&
((0 < n@pre) => (c == (i*(i-1))/2)) &&
((!(0 < n@pre)) => ((c == 0)&&(i == 0)&&(n == n@pre))) &&
(n == n@pre
        loop assigns c, i)
    */
    
    while(i < n) {
       c = c + i;
       i = i + 1;
    }

    

  }