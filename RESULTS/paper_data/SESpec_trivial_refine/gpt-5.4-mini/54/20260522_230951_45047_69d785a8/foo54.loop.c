
        
        
void foo54() {

    int x;
    int y;

    x = 0;

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant x >= 0;
          loop invariant x <= 101;
          loop assigns x;
            */
            while (x < 99) {
       if(y % 2 == 0){
       x = x + 2;
      }
       else{
       x = x + 1;
      }
      }
            

  }
