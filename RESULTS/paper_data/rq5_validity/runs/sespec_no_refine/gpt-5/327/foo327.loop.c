
/*@
  logic integer prod2(integer i) =
    i <= 2 ? 1 : (i - 1) * prod2(i - 1);
*/


int foo327(int n) {

    int fact = 1;

    /*@
      loop invariant 2 <= i;
      loop invariant n == \at(n,Pre);
      loop invariant fact == prod2(i);
      loop invariant n == \at(n,Pre);
      loop assigns i, fact;
    */
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }

    int foo327 = 0;

    /*@
      loop invariant foo327 >= 0 && foo327 <= 9;
      loop assigns foo327, fact;
    */
    while (fact > 0) {
        foo327 = fact % 10;
        fact /= 10;
    }

    return foo327;
}
