public class CopyArray {

    /*@ 
      @ requires a != null && b != null;
      @ requires 0 <= iBegin && iBegin <= iEnd && iEnd <= a.length && iEnd <= b.length;
      @ ensures (\forall int i; iBegin <= i && i < iEnd; a[i] == \old(b[i]));
      @ ensures (\forall int i; 0 <= i && i < a.length && (i < iBegin || i >= iEnd) ==> a[i] == \old(a[i]));
      @ ensures (\forall int i; 0 <= i && i < b.length; b[i] == \old(b[i]));
      @*/
    public static void CopyArray(int[] b, int iBegin, int iEnd, int[] a) {
        int k = iBegin;

        //@ maintaining 0 <= iBegin && iBegin <= k && k <= iEnd && iEnd <= a.length && iEnd <= b.length;
        //@ maintaining iEnd - k >= 0;
        //@ maintaining (\forall int i; iBegin <= i && i < k; a[i] == \old(b[i]));
        //@ maintaining (\forall int i; 0 <= i && i < a.length && (i < iBegin || i >= iEnd) ==> a[i] == \old(a[i]));
        //@ maintaining (\forall int i; 0 <= i && i < b.length; b[i] == \old(b[i]));
        //@ decreases iEnd - k;
        while (iEnd - k > 0) {
            a[k] = b[k];
            k = k + 1 ;
        }
    }
}