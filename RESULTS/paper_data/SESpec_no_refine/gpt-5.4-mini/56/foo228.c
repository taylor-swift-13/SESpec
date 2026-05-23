
/*@
  logic double geom_partial(integer x, integer count) =
    count <= 0 ? 0.0 : 1.0 + (x / (count - 1)) * geom_partial(x, count - 1);
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
      loop invariant count >= 1;
      loop invariant term == 1;
      loop invariant exp == count;
      loop assigns term, exp, count;
    */
    while(unknown()){
       term = term * (x / count) ;
       exp = exp + term ;
       count++ ;
    }
}
