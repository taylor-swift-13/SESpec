
/*@
    requires x >= 0 && x <= 2 && y <= 2 && y >= 0;
    */
    
void foo10(int x,int y) {

  
    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant x == \at(x, Pre) + (y - \at(y, Pre));
          loop invariant y == \at(y, Pre) + (x - \at(x, Pre));
          loop invariant y >= \at(y, Pre) && x >= \at(x, Pre);
          loop invariant (x - \at(x, Pre)) == (y - \at(y, Pre));
          loop invariant (x % 2) == (\at(x, Pre) % 2);
          loop invariant (y % 2) == (\at(y, Pre) % 2);
            */
            while (unknown()) {
      
      x  = x + 2;
      y  = y + 2;

    }
            
      /*@ assert (y == 0) ==> (x != 4);  */
  
  }
