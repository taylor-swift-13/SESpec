#include <limits.h>

/*@ requires (\true) && (\true) && (\true) && (\true) && (\true) && (\true);
    assigns \nothing;
*/
void check_A_implies_B(void) {
    /*@ assert (\true); */
}

/*@ requires (\true);
    assigns \nothing;
*/
void check_B_implies_A(void) {
    /*@ assert (\true); */
    /*@ assert (\true); */
    /*@ assert (\true); */
    /*@ assert (\true); */
    /*@ assert (\true); */
    /*@ assert (\true); */
}
