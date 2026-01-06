
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo164(int n) 

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