
/*@
    requires k >= 0 && k <= 1;
    */
    
void foo249(int k) {

    int i;
    int j;

    i = 1;
    j = 1;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant k == \at(k, Pre) - (i - 1);
          loop invariant i == 1 + (\at(k, Pre) - k);
          loop invariant j == 1 + (\at(k, Pre) * (i - 1) - (i - 1) * (i - 2) / 2);
          loop assigns i, j, k;
            */
            while (unknown()) {
       i = i + 1;
       j = j + k;
       k = k - 1;
      }
            

    /*@ assert 1 <= i + k; */

  }
