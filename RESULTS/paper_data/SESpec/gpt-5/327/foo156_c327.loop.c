
/*@
  logic integer prod2(integer a, integer b) =
    a > b ? 1 : a * prod2(a + 1, b);
*/

int foo156_c327(int n) {

        int fact = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant n == \at(n,Pre);
          loop invariant 2 <= i;
          loop invariant fact >= 1;
          loop invariant fact == prod2(2, i - 1);
          loop invariant (i > n) ==> (fact == prod2(2, n));
          loop assigns i, fact;
            */
            for (int i = 2; i <= n; i++) {
            fact *= i;
        }
            
        int foo156_c327 = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant fact >= 0;
          loop invariant foo156_c327 >= 0;
          loop assigns foo156_c327, fact;
            */
            while (fact > 0) {
            foo156_c327 = fact % 10;
            fact /= 10;
        }
            
        return foo156_c327;
}
