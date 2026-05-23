
int foo239(int * ar, int ar_len, int n) {

        int missing = 1;
        if (n == 0 || n == 1) {
            return missing;
        }
        
            /*@
          loop invariant i >= 1;
          loop invariant missing >= 1;
          loop invariant missing <= i;
          loop assigns i, missing;
            */
            for (int i = 1; i <= n; i++) {
            if (ar[i - 1] == i) {
                missing = i;
            } else if (ar[i - 1] != i) {
                return i;
            }
        }
            
        return missing;
}
