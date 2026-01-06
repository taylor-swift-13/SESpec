
void foo130(int x2,int x3) {

    int d1 = 1;
    int d2 = 1;
    int d3 = 1;
    int x1 = 1;

    
    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant x2 == \at(x2, Pre) - (1 - x1);
          loop invariant x3 == \at(x3, Pre) - (1 - x1);
          loop invariant x1 == 1 - (\at(x2, Pre) - x2);
          loop invariant x1 >= 0;
          loop invariant x2 >= 0 || x1 == 1;
          loop invariant x3 >= \at(x3, Pre) - 1;
          loop invariant d3 == 1;
          loop invariant d2 == 1;
          loop invariant d1 == 1;
          loop invariant (x2 > 0 && x3 > 0) ==> x1 >= 0;
            */
            while(x1 > 0) {
        if(x2 > 0) {
            if(x3 > 0) {
                x1 = x1 - d1;
                x2 = x2 - d2;
                x3 = x3 - d3;
            }
        }
    }
            

    /*@ assert x2 >= 0;*/


}
