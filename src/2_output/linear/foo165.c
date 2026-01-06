
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo165(int m, int n) 

            /*@
            Require n >= 0 && m >= 0 && m < n
            Ensure Results(__return)
            */
            {

    int x;
    int y;

    x = 0;
    y = m;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < n@pre) => (x >= 0 && x <= n)) &&
((0 < n@pre) => (y == m + (x > m ? x - m : 0))) &&
((!(0 < n@pre)) => ((y == m@pre)&&(x == 0)&&(n == n@pre)&&(m == m@pre))) &&
(n == n@pre) &&
(m == m@pre
          loop assigns x, y)
    */
    
            while(x < n){
       if(x + 1 <= m){
       x = x + 1;
      }
       else if (x + 1 > m){
       x = x + 1;
       y = y + 1;
      }
      }

    

  }