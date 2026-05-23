
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer copy_count(int* src, int* dst, integer lo, integer hi) =
    lo >= hi ? 0
             : copy_count(src, dst, lo, hi - 1) + (dst[hi - 1] == src[hi - 1] ? 1 : 0);
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
  requires 0 <= iBegin <= iEnd <= a_len;
  requires iEnd <= b_len;
  assigns a[iBegin..iEnd-1];
  ensures \forall integer j; 0 <= j < a_len ==> (j < iBegin || j >= iEnd) ==> a[j] == \old(a[j]);
*/
void foo20(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len) {

        int k = iBegin;

        
            
        /*@
          loop invariant (\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (iBegin <= k <= iEnd);
          loop invariant (\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (\forall integer j; k <= j < iEnd ==> a[j] == \at(a[j],Pre));
          loop invariant (\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (\forall integer j; 0 <= j < a_len ==> (j < iBegin || j >= iEnd) ==> a[j] == \at(a[j],Pre));
          loop invariant (!(\at(iEnd,Pre) - \at(iBegin,Pre) > 0)) ==> ((k == \at(iBegin,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))&&(iEnd == \at(iEnd,Pre))&&(iBegin == \at(iBegin,Pre))&&(b_len == \at(b_len,Pre))&&(b == \at(b,Pre)));
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant iEnd == \at(iEnd,Pre);
          loop invariant iBegin == \at(iBegin,Pre);
          loop invariant b_len == \at(b_len,Pre);
          loop invariant b == \at(b,Pre);
          loop invariant (\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (\forall integer j; 0 <= j < a_len ==> (j < iBegin || j >= k) ==> a[j] == \at(a[j],Pre));
          loop assigns a[iBegin..iEnd-1], k;
            */
            while (iEnd - k > 0) {
            a[k] = b[k];
            k = k + 1 ;
        }
            
}
