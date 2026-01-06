
/*@
    requires x != y;
    */
    
void foo271(int x, int y) {

    int t;

    y = t;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant y >= t;
          loop assigns y;
            */
            while (unknown()) {
       if(x > 0)
       y = y + x;
      }
            

    /*@ assert y >= t; */

  }
