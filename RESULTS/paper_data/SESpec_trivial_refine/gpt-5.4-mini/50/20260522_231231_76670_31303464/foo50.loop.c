
        /*@
        */
        
void foo50(int i, int j, int k) {

    int n;
    int b;

    n = 0;
    b = 0;

    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= n;
          loop invariant k < 0 || n <= 2 * k;
          loop invariant b == (n % 2);
          loop assigns n, b, i, j;
            */
            while(n < (2 * k)){
       n = n + 1;
       if(b == 1){
       b = 0;
       i = i + 1;
      }
       else{
       b = 1;
       j = j + 1;
      }
      }
            

  }
