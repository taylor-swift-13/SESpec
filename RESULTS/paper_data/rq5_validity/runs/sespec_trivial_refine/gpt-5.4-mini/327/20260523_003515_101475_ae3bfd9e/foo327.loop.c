
        /*@
        */
        
/*@
        logic integer fact_logic(integer n) = (n <= 1) ? 1 : n * fact_logic(n - 1);
        */
        

int foo327(int n) {

        int fact = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant fact == fact_logic(i - 1);
          loop invariant i >= 2;
          loop invariant (n < 2) || i <= n + 1;
          loop assigns fact, i;
            */
            for (int i = 2; i <= n; i++) {
            fact *= i;
        }
            
        int foo327 = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant fact >= 0;
          loop invariant foo327 >= 0 && foo327 <= 9;
          loop assigns foo327, fact;
            */
            while (fact > 0) {
            foo327 = fact % 10;
            fact /= 10;
        }
            
        return foo327;
}
