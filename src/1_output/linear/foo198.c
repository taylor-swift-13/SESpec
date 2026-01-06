
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