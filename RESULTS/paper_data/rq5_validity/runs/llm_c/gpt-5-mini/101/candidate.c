/*@
    requires b != \null && a != \null;
    requires 0 <= iBegin <= iEnd <= b_len;
    requires 0 <= iBegin <= iEnd <= a_len;
    requires \valid_read(b + (0 .. b_len-1));
    requires \valid(a + (0 .. a_len-1));
    assigns a[iBegin .. iEnd-1];
    ensures \forall integer j; iBegin <= j < iEnd ==> a[j] == b[j];
    ensures \forall integer j; 0 <= j < a_len && (j < iBegin || j >= iEnd) ==> a[j] == \old(a[j]);
*/
void CopyArray(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len) {

        int k = iBegin;

        /*@
            loop invariant iBegin <= k <= iEnd;
            loop invariant \forall integer j; iBegin <= j < k ==> a[j] == b[j];
            loop assigns k, a[iBegin .. iEnd-1];
            loop variant iEnd - k;
        */
        while (iEnd - k > 0) {
            a[k] = b[k];
            k = k + 1 ;
        }
}
