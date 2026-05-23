
/*@
  predicate valid_read_range{L}(int *p, integer l, integer u) =
    l <= u ==> \valid_read(p + (l .. u));
*/
/*@
  predicate valid_write_range{L}(int *p, integer l, integer u) =
    l <= u ==> \valid(p + (l .. u));
*/

/*@
  predicate in_bounds(integer x, integer l, integer u) = l <= x <= u;
*/

/*@ 
  requires valid_write_range(a, iBegin, iEnd - 1);
  requires valid_read_range(b, iBegin, iEnd - 1);
  requires 0 <= iBegin <= iEnd;
  requires iEnd <= a_len;
  requires iEnd <= b_len;
  requires \separated(a + (iBegin .. iEnd - 1), b + (iBegin .. iEnd - 1));
  assigns a[iBegin..iEnd-1];
  ensures \forall integer i; iBegin <= i < iEnd ==> a[i] == \at(b[i], Pre);
  ensures \forall integer i; 0 <= i < iBegin || iEnd <= i < a_len ==> a[i] == \at(a[i], Pre);
*/
void foo101(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len) {

  int k = iBegin;

  /*@
    loop invariant iBegin <= k <= iEnd;
    loop invariant \forall integer i; iBegin <= i < k ==> a[i] == \at(b[i], Pre);
    loop invariant \forall integer i; 0 <= i < iBegin || iEnd <= i < a_len ==> a[i] == \at(a[i], Pre);
    loop assigns a[iBegin..iEnd-1], k;
    loop variant iEnd - k;
  */
  while (iEnd - k > 0) {
    a[k] = b[k];
    k = k + 1;
  }
}
