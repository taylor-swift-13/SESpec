
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo177(int k, int z) 

            /*@
            Require z == k
            Ensure Results(__return)
            */
            {

    int x;
    int y;
    int c;
    int turn;

    x = 0;
    y = 0;
    turn = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while(unknown()){
       if(turn == 0){
       c = 0;
       if(unknown()){
       turn = 1;
      }
       else{
       turn = 2;
      }
      }
       else if(turn == 1){
       if(z == (k + y - c)){
       y = y + 1;
       x = x + 1;
       c = c + 1;
       turn = 2;
      }
       else{
       y = y - 1;
       x = x + 1;
       c = c + 1;
       if(unknown()){
       turn = 2;
      }
      }
      }
       else if(turn == 2){
       x = x - 1;
       y = y - 1;
       if(unknown()){
       turn = 3;
      }
      }
       else if(turn > 2 || turn < 0){
       z = x + y;
       turn = 0;
      }
      }

    

  }