#include <limits.h>

/*@ logic integer undef_data_at(unsigned int *p) = 0; */

/*@ requires ((y == 1) || (y == 0)) && ((y == 0) ==> (x % 3 == 0 || x % 3 == 1 || x % 3 == 2)) && ((y == 1) ==> (x % 3 == 0 || x % 3 == 1 || x % 3 == 2));
    assigns \nothing;
*/
void check_A_implies_B(int x, int y) {
    /*@ assert (y == 1 ==> (x % 3 == 0 || x % 3 == 1 || x % 3 == 2)); */
    /*@ assert (y == 0 || y == 1); */
    /*@ assert (y == 0 ==> (x % 3 == 0 || x % 3 == 1 || x % 3 == 2)); */
    /*@ assert (x % 3 == 0 || x % 3 == 1 || x % 3 == 2); */
    /*@ assert (0 <= x); */
}

/*@ requires (y == 1 ==> (x % 3 == 0 || x % 3 == 1 || x % 3 == 2)) && (y == 0 || y == 1) && (y == 0 ==> (x % 3 == 0 || x % 3 == 1 || x % 3 == 2)) && (x % 3 == 0 || x % 3 == 1 || x % 3 == 2) && (0 <= x);
    assigns \nothing;
*/
void check_B_implies_A(int x, int y) {
    /*@ assert ((y == 1) || (y == 0)); */
    /*@ assert ((y == 0) ==> (x % 3 == 0 || x % 3 == 1 || x % 3 == 2)); */
    /*@ assert ((y == 1) ==> (x % 3 == 0 || x % 3 == 1 || x % 3 == 2)); */
}
