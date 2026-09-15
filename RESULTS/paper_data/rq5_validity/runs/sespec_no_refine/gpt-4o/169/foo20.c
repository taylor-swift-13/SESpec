
/*@
  logic integer array_copy_count(int* src, int* dest, integer lo, integer hi) =
    lo >= hi ? 0 : array_copy_count(src, dest, lo, hi - 1) + (dest[hi - 1] == src[hi - 1] ? 1 : 0);
*/

/*@
  requires \at(b_len,Pre) > 0 && \at(b_len,Pre) < 100;
  requires \at(a_len,Pre) > 0 && \at(a_len,Pre) < 100;
  requires \valid(b + (0..\at(b_len,Pre)-1));
  requires \valid(a + (0..\at(a_len,Pre)-1));
  requires iBegin >= 0 && iBegin < \at(b_len,Pre);
  requires iEnd > iBegin && iEnd <= \at(b_len,Pre);
  assigns a[iBegin..iEnd-1];
  ensures \forall integer i; i >= 0 && i < iBegin ==> a[i] == \at(a[i],Pre);
  ensures \forall integer i; i >= iEnd && i < \at(a_len,Pre) ==> a[i] == \at(a[i],Pre);
*/
void foo20(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len) {

    int k = iBegin;

    /*@
      loop invariant (\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (k >= \at(iBegin,Pre) && k <= \at(iEnd,Pre));
      loop invariant (!(\at(iEnd,Pre) - \at(iBegin,Pre) > 0)) ==> ((k == \at(iBegin,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))&&(iEnd == \at(iEnd,Pre))&&(iBegin == \at(iBegin,Pre))&&(b_len == \at(b_len,Pre))&&(b == \at(b,Pre)));
      loop invariant a_len == \at(a_len,Pre);
      loop invariant a == \at(a,Pre);
      loop invariant iEnd == \at(iEnd,Pre);
      loop invariant iBegin == \at(iBegin,Pre);
      loop invariant b_len == \at(b_len,Pre);
      loop invariant b == \at(b,Pre);
      loop invariant k >= iBegin && k <= iEnd;
      loop assigns a[iBegin..iEnd-1], k;
      loop variant iEnd - k;
    */
    while (iEnd - k > 0) {
        a[k] = b[k];
        k = k + 1;
    }
}
