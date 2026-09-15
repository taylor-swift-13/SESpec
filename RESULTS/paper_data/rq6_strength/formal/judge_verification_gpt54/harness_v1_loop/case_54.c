#include <limits.h>

/*@predicate undef_data_at(int *p) = \true;*/

/*@ requires (0 <= x <= 100);
    assigns \nothing;
*/
void check_A_implies_B(int x) {
    /*@ assert (x <= 100) && (x % 2 == 0 || x % 2 == 1) && (x % 1 == 0) && (0 <= x); */
}

/*@ requires (x <= 100) && (x % 2 == 0 || x % 2 == 1) && (x % 1 == 0) && (0 <= x);
    assigns \nothing;
*/
void check_B_implies_A(int x) {
    /*@ assert (0 <= x <= 100); */
}
