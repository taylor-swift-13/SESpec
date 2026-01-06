
/*@
    requires x >= 0 && y >= 0 && x == y;
    */
    
void foo174(int x, int y) {

    int n;

    n = 0;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant x == y;
          loop invariant (\at(x,Pre) != 0) ==> (x >= n);
          loop invariant (!(\at(x,Pre) != 0)) ==> ((n == 0)&&(y == \at(y,Pre))&&(x == \at(x,Pre)));
          loop invariant n == 0;
          loop assigns x, y;
            */
            while(x != n){
       x = x - 1;
       y = y - 1;
      }
            

    /*@ assert (x == n) ==> (y == n); */

  }
