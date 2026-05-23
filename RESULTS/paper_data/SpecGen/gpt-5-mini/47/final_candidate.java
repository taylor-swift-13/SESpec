class SVCOMP_linear_0052__145 {
    static void foo145(int mid) {
        int lo;
        int hi;
 
 
    
        lo = 0;
        hi = 2 * mid;
 
        //@ maintaining hi - mid == \old(mid);
        //@ maintaining lo + hi == 2 * \old(mid);  
        //@ maintaining lo >= 0;
        //@ decreases mid;
        while(mid > 0){
            lo = lo + 1;
            hi = hi - 1;
            mid = mid - 1;
        }
    
    }
}
