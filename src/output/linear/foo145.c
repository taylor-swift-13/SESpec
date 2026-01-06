
/*@
    requires mid > 0;
    */
    
void foo145(int mid) {

    int lo;
    int hi;

    lo = 0;
    hi = 2 * mid;


    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (\at(mid,Pre) > 0) ==> (mid == \at(mid,Pre) - lo) ;
          loop invariant (\at(mid,Pre) > 0) ==> (hi == 2 * \at(mid,Pre) - lo) ;
          loop invariant (\at(mid,Pre) > 0) ==> (lo <= \at(mid,Pre)) ;
          loop invariant (!(\at(mid,Pre) > 0)) ==> ((hi == 2 * \at(mid,Pre))&&(lo == 0)&&(mid == \at(mid,Pre)));
          loop assigns lo, hi, mid;
            */
            while(mid > 0){
       lo = lo + 1;
       hi = hi - 1;
       mid = mid - 1;
      }
            

    /*@ assert lo == hi; */

  }
