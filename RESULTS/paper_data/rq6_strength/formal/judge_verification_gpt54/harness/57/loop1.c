#include <limits.h>

/*@ requires (count >= 0) && (count % 2 == 0 || count % 2 == 1) && (multFactor == 0 || multFactor == 1 || multFactor == -1) && (term == term) && (evenExp == evenExp) && (oddExp == oddExp) && ((count / 2) % 2 == 0 || (count / 2) % 2 == 1) && (evenExp >= 0.0 || evenExp <= 0.0) && (oddExp >= 0.0 || oddExp <= 0.0);
    assigns \nothing;
*/
void check_A_implies_B(int count, int evenExp, int multFactor, int octant, int oddExp, int term, int x) {
    /*@ assert (term >= 0 || term <= 0); */
    /*@ assert (term == x || term == 0 || term >= 0 || term <= 0); */
    /*@ assert (oddExp == x || oddExp >= x || oddExp <= x); */
    /*@ assert (octant == 1); */
    /*@ assert (multFactor == 1 || multFactor == -1 || multFactor == 0); */
    /*@ assert (multFactor == 0 || multFactor == 1 || multFactor == -1); */
    /*@ assert (multFactor == -1 || multFactor == 1 || multFactor == 0); */
    /*@ assert (evenExp == oddExp || evenExp != oddExp); */
    /*@ assert (evenExp == 1.0 || evenExp >= 1.0 || evenExp <= 1.0); */
}

/*@ requires (term >= 0 || term <= 0) && (term == x || term == 0 || term >= 0 || term <= 0) && (oddExp == x || oddExp >= x || oddExp <= x) && (octant == 1) && (multFactor == 1 || multFactor == -1 || multFactor == 0) && (multFactor == 0 || multFactor == 1 || multFactor == -1) && (multFactor == -1 || multFactor == 1 || multFactor == 0) && (evenExp == oddExp || evenExp != oddExp) && (evenExp == 1.0 || evenExp >= 1.0 || evenExp <= 1.0);
    assigns \nothing;
*/
void check_B_implies_A(int count, int evenExp, int multFactor, int octant, int oddExp, int term, int x) {
    /*@ assert (count >= 0); */
    /*@ assert (count % 2 == 0 || count % 2 == 1); */
    /*@ assert (multFactor == 0 || multFactor == 1 || multFactor == -1); */
    /*@ assert (term == term); */
    /*@ assert (evenExp == evenExp); */
    /*@ assert (oddExp == oddExp); */
    /*@ assert ((count / 2) % 2 == 0 || (count / 2) % 2 == 1); */
    /*@ assert (evenExp >= 0.0 || evenExp <= 0.0); */
    /*@ assert (oddExp >= 0.0 || oddExp <= 0.0); */
}
