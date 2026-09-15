
/*@
  logic integer factorial(integer x) =
    x <= 1 ? 1 : x * factorial(x - 1);
*/

/*@
  requires n >= 1;
  requires n <= 4;
  assigns \nothing;
  ensures \result >= 0;
  ensures 0 <= \result && \result <= 9;
  ensures n == 1 ==> \result >= 0;
  ensures n == 2 ==> \result >= 0;
  ensures n == 3 ==> \result >= 0;
  ensures n == 4 ==> \result >= 0;
  ensures n >= 5 ==> \result >= 0;
*/
int foo327(int n) {

        int fact = 1;
        
            
        /*@
          loop invariant 2 <= i <= n + 1;
          loop invariant fact == factorial(i - 1);
          loop invariant fact >= 1;
          loop invariant (i <= n) ==> fact > 0;
          loop invariant (i > n) ==> fact == factorial(n);
          loop invariant n == \at(n,Pre);
          loop assigns i, fact;
        */
            for (int i = 2; i <= n; i++) {
            fact *= i;
        }
            
        int foo327 = 0;
        
            
        /*@
          loop invariant fact >= 0;
          loop invariant 0 <= foo327 <= 9;
          loop invariant (fact > 0) ==> 0 <= foo327 <= 9;
          loop invariant (fact == 0) ==> 0 <= foo327 <= 9;
          
          loop assigns foo327, fact;
        */
            while (fact > 0) {
            foo327 = fact % 10;
            fact /= 10;
        }
            
        return foo327;
}
