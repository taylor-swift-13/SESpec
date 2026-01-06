
/*@
    requires x > 0 && y > 0 && z > 0 && w > 0;
    */
    
void foo222(int w, int x, int y, int z) {


    x = w;
    z = x + 1;
    y = w + 1;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant y == z;
          loop invariant y == \at(w,Pre) + 1 + (\at(y,Here) - \at(y,LoopEntry));
          loop invariant z == \at(w,Pre) + 1 + (\at(z,Here) - \at(z,LoopEntry));
          loop invariant x == \at(w,Pre);
          loop invariant w == \at(w,Pre);
          loop assigns y, z;
            */
            while (unknown()) {
       y = y + 1;
       z = z + 1;
      }
            

  }
