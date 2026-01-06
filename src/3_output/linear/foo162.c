
void foo162() {

    int k;
    int i;
    int j;
    int n;
    int turn;

    k = 1;
    i = 1;
    j = 0;
    turn = 0;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant k >= 1;
          loop invariant i >= 1;
          loop invariant j >= 0;
          loop invariant (turn == 0) ==> (j == 0);
          loop invariant (turn == 1) ==> (k >= i - j + 1 && j <= i);
          loop invariant (turn == 2) ==> (k >= i && j == i);
          loop invariant (turn == 0 && i >= n) ==> (k >= n);
            */
            while((turn >= 0) && (turn < 3)){
       if(turn == 0 && i >= n){
       turn = 3;
      }
       else if(turn == 1 && j < i){
       k = k + i - j;
       j = j + 1;
      }
       else if (turn == 1 && j >= i){
       turn = 2;
      }
       else if(turn == 2){
       i = i + 1;
       turn = 0;
      }
      }
            

    /*@ assert (turn == 3) ==> (k >= n); */

  }
