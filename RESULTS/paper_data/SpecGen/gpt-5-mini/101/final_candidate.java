public class CopyArray {

    //@ requires b != null && a != null && 0 <= iBegin && iBegin <= iEnd && iEnd <= b.length && iEnd <= a.length;
    //@ ensures (\forall int k; iBegin <= k && k < iEnd; a[k] == b[k]);
    //@ ensures (\forall int k; 0 <= k && k < a.length && (k < iBegin || k >= iEnd); a[k] == \old(a[k]));
    //@ ensures (\forall int k; 0 <= k && k < b.length; b[k] == \old(b[k]));
    public static void CopyArray(int[] b, int iBegin, int iEnd, int[] a) {
        int k = iBegin;

        //@ maintaining iBegin <= k && k <= iEnd;
        //@ maintaining 0 <= iBegin && iBegin <= iEnd && iEnd <= b.length && iEnd <= a.length;
        //@ maintaining (\forall int j; iBegin <= j && j < k; a[j] == b[j]);
        //@ maintaining (\forall int j; 0 <= j && j < a.length && (j < iBegin || j >= k) ==> a[j] == \old(a[j]));
        //@ maintaining (\forall int j; 0 <= j && j < b.length; b[j] == \old(b[j]));
        //@ decreases iEnd - k;
        while (iEnd - k > 0) {
            a[k] = b[k];
            k = k + 1 ;
        }
    }
}