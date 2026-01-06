
/*@
    requires n > 0 && k > n;
    */
    
void foo159(int k, int n) {

    int j;

    j = 0;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(n,Pre)) ==> (k == \at(k,Pre) - j);
          loop invariant (0 < \at(n,Pre)) ==> (0 <= j <= \at(n,Pre));
          loop invariant (!(0 < \at(n,Pre))) ==> ((j == 0)&&(n == \at(n,Pre))&&(k == \at(k,Pre)));
          loop invariant n == \at(n,Pre);
          loop assigns j, k;
            */
            while(j < n){
       j = j + 1;
       k = k - 1;
      }
            

    /*@ assert (j >= n) ==> (k >= 0); */

  }
