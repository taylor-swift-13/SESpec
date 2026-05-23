class SVCOMP_linear_0052__145 {
    //@ ensures mid >= 0 ==> \old(mid) + \old(mid) == 2 * \old(mid);
    static void foo145(int mid) {

        int lo;
        int hi;

        lo = 0;
        hi = 2 * mid;

 
 
 
        //@ decreases mid;
        while (mid > 0) {
            lo = lo + 1;
            hi = hi - 1;
            mid = mid - 1;
        }
    }
}