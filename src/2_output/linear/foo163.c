
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo163(int n) 

            /*@
            Require n > 0
            Ensure Results(__return)
            */
            {

    int b;
    int j;
    int flag;

    j = 0;
    b = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < n@pre) => (0 <= b && b <= n)) &&
((0 < n@pre) => ((flag == 1) => (j == b)) && ((flag != 1) => (j <= b))) &&
((!(0 < n@pre)) => ((j == 0)&&(b == 0)&&(n == n@pre))) &&
(n == n@pre
          loop assigns j, b)
    */
    
            while(b < n){
       if(flag == 1){
       j = j + 1;
       b = b + 1;
      }
       else if (flag != 1){
       b = b + 1;
      }
      }

    

  }