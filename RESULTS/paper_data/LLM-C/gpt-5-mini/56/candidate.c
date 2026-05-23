int unknown();

/*@
    requires x != 1;
    assigns \nothing;
    ensures \true;
*/
void foo240(int x) {

    unsigned int count;
    double exp;
    double term;
    double result;

    exp = 1;
    term = 1;
    count = 1;
    result = 2 * (1 / (1 - x));

    /*@
        loop invariant count >= 1;
        loop invariant result == 2 * (1 / (1 - x));
        loop assigns count, term, exp;
    */
    while(unknown()){
       term = term * (x / count) ;
       exp = exp + term ;
       count++ ;
      }

  }
