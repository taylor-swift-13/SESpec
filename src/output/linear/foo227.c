
void foo227() {

    int x;
    int y;

    x = 0;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (x % 2) == (y % 2) || x < 99;
          loop invariant y % 2 == 0 ==> x % 10 == 0;
          loop invariant y % 2 != 0 ==> x % 5 == 0;
            */
            while (x < 99) {
       if (y % 2 == 0)
       x += 10;
       else
       x -= 5;
      }
            

    /*@ assert (x % 2) == (y % 2); */

  }
