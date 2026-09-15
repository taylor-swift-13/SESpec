
/*@
  logic real power(real base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

/*@
  logic real factorial(integer n) =
    n <= 1 ? 1 : n * factorial(n - 1);
*/

/*@
  logic real taylor_term(real x, integer n) =
    power(x, n) / factorial(n);
*/

/*@
  predicate taylor_series_sum(real x, integer count, real exp) =
    exp == \sum(0, count - 1, \lambda integer i; taylor_term(x, i));
*/

void foo228(int x) {

    unsigned int count;
    double exp;
    double term;
    double result;

    exp = 1;
    term = 1;
    count = 1;
    result = 2 * (1 / (1 - x));

    /*@
      loop assigns term, exp, count;
    */
    while(unknown()) {
        term = term * (x / count);
        exp = exp + term;
        count++;
    }
}
