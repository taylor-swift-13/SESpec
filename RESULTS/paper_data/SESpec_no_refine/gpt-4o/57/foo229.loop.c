
/*@
  logic double power(double base, integer exp) =
    exp <= 0 ? 1.0 : base * power(base, exp - 1);
*/

/*@
  logic double factorial(integer n) =
    n <= 1 ? 1.0 : n * factorial(n - 1);
*/

/*@
  logic double term_value(double x, integer count) =
    power(x, count) / factorial(count);
*/

/*@
  logic double alternating_sum(double x, integer count, integer parity) =
    count <= 0 ? 0.0 : 
    (parity == 0 ? 1.0 : -1.0) * term_value(x, count) + alternating_sum(x, count - 2, 1 - parity);
*/

void foo229(int octant, int x) {

    unsigned int count;
    int multFactor;
    int temp;
    double oddExp;
    double evenExp;
    double term;

    octant = 3.14159 / 3;
    oddExp = x;
    evenExp = 1.0;
    term = x;
    count = 2;
    multFactor = 0;

    /*@
      loop invariant count >= 2;
      loop invariant term == term_value(x, count - 1);
      loop invariant evenExp == alternating_sum(x, count - 2, 0);
      loop invariant oddExp == alternating_sum(x, count - 1, 1);
      loop assigns term, multFactor, evenExp, count, oddExp;
    */
    while(unknown()){
       term = term * (x / count);

       if((count / 2) % 2 == 0)
       multFactor = 1;
       else
       multFactor = -1;

       evenExp = evenExp + multFactor * term;

       count = count + 1;

       term = term * (x / count);

       oddExp = oddExp + multFactor * term;

       count = count + 1;
    }
}
