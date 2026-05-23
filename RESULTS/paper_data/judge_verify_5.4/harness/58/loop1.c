#include <limits.h>

/*@ requires (octant1 == 0) && (term == term) && (evenExp == evenExp) && (oddExp == oddExp);
    assigns \nothing;
*/
void check_A_implies_B(int evenExp, int multFactor, int octant1, int oddExp, int term) {
    /*@ assert (term >= 0 || term < 0); */
    /*@ assert (oddExp >= 0.0 || oddExp <= 0.0); */
    /*@ assert (multFactor == 1 || multFactor == -1 || multFactor == 0); */
    /*@ assert (evenExp >= 0.0 || evenExp <= 0.0); */
    /*@ assert (evenExp == oddExp || evenExp != oddExp); */
}

/*@ requires (term >= 0 || term < 0) && (oddExp >= 0.0 || oddExp <= 0.0) && (multFactor == 1 || multFactor == -1 || multFactor == 0) && (evenExp >= 0.0 || evenExp <= 0.0) && (evenExp == oddExp || evenExp != oddExp);
    assigns \nothing;
*/
void check_B_implies_A(int evenExp, int multFactor, int octant1, int oddExp, int term) {
    /*@ assert (octant1 == 0); */
    /*@ assert (term == term); */
    /*@ assert (evenExp == evenExp); */
    /*@ assert (oddExp == oddExp); */
}
