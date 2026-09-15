
/*@
  logic real product(real x, integer count) =
    count <= 0 ? 1 : x / count * product(x, count - 1);

  logic real sum(real x, integer count) =
    count <= 0 ? 0 : sum(x, count - 1) + product(x, count);
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
      loop assigns term, exp, count;
    */
    while(unknown()){
       term = term * (x / count) ;
       exp = exp + term ;
       count++ ;
    }
}
