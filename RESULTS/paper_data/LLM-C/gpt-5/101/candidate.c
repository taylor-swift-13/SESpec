void CopyArray(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len);

/*@ 
  requires 0 <= iBegin && iBegin <= iEnd;
  requires 0 <= a_len && 0 <= b_len;
  requires iEnd <= a_len && iEnd <= b_len;
  requires iBegin < iEnd ==> \valid(a + (iBegin .. iEnd-1)) && \valid_read(b + (iBegin .. iEnd-1));
  requires iBegin < iEnd ==> (a == b || \separated(a + (iBegin .. iEnd-1), b + (iBegin .. iEnd-1)));
  assigns a[iBegin .. iEnd-1];
  ensures \forall integer i; iBegin <= i < iEnd ==> a[i] == b[i];
*/
void CopyArray(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len) {

        int k = iBegin;

        /*@
          loop invariant iBegin <= k <= iEnd;
          loop invariant \forall integer i; iBegin <= i < k ==> a[i] == b[i];
          loop invariant iBegin < iEnd ==> \valid(a + (iBegin .. iEnd-1)) && \valid_read(b + (iBegin .. iEnd-1));
          loop assigns a[iBegin .. iEnd-1], k;
          loop variant iEnd - k;
        */
        while (iEnd - k > 0) {
            a[k] = b[k];
            k = k + 1 ;
        }
}
