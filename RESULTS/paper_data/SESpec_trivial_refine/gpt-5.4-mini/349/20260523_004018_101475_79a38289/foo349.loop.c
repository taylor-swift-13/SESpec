
        /*@
        */
        
int foo349(int n) {

        int sum = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant sum >= 0;
          loop invariant i >= 1;
          loop invariant n < 1 || i <= n + 1;
          loop assigns i, sum;
            */
            for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                if (i % 2 != 0) {
                    sum += i;
                }
            }
        }
            
        return sum;
}
