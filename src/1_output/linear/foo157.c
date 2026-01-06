
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo157(int m) 

            /*@
            Require m > 0
            Ensure Results(__return)
            */
            {

    int a;
    int j;

    a = 0;
    j = 1;


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