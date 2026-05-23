
/*@
*/

int foo148(int n) {

        if(n <= 0) {
            return 0;
        }
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant n > 0;
          loop invariant n % 2 == 0;
          loop assigns n;
            */
            while (n % 2 == 0) {
            n /= 2;
        }
            
        return n == 1;
}
