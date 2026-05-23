#include <limits.h>

/*@ requires (1 <= a <= 2 * radius + 1) && (1 <= b) && (radius == \at(radius, Pre)) && (diameterSquare == diameter * diameter) && (rectangles >= 0);
    assigns \nothing;
*/
void check_A_implies_B(int *a, int *b, int *diameter, int diameterSquare, int *k, int *l, int *radius, int rectangles) {
    /*@ assert (rectangles == 0 || rectangles > 0); */
    /*@ assert (diameterSquare == diameter * diameter); */
    /*@ assert (diameterSquare == 4 * radius * radius); */
    /*@ assert (diameter == 2 * radius); */
    /*@ assert (b <= 2 * radius + 1); */
    /*@ assert (a >= 1 && a <= 2 * radius); */
    /*@ assert (a <= 2 * radius); */
    /*@ assert (a <= 2 * radius + 1); */
    /*@ assert (\forall integer l; 1 <= l < b ==> rectangles >= 0); */
    /*@ assert (\forall integer l; 1 <= l < b ==> 0 <= rectangles); */
    /*@ assert (\forall integer l; 1 <= l < b ==> (a * a + l * l) > diameterSquare || rectangles >= 0); */
    /*@ assert (\forall integer l; 1 <= l < b ==> (a * a + l * l) <= diameterSquare ==> rectangles >= 0); */
    /*@ assert (\forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare) || rectangles >= 0); */
    /*@ assert (\forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare) || (a * a + l * l <= diameterSquare)); */
    /*@ assert (\forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare || rectangles >= 0)); */
    /*@ assert (\forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare || a >= 1)); */
    /*@ assert (\forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare || a > 0)); */
    /*@ assert (\forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare || a * a + l * l <= diameterSquare)); */
    /*@ assert (\forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare || (a * a + l * l <= diameterSquare && rectangles >= 0))); */
    /*@ assert (\forall integer l; 1 <= l < b ==> (a * a + l * l <= diameterSquare || rectangles >= 0)); */
    /*@ assert (\forall integer l; 1 <= l < b ==> (a * a + l * l <= diameterSquare || a >= 1)); */
    /*@ assert (\forall integer l; 1 <= l < b ==> (a * a + l * l <= diameterSquare || a > 0)); */
    /*@ assert (\forall integer l; 1 <= l < b ==> (a * a + l * l <= diameterSquare ==> rectangles >= 1)); */
    /*@ assert (\forall integer l; 1 <= l < b ==> (a * a + l * l <= diameterSquare ==> rectangles >= 0)); */
    /*@ assert (\forall integer l; 1 <= l < b ==> ((a * a + l * l) > diameterSquare || rectangles >= 0)); */
    /*@ assert (\forall integer l; 1 <= l < b ==> ((a * a + l * l) > diameterSquare || (a * a + l * l) <= diameterSquare)); */
    /*@ assert (\forall integer l; 1 <= l < b ==> ((a * a + l * l) > diameterSquare ==> rectangles >= 0)); */
    /*@ assert (\forall integer l; 1 <= l < b ==> ((a * a + l * l) <= diameterSquare ==> rectangles >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < b ==> (a * a + k * k > diameterSquare) || (rectangles >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < a ==> rectangles >= 0); */
    /*@ assert (\forall integer k; 1 <= k < a ==> diameterSquare == diameter * diameter); */
    /*@ assert (\forall integer k; 1 <= k < a ==> diameterSquare == 4 * radius * radius); */
    /*@ assert (\forall integer k; 1 <= k < a ==> diameter == 2 * radius); */
    /*@ assert (\forall integer k; 1 <= k < a ==> a <= 2 * radius + 1); */
    /*@ assert (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k*k + l*l <= diameterSquare ==> 0 <= rectangles)); */
    /*@ assert (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l > diameterSquare) || (k * k + l * l <= diameterSquare)); */
    /*@ assert (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l > diameterSquare || rectangles >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l > diameterSquare || k * k + l * l <= diameterSquare)); */
    /*@ assert (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l > diameterSquare || (k * k + l * l <= diameterSquare && rectangles >= 0))); */
    /*@ assert (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l <= diameterSquare ==> rectangles >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> ((k * k + l * l) <= diameterSquare ==> rectangles >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l < b ==> rectangles >= 0); */
    /*@ assert (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l < b ==> (k * k + l * l > diameterSquare || rectangles >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l < b ==> (k * k + l * l <= diameterSquare ==> rectangles >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l < b ==> ((k * k + l * l) <= diameterSquare ==> rectangles >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < a ==> 1 <= b <= 2 * radius + 1); */
    /*@ assert (\forall integer k; 1 <= k < a ==> 0 <= rectangles); */
    /*@ assert (\forall integer k; 1 <= k < a ==> 0 <= b); */
    /*@ assert (\forall integer k; 1 <= k < a ==> 0 <= a); */
    /*@ assert (1 <= b); */
    /*@ assert (1 <= a); */
    /*@ assert (0 <= rectangles); */
    /*@ assert (0 <= b); */
    /*@ assert (0 <= b * b); */
    /*@ assert (0 <= a); */
    /*@ assert (0 <= a * a); */
    /*@ assert (0 < a); */
}

/*@ requires (rectangles == 0 || rectangles > 0) && (diameterSquare == diameter * diameter) && (diameterSquare == 4 * radius * radius) && (diameter == 2 * radius) && (b <= 2 * radius + 1) && (a >= 1 && a <= 2 * radius) && (a <= 2 * radius) && (a <= 2 * radius + 1) && (\forall integer l; 1 <= l < b ==> rectangles >= 0) && (\forall integer l; 1 <= l < b ==> 0 <= rectangles) && (\forall integer l; 1 <= l < b ==> (a * a + l * l) > diameterSquare || rectangles >= 0) && (\forall integer l; 1 <= l < b ==> (a * a + l * l) <= diameterSquare ==> rectangles >= 0) && (\forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare) || rectangles >= 0) && (\forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare) || (a * a + l * l <= diameterSquare)) && (\forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare || rectangles >= 0)) && (\forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare || a >= 1)) && (\forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare || a > 0)) && (\forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare || a * a + l * l <= diameterSquare)) && (\forall integer l; 1 <= l < b ==> (a * a + l * l > diameterSquare || (a * a + l * l <= diameterSquare && rectangles >= 0))) && (\forall integer l; 1 <= l < b ==> (a * a + l * l <= diameterSquare || rectangles >= 0)) && (\forall integer l; 1 <= l < b ==> (a * a + l * l <= diameterSquare || a >= 1)) && (\forall integer l; 1 <= l < b ==> (a * a + l * l <= diameterSquare || a > 0)) && (\forall integer l; 1 <= l < b ==> (a * a + l * l <= diameterSquare ==> rectangles >= 1)) && (\forall integer l; 1 <= l < b ==> (a * a + l * l <= diameterSquare ==> rectangles >= 0)) && (\forall integer l; 1 <= l < b ==> ((a * a + l * l) > diameterSquare || rectangles >= 0)) && (\forall integer l; 1 <= l < b ==> ((a * a + l * l) > diameterSquare || (a * a + l * l) <= diameterSquare)) && (\forall integer l; 1 <= l < b ==> ((a * a + l * l) > diameterSquare ==> rectangles >= 0)) && (\forall integer l; 1 <= l < b ==> ((a * a + l * l) <= diameterSquare ==> rectangles >= 0)) && (\forall integer k; 1 <= k < b ==> (a * a + k * k > diameterSquare) || (rectangles >= 0)) && (\forall integer k; 1 <= k < a ==> rectangles >= 0) && (\forall integer k; 1 <= k < a ==> diameterSquare == diameter * diameter) && (\forall integer k; 1 <= k < a ==> diameterSquare == 4 * radius * radius) && (\forall integer k; 1 <= k < a ==> diameter == 2 * radius) && (\forall integer k; 1 <= k < a ==> a <= 2 * radius + 1) && (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k*k + l*l <= diameterSquare ==> 0 <= rectangles)) && (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l > diameterSquare) || (k * k + l * l <= diameterSquare)) && (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l > diameterSquare || rectangles >= 0)) && (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l > diameterSquare || k * k + l * l <= diameterSquare)) && (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l > diameterSquare || (k * k + l * l <= diameterSquare && rectangles >= 0))) && (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l <= diameterSquare ==> rectangles >= 0)) && (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> ((k * k + l * l) <= diameterSquare ==> rectangles >= 0)) && (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l < b ==> rectangles >= 0) && (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l < b ==> (k * k + l * l > diameterSquare || rectangles >= 0)) && (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l < b ==> (k * k + l * l <= diameterSquare ==> rectangles >= 0)) && (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l < b ==> ((k * k + l * l) <= diameterSquare ==> rectangles >= 0)) && (\forall integer k; 1 <= k < a ==> 1 <= b <= 2 * radius + 1) && (\forall integer k; 1 <= k < a ==> 0 <= rectangles) && (\forall integer k; 1 <= k < a ==> 0 <= b) && (\forall integer k; 1 <= k < a ==> 0 <= a) && (1 <= b) && (1 <= a) && (0 <= rectangles) && (0 <= b) && (0 <= b * b) && (0 <= a) && (0 <= a * a) && (0 < a);
    assigns \nothing;
*/
void check_B_implies_A(int *a, int *b, int *diameter, int diameterSquare, int *k, int *l, int *radius, int rectangles) {
    /*@ assert (1 <= a <= 2 * radius + 1); */
    /*@ assert (1 <= b); */
    /*@ assert (radius == \at(radius, Pre)); */
    /*@ assert (diameterSquare == diameter * diameter); */
    /*@ assert (rectangles >= 0); */
}
