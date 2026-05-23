/*@ 
    requires \valid(b + (0 .. b_len-1));
    requires \valid(a + (0 .. a_len-1));
    requires 0 <= iBegin <= iEnd <= b_len;
    requires iEnd <= a_len;
    assigns a[iBegin .. iEnd-1];
    ensures \forall integer i; iBegin <= i < iEnd ==> a[i] == b[i];
*/
void CopyArray(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len);

void CopyArray(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len) {

        int k = iBegin;

        /*@
            loop invariant iBegin <= k <= iEnd;
            loop invariant \forall integer i; iBegin <= i < k ==> a[i] == b[i];
            loop assigns k, a[iBegin .. iEnd-1];
            loop variant iEnd - k;
        */
        while (iEnd - k > 0) {
            a[k] = b[k];
            k = k + 1 ;
        }
}
