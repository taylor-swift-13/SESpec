
/*@ logic integer copied_prefix(int *a, int *b, integer lb, integer ub, integer k) =
      k <= lb ? 1 :
      (a[k-1] == b[k-1] ? copied_prefix(a, b, lb, ub, k-1) : 0);
*/

/*@ 
    requires \at(b_len,Pre) > 0 && \at(b_len,Pre) < 100 && \at(a_len,Pre) > 0 && \at(a_len,Pre) < 100 ;
    assigns a[0 .. a_len-1];
*/
void foo101(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len) {

        int k = iBegin;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (k <= iEnd);
          loop invariant (\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (k >= \at(iBegin,Pre)) ;
          loop invariant (!(\at(iEnd,Pre) - \at(iBegin,Pre) > 0)) ==> ((k == \at(iBegin,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))&&(iEnd == \at(iEnd,Pre))&&(iBegin == \at(iBegin,Pre))&&(b_len == \at(b_len,Pre))&&(b == \at(b,Pre)));
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant iEnd == \at(iEnd,Pre);
          loop invariant iBegin == \at(iBegin,Pre);
          loop invariant b_len == \at(b_len,Pre);
          loop invariant b == \at(b,Pre);
          loop invariant \forall integer j; 0 <= j && j < \at(a_len,Pre) && !(\at(iBegin,Pre) <= j && j < k) ==> a[j] == \at(a[j], Pre);
          loop assigns a[0 .. \at(a_len,Pre)-1], k;
            */
            while (iEnd - k > 0) {
            a[k] = b[k];
            k = k + 1 ;
        }
            
}
