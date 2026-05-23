
        /*@
        
        */
        
void foo55(unsigned int y) {

    unsigned int x;

    x = 2;

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant x >= 2;
          loop invariant x <= y;
          loop assigns x;
            */
            while (x < y) {
       if (x < y / x) {
       x *= x;
      }
       else {
       x++;
      }
      }
            

  }
