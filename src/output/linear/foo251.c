
/*@
    requires k >= 0 && k <= 1;
    */
    
void foo251(int k) {

    int i;
    int j;

    i = 1;
    j = 1;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant k <= 1;
          loop invariant i >= 1;
          loop invariant i + k >= 1;
          loop assigns i, j, k;
            */
            while (unknown()) {
       i = i + 1;
       j = j + k;
       k = k - 1;
      }
            

    /*@ assert i >= 1; */

  }
