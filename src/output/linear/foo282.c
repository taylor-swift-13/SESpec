
/*@
    requires n > 0;
    */
    
void foo282(int n) {

    int i;
    int k;

    i = 0;
    k = n;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(n,Pre) && \at(n,Pre) > 0) ==> (i >= 0 && i <= \at(n,Pre)) ;
          loop invariant (0 < \at(n,Pre) && \at(n,Pre) > 0) ==> (k == \at(n,Pre) - i) ;
          loop invariant (!(0 < \at(n,Pre) && \at(n,Pre) > 0)) ==> ((k == \at(n,Pre))&&(i == 0)&&(n == \at(n,Pre)));
          loop invariant n == \at(n,Pre);
          loop assigns k, i;
            */
            while (i < n && n > 0) {
       k--;
       i++;
      }
            

    /*@ assert k == 0; */

  }
