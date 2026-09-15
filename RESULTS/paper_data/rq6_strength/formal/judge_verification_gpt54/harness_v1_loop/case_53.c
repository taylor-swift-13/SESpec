#include <limits.h>
#include <stddef.h>

/*@predicate undef_data_at{L}(int *p) = \true;*/

/*@ requires (x % 5 == 0) && (x <= 105);
    assigns \nothing;
*/
void check_A_implies_B(int x) {
    /*@ assert (x % 5 == 0); */
}

/*@ requires (x % 5 == 0);
    assigns \nothing;
*/
void check_B_implies_A(int x) {
    /*@ assert (x % 5 == 0) && (x <= 105); */
}
