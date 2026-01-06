
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo191(int a, int b) 

            /*@
            Require a <= 1000000 && b >= 0 && b <= 1000000
            Ensure Results(__return)
            */
            {

    int res;
    int cnt;

    res = a;
    cnt = b;


    while(cnt > 0){
       cnt = cnt - 1;
       res = res + 1;
      }

    

  }