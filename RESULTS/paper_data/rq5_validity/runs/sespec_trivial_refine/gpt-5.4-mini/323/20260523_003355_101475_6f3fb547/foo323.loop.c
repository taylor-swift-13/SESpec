
/*@
*/

int foo323(int n) {

        int count = 0;
        if (n == 1) return 1;
        
            
        /*@
          loop invariant count >= 0;
          loop invariant i >= 2;
          loop invariant count <= i - 2;
          loop assigns count, i;
        */
            for (int i = 2; i <= n / i; i++) {
            if (n % i == 0) {
                count++;
                if (n / i == i) {
                    break;
                }
            }
        }
            
        return count;
}
