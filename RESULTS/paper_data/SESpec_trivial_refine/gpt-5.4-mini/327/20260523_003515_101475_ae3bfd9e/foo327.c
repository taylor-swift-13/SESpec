
        /*@
        */
        
/*@
  assigns \nothing;
  ensures \result == fact_logic(n) % 10;
  ensures 0 <= \result <= 9;
  ensures n <= 1 ==> \result == 1;
  ensures 2 <= n && n <= 4 ==> \result == fact_logic(n);
  ensures n >= 5 ==> \result == 0;
*/
int foo327(int n) {

        int fact = 1;
        
            
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
