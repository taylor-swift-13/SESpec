
/*@
  logic integer copied_count(int *b, int *a, integer lo, integer hi) =
    lo >= hi ? 0
              : copied_count(b, a, lo, hi - 1) + (a[hi - 1] == b[hi - 1] ? 1 : 0);
*/

/*@ 
        logic integer PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
void foo20(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len) {

        int k = iBegin;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (k >= \at(iBegin,Pre) && k <= \at(iEnd,Pre) && copied_count(b, a, \at(iBegin,Pre), k) == k - \at(iBegin,Pre)) ;
          loop invariant (!(\at(iEnd,Pre) - \at(iBegin,Pre) > 0)) ==> ((k == \at(iBegin,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))&&(iEnd == \at(iEnd,Pre))&&(iBegin == \at(iBegin,Pre))&&(b_len == \at(b_len,Pre))&&(b == \at(b,Pre)));
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant iEnd == \at(iEnd,Pre);
          loop invariant iBegin == \at(iBegin,Pre);
          loop invariant b_len == \at(b_len,Pre);
          loop invariant b == \at(b,Pre);
          loop invariant \forall integer t; \at(iBegin,Pre) <= t < k ==> a[t] == b[t];
          loop invariant \forall integer t; k <= t < \at(iEnd,Pre) ==> a[t] == \at(a[t], Pre);
          loop assigns a[..], k;
            */
            while (iEnd - k > 0) {
            a[k] = b[k];
            k = k + 1 ;
        }
            
}
