
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo198(int k, int x, int y) 

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
    ((0 < n) => (x + y == k)) &&
((0 < n) => (y == y@pre - (x - x@pre))) &&
((0 < n) => (0 <= j && j <= n)) &&
((0 < n) => (((m == 0)&&(j == 0)&&(y == y@pre)&&(x == x@pre)&&(k == k@pre)) || (0 <= m && m < n))) &&
((!(0 < n)) => ((m == 0)&&(j == 0)&&(y == y@pre)&&(x == x@pre)&&(k == k@pre))) &&
(k == k@pre
          loop assigns m, j, x, y)
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