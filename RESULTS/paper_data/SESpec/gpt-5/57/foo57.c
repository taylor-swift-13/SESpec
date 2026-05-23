
/*@
  logic real rpow(real base, integer exp) =
    exp <= 0 ? 1.0 : base * rpow(base, exp - 1);
*/

/*@
  logic real factr(integer n) =
    n <= 1 ? 1.0 : ((real)n) * factr(n - 1);
*/

/*@
  logic real partial_even(integer m, real x) =
    m < 0 ? 0.0
          : partial_even(m - 1, x)
            + ((m % 2 == 0) ? 1.0 : -1.0) * rpow(x, 2 * m) / factr(2 * m);
*/

/*@
  logic real partial_odd(integer m, real x) =
    m < 0 ? 0.0
          : partial_odd(m - 1, x)
            + ((m % 2 == 0) ? 1.0 : -1.0) * rpow(x, 2 * m + 1) / factr(2 * m + 1);
*/

/*@
  requires \true;
*/
void foo57(int octant, int x) {

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
      loop invariant 0 <= count;
      loop invariant 0 <= count;
      loop invariant evenExp == evenExp;
      loop invariant oddExp == oddExp;
      loop invariant term == term;
      loop invariant 0 <= count;
      loop invariant -1 <= multFactor;
      loop invariant multFactor <= 1;
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
