
void foo36() {
    int c = 0;
  
    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant ((c == 0)) || ((1 <= c <= 40) && (c != 40 ==> c <= 39));
          loop assigns c;
            */
            while (unknown()) {
      if (unknown()) {
        if (c != 40) {
          c  = c + 1;
        }
      } else {
        if (c == 40) {
          c  = 1;
        }
      }
    }
            

      /*@ assert (c != 40) ==> (c <= 40);*/
    
  
  }
