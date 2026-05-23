
/*@
  // Define factorial as a pure logic function so loop invariants can refer to it.
  logic integer fact_of(integer m) =
    m <= 1 ? 1 : m * fact_of(m - 1);
*/

/*@
  requires \true;
*/
int foo327(int n) {

    int fact = 1;

    /*@ 
      loop invariant 2 <= i <= \at(n,Pre) + 1 || (i == 2 && \at(n,Pre) < 2);
      loop invariant fact >= 1;
      loop invariant fact == fact_of(i - 1);
      loop invariant (i == \at(n,Pre) + 1) ==> (fact == fact_of(\at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns i, fact;
    */
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }

    int foo327 = 0;

    /*@
      loop invariant 0 <= foo327 && foo327 <= 9;
      loop invariant fact >= 0;
      loop invariant fact > 0 ==> (0 <= fact % 10 && fact % 10 <= 9);
      loop invariant (fact == 0) ==> (0 <= foo327 && foo327 <= 9);
      loop assigns foo327, fact;
    */
    while (fact > 0) {
        foo327 = fact % 10;
        fact /= 10;
    }

    return foo327;
}
