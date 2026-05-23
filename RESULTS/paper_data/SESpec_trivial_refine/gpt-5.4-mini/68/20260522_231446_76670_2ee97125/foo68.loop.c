
        /*@
        */
        
void foo68(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int l;

    i = 0;
    j = 0;
    l = 0;

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant l <= n;
          loop invariant i + j == l;
          loop assigns i, j, l;
          loop variant n - l;
            */
            while (l < n) {
       if ((l % 2) == 0) {
       i = i + 1;
      }
       else{
       j = j + 1;
      }
       l = l + 1;
      }
            

  }
