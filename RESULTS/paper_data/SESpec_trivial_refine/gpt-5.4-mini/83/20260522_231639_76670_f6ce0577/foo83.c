
        /*@
        logic integer ipow(integer b, integer e) = (e <= 0) ? 1 : b * ipow(b, e - 1);
        logic integer series(integer b, integer n) = (n <= 0) ? 1 : b * series(b, n - 1) + 1;
        */
        
void foo83(int z,int k,int a){

    int x=a;
    int y=1;
    int c=1;

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant c >= 1;
          loop invariant y == ipow(z, c - 1);
          loop assigns c, x, y;
            */
            while (c < k){
   c = c + 1;
   x = x*z + a;
   y = y*z;
    }
            

  }
