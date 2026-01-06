
/*@
    requires x <= 1 && x >= 0;
    */
    
void foo203(int x) {

    int y;

    y = -3;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant x <= 1;
          loop invariant y >= -3 && (x - y == 4 || x - y <= 3);
          loop assigns x, y;
            */
            while(unknown()){
       if(x - y < 2){
       x = x - 1;
       y = y + 2;
      }
       else if(x - y >= 2){
       y = y + 1;
      }
      }
            

    /*@ assert x <= 1; */

  }
