
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
        */

/*@
  requires \valid(&b[0] + (0..b_len-1));
  requires \forall integer i; 0 <= i < b_len ==> 0 <= b[i] <= 100;
  requires b_len > 0;
  requires b_len < 100;
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns a[iBegin..iEnd-1], k;
  ensures (iEnd - iBegin > 0) ==> (k == iEnd);
  ensures (iEnd - iBegin > 0) ==> (\forall integer j; iBegin <= j < iEnd ==> a[j] == \at(b[j],Pre));
  ensures (iEnd - iBegin <= 0) ==> (k == iBegin);
  ensures (iEnd - iBegin <= 0) ==> (\forall integer j; 0 <= j < a_len ==> a[j] == \at(a[j],Pre));
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
