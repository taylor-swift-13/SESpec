
        /*@
        
        */
        

void foo59() {

    unsigned int x;
    unsigned int y;

    y = 1;

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \true;
          loop invariant \true;
          loop assigns x, y;
            */
            while(unknown()){
       if(x % 3 == 1){
       x = x + 2;
       y = 0;
      }
       else{
       if(x % 3 == 2){
       x = x + 1;
       y = 0;
      }
       else{
       if(unknown()){
       x = x + 4;
       y = 1;
      }
       else{
       x = x + 5;
       y = 1;
      }
      }
      }
      }
            

  }
