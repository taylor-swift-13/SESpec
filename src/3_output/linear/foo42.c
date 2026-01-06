
/*@
    requires n > 0;
    */
    
void foo42(int n) {

    int c = 0;

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant ((c == 0)&&(n == \at(n,Pre))) || (c == 1);
          loop invariant n == \at(n,Pre);
          loop assigns c;
            */
            while (unknown()) {
        {
          if (unknown()) {
            if ( c > n )
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
            
           
    /*@ assert ((c < 0)&& (c > n)) ==> (c == n); */
    

}
