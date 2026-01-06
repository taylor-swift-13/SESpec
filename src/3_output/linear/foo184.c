
/*@
    requires n == 1 || n == 2;
    */
    
void foo184(int n) {

    int i;
    int j;
    int k;

    i = 0;
    j = 0;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= k) ==> (i >= 0 && i <= k + 1);
          loop invariant (0 <= k) ==> (j == i * n);
          loop invariant (!(0 <= k)) ==> ((j == 0)&&(i == 0)&&(n == \at(n,Pre)));
          loop invariant n == \at(n,Pre);
          loop assigns i, j;
            */
            while(i <= k){
       i = i + 1;
       j = j + n;
      }
            

    /*@ assert (i > k && n == 1) ==> (i == j); */

  }
