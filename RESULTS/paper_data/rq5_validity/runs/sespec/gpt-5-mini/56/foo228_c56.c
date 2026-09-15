
#include <stddef.h>

int unknown();

/*@
  logic integer power(integer b, integer e) =
    e <= 0 ? 1 : b * power(b, e-1);
*/

/*@
  logic real factprod(integer n) =
    n <= 0 ? 1.0 : (1.0 / n) * factprod(n-1);
*/

/*@
  requires \true;
*/
void foo228_c56(int x) {

    unsigned int count;
    double exp;
    double term;
    double result;

    exp = 1;
    term = 1;
    count = 1;
    result = 2 * (1 / (1 - x));

    /*@
      loop invariant 0 <= (integer)count;
      loop assigns term, exp, count;
    */
    while(unknown()){
       term = term * (x / count) ;
       exp = exp + term ;
       count++ ;
    }

}
