
void foo52(int n) {

    int c = 0;

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant ((c == 0)&&(n == \at(n,Pre))) || (c >= 1 && c <= 4);
          loop invariant n == \at(n,Pre);
          loop assigns c;
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
             
   
           
    /*@ assert ((c < 0)&& (c > 4)) ==> (c == 4); */
  

}
