
/*@
predicate is_power_of_two(integer x) = x > 0 && (x & (x - 1)) == 0;
*/

int foo148(int n) {

        if(n <= 0) {
            return 0;
        }
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant n > 0;
          loop assigns n;
            */
            while (n % 2 == 0) {
            n /= 2;
        }
            
        return n == 1;
}
