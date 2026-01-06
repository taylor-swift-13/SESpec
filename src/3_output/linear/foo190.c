
/*@
    requires y > -1000 && y < 1000;
    */
    
void foo190(int y) {

    int x;

    x = -50;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant y >= \at(y, Pre);
          loop invariant \at(y, Pre) > 0 ==> y > 0;
          loop invariant y > \at(y, Pre) || x == -50;
          loop invariant y > 0 || x < 0;
          loop assigns x, y;
            */
            while(x < 0){
       x = x + y;
       y = y + 1;
      }
            

    /*@ assert y > 0; */

  }
