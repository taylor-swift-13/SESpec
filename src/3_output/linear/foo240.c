
/*@
    requires x > -1 && x < 1;
*/
void foo240(int x) {
    unsigned int count;
    double exp, term, result;

    exp = 1;
    term = 1;
    count = 1;
    result = 2 * (1 / (1 - x));

    /*@
      loop assigns exp, term, count;
    */
    while(unknown()) {
       term = term * (x / count);
       exp = exp + term;
       count++;
    }

    /*@ assert result >= exp; */
}
