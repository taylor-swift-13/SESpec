/*@
    requires \valid_read(b + (iBegin .. iEnd - 1));
    requires \valid(a + (iBegin .. iEnd - 1));
    requires 0 <= iBegin <= iEnd;
    requires iEnd <= b_len;
    requires iEnd <= a_len;
    assigns a[iBegin .. iEnd - 1];
    ensures \forall integer j; iBegin <= j < iEnd ==> a[j] == \old(b[j]);
*/
void CopyArray(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len);

 /*@
    requires \valid_read(b + (iBegin .. iEnd - 1));
    requires \valid(a + (iBegin .. iEnd - 1));
    requires 0 <= iBegin <= iEnd;
    requires iEnd <= b_len;
    requires iEnd <= a_len;
    assigns a[iBegin .. iEnd - 1];
    ensures \forall integer j; iBegin <= j < iEnd ==> a[j] == \old(b[j]);
*/
void CopyArray(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len) {

        int k = iBegin;
        /*@
            loop invariant iBegin <= k <= iEnd;
            loop invariant \forall integer j; iBegin <= j < k ==> a[j] == \at(b[j], Pre);
            loop assigns k, a[iBegin .. iEnd - 1];
            loop variant iEnd - k;
        */
        while (iEnd - k > 0) {
            a[k] = b[k];
            k = k + 1 ;
        }
}
