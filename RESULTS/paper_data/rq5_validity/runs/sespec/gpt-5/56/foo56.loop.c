
// Self-contained file for Frama-C

int unknown();

/*@
  logic real fact(integer n) =
    (n <= 0) ? 1.0 : ( (real)n * fact(n - 1) );
*/

/*@
  logic real rpow(real base, integer exp) =
    (exp <= 0) ? 1.0 : ( base * rpow(base, exp - 1) );
*/

/*@
  // Truncated exponential series sum_{k=0..n} x^k / k!
  logic real esum(real x, integer n) =
    (n <= 0) ? 1.0 : ( esum(x, n - 1) + rpow(x, n) / fact(n) );
*/

void foo56(int x) {

    unsigned int count;
    double exp;
    double term;
    double result;

    exp = 1;
    term = 1;
    count = 1;
    result = 2 * (1 / (1 - x));

    /*@
      loop invariant 0 <= count;
      loop invariant \true;
      loop invariant \true;
      loop invariant \true;
      loop invariant \true;
      loop invariant \true;
      loop invariant count >= 2 ==> esum(x, (integer)count - 1) == esum(x, (integer)count - 2) + rpow(x, (integer)count - 1) / fact((integer)count - 1);

      loop assigns term, exp, count;
    */
    while(unknown()){
       term = term * (x / count) ;
       exp = exp + term ;
       count++ ;
    }
}
