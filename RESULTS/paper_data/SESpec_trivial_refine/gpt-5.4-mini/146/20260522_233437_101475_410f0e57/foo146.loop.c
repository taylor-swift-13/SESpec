
        /*@
        */
        
int foo146(int n) {

        if(n <= 0) {
            return 0;
        }
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant n > 0;
          loop assigns n;
            */
            while (n % 4 == 0) {
            n /= 4;
        }
            
        return n == 1;
}
