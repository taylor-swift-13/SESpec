
/*@
    requires n > 0;
    */
    
void foo46(int n) {

    int c = 0;

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant ((c == 0)&&(n == \at(n,Pre))) || ((1 <= c <= n) && (n == \at(n,Pre)));
          loop invariant n == \at(n,Pre);
            */
            while (unknown()) {
        {
          if (unknown()) {
            if ( c != n )
            {
            c  = c + 1;
            }
          } else {
            if (c == n) 
            {
            c  = 1;
            }
          }
    
        }
    
    }
               
    /*@ assert  (c != n ) ==> (c <= n); */
    

  

}
