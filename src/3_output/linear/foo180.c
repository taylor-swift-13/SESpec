
/*@
    requires n > 0;
    */
    
void foo180(int n) {

    int x;
    int m;

    x = 0;
    m = 0;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(n,Pre)) ==> (0 <= x <= n);
          loop invariant (0 < \at(n,Pre)) ==> (((m == 0)&&(x == 0)&&(n == \at(n,Pre))) || (0 <= m < x));
          loop invariant (!(0 < \at(n,Pre))) ==> ((m == 0)&&(x == 0)&&(n == \at(n,Pre)));
          loop invariant n == \at(n,Pre);
          loop assigns x, m;
            */
            while(x < n){
       if(unknown()){
       m = x;
      }
       x = x + 1;
      }
            

    /*@ assert (x >= n && n > 0) ==> (m < n); */

  }
