
/*@ 
  // Define the factorial logic function
  logic integer factorial(integer n) = 
    (n <= 1) ? 1 : n * factorial(n - 1);
*/
/*@
  requires n >= 0;
  assigns \nothing;
  ensures n > 1 ==> \result >= 1 && \result <= 9;
  ensures n >= 0 && n > 1 ==> \result == factorial(n) % 10;
*/
int foo327(int n) {

    int fact = 1;

    /*@
      loop invariant n == \at(n, Pre);
      loop invariant fact >= 1;
      loop assigns fact;
      loop variant n - i;
    */
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }

    int foo327 = 0;

    /*@
      loop invariant foo327 >= 0;
      loop invariant n == \at(n, Pre);
      loop invariant \forall integer k; 0 <= k < foo327 ==> (k >= 0 && k <= 9);
      loop assigns foo327, fact;
      loop variant fact;
    */
    while (fact > 0) {
        foo327 = fact % 10;
        fact /= 10;
    }

    return foo327;
}
