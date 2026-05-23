class Sespec0132 {
    //@ requires a != null;
    //@ ensures a.length == 0 ==> \result == -1;
    //@ ensures a.length > 0 ==> \result == Integer.MIN_VALUE;
    //@ ensures a.length > 0 ==> (\forall int k; 0 <= k && k < a.length; \result <= a[k]);
    /*@ spec_public @*/ static int foo132(int[] a) {
        if (a.length == 0) return -1;
        int res = Integer.MIN_VALUE;
        //@ maintaining 0 <= i && i <= a.length;
        //@ maintaining (\forall int k; 0 <= k && k < i; res <= a[k]);
        //@ decreases a.length - i;
        for (int i = 0; i < a.length; i++) {
            res = ((a[i] < res) ? a[i] : res);
        }
        return res;
    }
}