
void foo225() {

    int x;

    x = 1;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant x == 1 || x % 2 == 1;
            */
            while(unknown()){
       x = x + 2;
      }
            

    /*@ assert x % 2 == 1; */

  }
