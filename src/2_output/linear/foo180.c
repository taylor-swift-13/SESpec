
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo180(int n) 

            /*@
            Require n > 0
            Ensure Results(__return)
            */
            {

    int x;
    int m;

    x = 0;
    m = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < n@pre) => (0 <= x && x <= n)) &&
((0 < n@pre) => (((m == 0)&&(x == 0)&&(n == n@pre)) || (0 <= m && m < x))) &&
((!(0 < n@pre)) => ((m == 0)&&(x == 0)&&(n == n@pre))) &&
(n == n@pre
          loop assigns x, m)
    */
    
            while(x < n){
       if(unknown()){
       m = x;
      }
       x = x + 1;
      }

    

  }