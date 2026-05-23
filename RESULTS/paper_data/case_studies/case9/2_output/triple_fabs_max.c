#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int triple_fabs_max(int a, int b, int c)

/*@

Require emp
Ensure (-c > -a && -b <= -a && c < 0 && b < 0 && a < 0 && __return == -c) || (-c > a && -b <= a && c < 0 && b < 0 && a >= 0 && __return == -c) || (-c > a && b <= a && c < 0 && b >= 0 && a >= 0 && __return == -c) || (-c > -a && b <= -a && c < 0 && b >= 0 && a < 0 && __return == -c) || (c > -a && b <= -a && c >= 0 && b >= 0 && a < 0 && __return == c) || (c > a && b <= a && c >= 0 && b >= 0 && a >= 0 && __return == c) || (c > a && -b <= a && c >= 0 && b < 0 && a >= 0 && __return == c) || (c > -a && -b <= -a && c >= 0 && b < 0 && a < 0 && __return == c) || (c > -b && -b > -a && c >= 0 && b < 0 && a < 0 && __return == c) || (c > -b && -b > a && c >= 0 && b < 0 && a >= 0 && __return == c) || (c > b && b > a && c >= 0 && b >= 0 && a >= 0 && __return == c) || (c > b && b > -a && c >= 0 && b >= 0 && a < 0 && __return == c) || (-c > b && b > -a && c < 0 && b >= 0 && a < 0 && __return == -c) || (-c > b && b > a && c < 0 && b >= 0 && a >= 0 && __return == -c) || (-c > -b && -b > a && c < 0 && b < 0 && a >= 0 && __return == -c) || (-c > -b && -b > -a && c < 0 && b < 0 && a < 0 && __return == -c) || (-c <= -b && -b > -a && c < 0 && b < 0 && a < 0 && __return == -b) || (-c <= -b && -b > a && c < 0 && b < 0 && a >= 0 && __return == -b) || (-c <= b && b > a && c < 0 && b >= 0 && a >= 0 && __return == b) || (-c <= b && b > -a && c < 0 && b >= 0 && a < 0 && __return == b) || (c <= b && b > -a && c >= 0 && b >= 0 && a < 0 && __return == b) || (c <= b && b > a && c >= 0 && b >= 0 && a >= 0 && __return == b) || (c <= -b && -b > a && c >= 0 && b < 0 && a >= 0 && __return == -b) || (c <= -b && -b > -a && c >= 0 && b < 0 && a < 0 && __return == -b) || (c <= -a && -b <= -a && c >= 0 && b < 0 && a < 0 && __return == -a) || (c <= a && -b <= a && c >= 0 && b < 0 && a >= 0 && __return == a) || (c <= a && b <= a && c >= 0 && b >= 0 && a >= 0 && __return == a) || (c <= -a && b <= -a && c >= 0 && b >= 0 && a < 0 && __return == -a) || (-c <= -a && b <= -a && c < 0 && b >= 0 && a < 0 && __return == -a) || (-c <= a && b <= a && c < 0 && b >= 0 && a >= 0 && __return == a) || (-c <= a && -b <= a && c < 0 && b < 0 && a >= 0 && __return == a) || (-c <= -a && -b <= -a && c < 0 && b < 0 && a < 0 && __return == -a)
*/
{
    int fa = a; if (fa < 0) fa = -fa;
    int fb = b; if (fb < 0) fb = -fb;
    int fc = c; if (fc < 0) fc = -fc;
    int m = fa;
    if (fb > m) m = fb;
    if (fc > m) m = fc;
    return m;
}