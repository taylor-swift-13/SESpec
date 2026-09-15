
        /*@
        */
        
int foo131(int * a, int a_len) {

        if (a_len == 0) return -1;
        int res = INT_MIN;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= a_len;
          loop invariant \forall integer j; 0 <= j < i ==> a[j] <= res;
          loop invariant res >= INT_MIN;
          loop assigns i, res;
            */
            for(int i = 0; i < a_len; i++) {
            res = ((a[i] > res) ? a[i] : res);
        }
            
        return res;
}
