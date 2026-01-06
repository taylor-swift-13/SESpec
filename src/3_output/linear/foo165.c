
/*@
    requires n >= 0 && m >= 0 && m < n;
    */
    
void foo165(int m, int n) {

    int x;
    int y;

    x = 0;
    y = m;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(n,Pre)) ==> (x >= 0 && x <= n);
          loop invariant (0 < \at(n,Pre)) ==> (y == m + (x > m ? x - m : 0));
          loop invariant (!(0 < \at(n,Pre))) ==> ((y == \at(m,Pre))&&(x == 0)&&(n == \at(n,Pre))&&(m == \at(m,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant m == \at(m,Pre);
          loop assigns x, y;
            */
            while(x < n){
       if(x + 1 <= m){
       x = x + 1;
      }
       else if (x + 1 > m){
       x = x + 1;
       y = y + 1;
      }
      }
            

    /*@ assert (x >= n) ==> (y == n); */

  }
