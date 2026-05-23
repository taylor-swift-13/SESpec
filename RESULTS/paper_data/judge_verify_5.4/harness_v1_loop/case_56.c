#include <limits.h>

/*@ requires (count >= 0) && (count >= 0) && (\true);
    assigns \nothing;
*/
void check_A_implies_B(int count, int term) {
    /*@ assert (term == 0 || term == term); */
}

/*@ requires (term == 0 || term == term);
    assigns \nothing;
*/
void check_B_implies_A(int count, int term) {
    /*@ assert (count >= 0) && (count >= 0) && (\true); */
}
