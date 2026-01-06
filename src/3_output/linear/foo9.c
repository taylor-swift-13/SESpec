
/*@
    requires x >= 0 && x <= 2 && y <= 2 && y >= 0;
    */
    
void foo9(int x,int y) {

  
    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant x == \at(x, Pre) + 2 * (\at(x, Here) - \at(x, Pre))/2;
          loop invariant y == \at(y, Pre) + 2 * (\at(y, Here) - \at(y, Pre))/2;
          loop invariant (x - \at(x, Pre)) % 2 == 0;
          loop invariant (y - \at(y, Pre)) % 2 == 0;
          loop invariant x >= \at(x, Pre) && y >= \at(y, Pre);
          loop invariant (x == \at(x, Pre)) ==> (y == \at(y, Pre));
          loop invariant (x == \at(x, Pre) + 2) ==> (y >= \at(y, Pre) + 2);
          loop invariant (x == \at(x, Pre) + 4) ==> (y >= \at(y, Pre) + 4);
          loop assigns x, y;
            */
            while (unknown()) {
      
      x  = x + 2;
      y  = y + 2;

    }
            
  
    /*@ assert (x == 4) ==> (y != 0);  */
  
    
  
  }
