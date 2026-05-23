
/*@
  logic integer factorial(integer n) =
    n <= 1 ? 1 : n * factorial(n - 1);
*/

int foo327(int n) {

    int fact = 1;

    /*@
      loop invariant n == \at(n,Pre);
      loop assigns i, fact;
    */
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }

    int foo327 = 0;

    /*@
      loop invariant foo327 >= 0;
      loop invariant n == \at(n,Pre);
      loop invariant \forall integer k; 0 <= k < foo327 ==> (k >= 0 && k <= 9);
      loop assigns foo327, fact;
    */
    while (fact > 0) {
        foo327 = fact % 10;
        fact /= 10;
    }

    return foo327;
}
