
int foo334(int n) {

        int sum = 0;
        int sum1 = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i;
          loop invariant sum1 == 0;
          loop invariant n == \at(n,Pre);
          loop assigns i, sum;
            */
            for (int i = 1; i <= n; i++) {
            sum += i * i * i;
        }
            
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i;
          loop invariant sum1 == i * (i - 1) / 2;
          loop invariant n == \at(n,Pre);
          loop assigns i, sum1;
            */
            for (int i = 1; i <= n; i++) {
            sum1 += i;
        }
            
        return sum - sum1;
}
