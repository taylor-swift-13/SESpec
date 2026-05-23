
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
void foo66(int y) {

    int x;

    x = 4 * y;

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant x == 4 * y;
          loop invariant x % 4 == 0;
          loop assigns x, y;
            */
            while (x > 0) {
       x -= 4;
       y--;
      }
            

  }
