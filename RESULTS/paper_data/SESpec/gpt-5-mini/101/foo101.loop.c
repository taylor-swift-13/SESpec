


/*@
  requires \valid(b + (0 .. b_len-1));
  requires \valid(a + (0 .. a_len-1));
  requires 0 <= iBegin <= iEnd <= b_len;
  requires 0 <= iBegin <= iEnd <= a_len;
  assigns a[0..a_len-1];
  ensures \forall integer p; 0 <= p < a_len ==> a[p] == \at(a[p],Pre) || (iBegin <= p && p < iEnd && a[p] == b[p]);
  ensures \forall integer p; iBegin <= p < iEnd ==> a[p] == b[p];
*/
void foo101(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len) {

    int k = iBegin;

    /*@
      loop invariant 0 <= iBegin == \at(iBegin,Pre);
      loop invariant 0 <= iEnd == \at(iEnd,Pre);
      loop invariant 0 <= a_len == \at(a_len,Pre);
      loop invariant 0 <= b_len == \at(b_len,Pre);

      loop invariant 0 <= k <= iEnd;
      loop invariant 0 <= iBegin <= k <= a_len;

      loop invariant \forall integer p; 0 <= p < a_len && !(iBegin <= p && p < k) ==> a[p] == \at(a[p],Pre);

      loop invariant a_len == \at(a_len,Pre);
      loop invariant b_len == \at(b_len,Pre);
      loop invariant iBegin == \at(iBegin,Pre);
      loop invariant iEnd == \at(iEnd,Pre);
      loop invariant b == \at(b,Pre);

      loop assigns a[0..a_len-1], k;
    */
    while (iEnd - k > 0) {
        a[k] = b[k];
        k = k + 1 ;
    }

}
