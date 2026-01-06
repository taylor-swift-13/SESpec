
/*@
    requires x > 0 && y > 0 && z > 0 && w > 0;
    */
    
void foo220(int w, int x, int y, int z) {


    x = w;
    z = y;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant w == x;
          loop invariant y == z;
          loop invariant w >= \at(w, Pre);
          loop invariant y <= \at(y, Pre);
            */
            while(unknown()) {
       if (unknown()) {
       w = w + 1;
       x = x + 1;
      }
       else {
       y = y - 1;
       z = z - 1;
      }
      }
            

    /*@ assert w == x; */

  }
