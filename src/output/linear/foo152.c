
void foo152() {

    int i;
    int pvlen;
    int t;
    int k;
    int n;
    int j;
    int turn;

    k = 0;
    i = 0;
    turn = 0;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant  ((turn == 0)&&(k == 0)&&(i == 0)) || 
                         ((turn >= 0) && (turn <= 5)) ;
          loop invariant k >= 0;
          loop invariant (turn < 2) ==> (k == 0);
          loop assigns k, i, pvlen, t, n, j, turn;
            */
            while(turn < 5){
       if(turn == 0){
       i = i + 1;
       if(unknown()){
       turn = 1;
      }
      }
       else if(turn == 1){
       if(i > pvlen){
       pvlen = i;
      }
       i = 0;
       turn = 2;
      }
       else if(turn == 2){
       t = i;
       i = i + 1;
       k = k + 1;
       if(unknown()){
       turn = 3;
      }
      }
       else if(turn == 3){
       if(unknown()){
       turn = 4;
      }
      }
       else if(turn == 4){
       n = i;
       j = 0;
       turn = 5;
      }
      }
            

    /*@ assert k >= 0; */

  }
