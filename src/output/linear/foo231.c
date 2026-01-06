
void foo231() {

    unsigned int x;

    x = 0;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= x <= 268435455;
          loop invariant x >= 65521 ==> x % 2 == 1;
          loop assigns x;
            */
            while (x < 268435455) {
       if (x < 65521) {
       x++;
      }
       else {
       x += 2;
      }

      }
            

    /*@ assert (x % 2); */

  }
