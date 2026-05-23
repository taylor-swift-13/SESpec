public class CopyArray {
    //@ requires b != null && a != null;
    //@ requires 0 <= iBegin && iBegin <= iEnd;
    //@ requires iEnd <= b.length && iEnd <= a.length;
 
 
 
    public static void CopyArray(int[] b, int iBegin, int iEnd, int[] a) {
        int k = iBegin;
        //@ maintaining iBegin <= k && k <= iEnd;
        //@ maintaining (\forall int t; iBegin <= t && t < k; a[t] == b[t]);
        //@ decreases iEnd - k;
        while (iEnd - k > 0) {
            a[k] = b[k];
            k = k + 1 ;
        }
    }
}
