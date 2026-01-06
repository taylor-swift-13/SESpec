
void foo186() {

    int x;
    int y;
    int z;
    int w;

    x = 0;
    y = 0;
    z = 0;
    w = 0;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant  x >= 0;
          loop invariant  y >= 0;
          loop invariant  z % 10 == 0;
          loop invariant  w % 10 == 0;
          loop invariant  3 * x >= y;
          loop invariant  z == w;
          loop assigns x, y, z, w;
            */
            while(unknown()){
       if(x >= 4){
       x = x + 1;
       y = y + 3;
       z = z + 10;
       w = w + 10;
      }
       else if(x >= z && w > y){
       x = 0 - x;
       y = 0 - y;
      }
       else{
       x = x + 1;
       y = y + 2;
      }
      }
            

    /*@ assert 3 * x >= y; */

  }
