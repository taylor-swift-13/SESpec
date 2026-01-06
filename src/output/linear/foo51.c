
void foo51(int n) {

    int c = 0;

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant ((c == 0)&&(n == \at(n,Pre))) || ((1 <= c <= 4) && (n == \at(n,Pre)));
          loop invariant n == \at(n,Pre);
            */
            while (unknown()) {
        {
          if (unknown()) {
            if ( c != 4 )
            {
            c  = c + 1;
            }
          } else {
            if (c == 4) 
            {
            c  = 1;
            }
          }
    
        }
    
    }
             
          
    /*@ assert  (c != 4 ) ==> (c <= 4); */
  

}
