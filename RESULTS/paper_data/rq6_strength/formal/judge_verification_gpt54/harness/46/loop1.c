#include <limits.h>

/*@ logic integer abs_int(integer x) = x < 0 ? -x : x; */

/*@ requires (t >= 0) && (x1 == 100 + t * v1) && (x3 == -50 + t * v3) && (v1 == \at(v1,Pre)) && (v3 == \at(v3,Pre)) && (\true) && (75 - 5 * t <= x2 <= 75 + 5 * t) && (x2 >= 75 - 5 * t) && (x2 <= 75 + 5 * t) && (t == 0 ==> x1 == 100 && x2 == 75 && x3 == -50) && ((\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5) ==> (t <= \at(v2,Pre) + 5 || t >= 0)) && (\true) && ((!(\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5)) ==> ((t == 0)&&(x3 == -50)&&(x2 == 75)&&(x1 == 100)&&(v3 == \at(v3,Pre))&&(v2 == \at(v2,Pre))&&(v1 == \at(v1,Pre)))) && (v3 == \at(v3,Pre)) && (v1 == \at(v1,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *t, int *v1, int v2, int *v3, int x1, int x2, int x3) {
    /*@ assert (x3 == -50 + t * v3); */
    /*@ assert (x1 == 100 + t * v1); */
    /*@ assert (0 <= t); */
}

/*@ requires (x3 == -50 + t * v3) && (x1 == 100 + t * v1) && (0 <= t);
    assigns \nothing;
*/
void check_B_implies_A(int *t, int *v1, int v2, int *v3, int x1, int x2, int x3) {
    /*@ assert (t >= 0); */
    /*@ assert (x1 == 100 + t * v1); */
    /*@ assert (x3 == -50 + t * v3); */
    /*@ assert (v1 == \at(v1,Pre)); */
    /*@ assert (v3 == \at(v3,Pre)); */
    /*@ assert (\true); */
    /*@ assert (75 - 5 * t <= x2 <= 75 + 5 * t); */
    /*@ assert (x2 >= 75 - 5 * t); */
    /*@ assert (x2 <= 75 + 5 * t); */
    /*@ assert (t == 0 ==> x1 == 100 && x2 == 75 && x3 == -50); */
    /*@ assert ((\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5) ==> (t <= \at(v2,Pre) + 5 || t >= 0)); */
    /*@ assert (\true); */
    /*@ assert ((!(\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5)) ==> ((t == 0)&&(x3 == -50)&&(x2 == 75)&&(x1 == 100)&&(v3 == \at(v3,Pre))&&(v2 == \at(v2,Pre))&&(v1 == \at(v1,Pre)))); */
    /*@ assert (v3 == \at(v3,Pre)); */
    /*@ assert (v1 == \at(v1,Pre)); */
}
