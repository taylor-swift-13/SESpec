
        /*@ */
        
void foo67(int n) {

    int i;
    int k;
    int j;

    i = 0;
    j = 0;
    k = 0;

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i;
          loop invariant i % 3 == 0;
          loop invariant i == j + k;
          loop assigns i, j, k;
            */
            while(i < n){
       i = i + 3;
       if((i % 2) != 0)
       j = j + 3;
       else
       k = k + 3;
      }
            

  }
