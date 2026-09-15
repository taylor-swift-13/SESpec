
/*@ 
  logic integer prod(integer m, integer k) =
    (k <= m) ? 1 : k * prod(m, k-1);
*/

/*@
  requires \true;
  assigns \nothing;   
  ensures \result >= 0 && \result < 10;
*/
int foo156_c327(int n) {

        int fact = 1;
        
        /*@
          loop invariant n == \at(n,Pre);
          loop assigns i, fact;
        */
        for (int i = 2; i <= n; i++) {
            fact *= i;
        }
            
        int foo156_c327 = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (fact > 0) ==> (0 <= foo156_c327 && foo156_c327 < 10);
          loop invariant (!(fact > 0)) ==> (0 <= foo156_c327 && foo156_c327 < 10);
          loop assigns foo156_c327, fact;
            */
            while (fact > 0) {
            foo156_c327 = fact % 10;
            fact /= 10;
        }
            
        return foo156_c327;
}
