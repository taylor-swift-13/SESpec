
        /*@
        */
        
int foo366(int n) {

        int sum = 0;
        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop assigns i, sum, count;
          loop invariant 1 <= i <= n + 1;
          loop invariant 0 <= count <= i / 2;
          loop invariant sum >= 0;
          loop invariant sum >= count;
            */
            for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                sum += i;
                count++;
            }
        }
            
        return sum / count;
}
