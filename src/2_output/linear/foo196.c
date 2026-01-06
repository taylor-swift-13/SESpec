
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo196(int k, int x, int y) 

            /*@
            Require k == x + y
            Ensure Results(__return)
            */
            {

    int i;
    int j;
    int m;
    int n;

    m = 0;
    j = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < n) => (k == x + y)) &&
((0 < n) => (x + y == x@pre + y@pre)) &&
((0 < n) => (j >= 0 && j <= n)) &&
((0 < n) => (((m == 0)&&(j == 0)&&(y == y@pre)&&(x == x@pre)&&(k == k@pre)) || (m >= 0 && m <= j))) &&
((!(0 < n)) => ((m == 0)&&(j == 0)&&(y == y@pre)&&(x == x@pre)&&(k == k@pre))) &&
(k == k@pre
          loop assigns j, m, x, y)
    */
    
            while(j < n){
       if(unknown()){
       m = j;
      }
       if(j == i){
       x = x + 1;
       y = y - 1;
      }
       else{
       x = x - 1;
       y = y + 1;
      }
       j = j + 1;
      }

    

  }