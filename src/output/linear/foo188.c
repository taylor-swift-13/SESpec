
void foo188() {

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
          loop invariant (y <= 2) ==> (x < 4);  // Verification goal as invariant
          loop invariant x >= 0 && x <= w + 4;
          loop invariant (x < 4) ==> (y == 100*x);
          loop invariant z == 10*w;
          loop invariant w >= 0;
          loop assigns x, y, z, w;
            */
            while(unknown()){
       if(x >= 4){
       x = x + 1;
       y = y + 2;

      }
       else if(y > 10 * w && z >= 100 * x){
       y = 0 - y;
      }
       else{
       x = x + 1;
       y = y + 100;
      }
       w = w + 1;
       z = z + 10;
      }
            

    /*@ assert (y <= 2) ==> (x < 4); */

  }
