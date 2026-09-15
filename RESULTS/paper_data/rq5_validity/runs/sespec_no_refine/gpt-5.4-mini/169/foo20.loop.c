
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
        */

void foo20(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len) {

        int k = iBegin;

            
        /*@
          loop invariant (\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (iBegin <= k <= iEnd);
          loop invariant (\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (\forall integer j; \at(iBegin,Pre) <= j < k ==> a[j] == b[j]);
          loop invariant (\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (\forall integer j; k <= j < iEnd ==> a[j] == \at(a[j],Pre));
          loop invariant (\at(iEnd,Pre) - \at(iBegin,Pre) <= 0) ==> (k == \at(iBegin,Pre));
          loop invariant (!(\at(iEnd,Pre) - \at(iBegin,Pre) > 0)) ==> ((k == \at(iBegin,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))&&(iEnd == \at(iEnd,Pre))&&(iBegin == \at(iBegin,Pre))&&(b_len == \at(b_len,Pre))&&(b == \at(b,Pre)));
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant iEnd == \at(iEnd,Pre);
          loop invariant iBegin == \at(iBegin,Pre);
          loop invariant b_len == \at(b_len,Pre);
          loop invariant b == \at(b,Pre);
          loop invariant \forall integer j; \at(iBegin,Pre) <= j < \at(iEnd,Pre) ==> b[j] == \at(b[j],Pre);
          loop invariant \forall integer j; \at(iBegin,Pre) <= j < iEnd ==> a[j] == \at(a[j],Pre);
          loop assigns a[..], k;
            */
            while (iEnd - k > 0) {
            a[k] = b[k];
            k = k + 1 ;
        }
            
}
