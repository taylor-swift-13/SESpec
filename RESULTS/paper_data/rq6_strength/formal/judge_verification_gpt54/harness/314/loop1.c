#include <limits.h>

/*@ requires (1 <= a) && (radius == \at(radius, Pre)) && (diameter == 2 * \at(radius, Pre)) && (diameterSquare == diameter * diameter) && (rectangles >= 0);
    assigns \nothing;
*/
void check_A_implies_B(int a, int *diameter, int diameterSquare, int *k, int *l, int *radius, int rectangles) {
    /*@ assert (\forall integer k; 1 <= k < a ==> (\forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l <= diameterSquare ==> rectangles >= 0))); */
    /*@ assert (rectangles >= 0 && a >= 1); */
    /*@ assert (rectangles == 0 || rectangles >= 0); */
    /*@ assert (rectangles <= a * (2 * radius) || 0 <= a); */
    /*@ assert (rectangles <= (a-1) * (2 * radius) || 0 <= a); */
    /*@ assert (rectangles <= (a - 1) * (2 * radius) || 0 <= a); */
    /*@ assert (diameterSquare == diameter * diameter); */
    /*@ assert (diameterSquare == 4 * radius * radius); */
    /*@ assert (diameter == 2 * radius); */
    /*@ assert (a <= 2 * radius + 1 || rectangles <= (a-1) * (2 * radius)); */
    /*@ assert (a <= 2 * radius + 1 || rectangles <= (a - 1) * (2 * radius)); */
    /*@ assert (a <= 2 * radius + 1 || 0 <= a); */
    /*@ assert (\forall integer k; 1 <= k < a ==> rectangles >= 0); */
    /*@ assert (\forall integer k; 1 <= k < a ==> diameterSquare >= 0); */
    /*@ assert (\forall integer k; 1 <= k < a ==> diameterSquare == diameter * diameter); */
    /*@ assert (\forall integer k; 1 <= k < a ==> diameterSquare == 4 * radius * radius); */
    /*@ assert (\forall integer k; 1 <= k < a ==> diameter == 2 * radius); */
    /*@ assert (\forall integer k; 1 <= k < a ==> a <= 2 * radius + 1); */
    /*@ assert (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l > diameterSquare) || (k * k + l * l <= diameterSquare)); */
    /*@ assert (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l > diameterSquare || rectangles >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l > diameterSquare || k * k + l * l <= diameterSquare)); */
    /*@ assert (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l > diameterSquare || (k * k + l * l <= diameterSquare && rectangles >= 0))); */
    /*@ assert (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l <= diameterSquare ==> rectangles >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> ((k * k + l * l) > diameterSquare || rectangles >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> ((k * k + l * l) > diameterSquare || (k * k + l * l) <= diameterSquare)); */
    /*@ assert (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> ((k * k + l * l) <= diameterSquare ==> rectangles >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < a ==> 1 <= a <= 2 * radius + 1); */
    /*@ assert (\forall integer k; 1 <= k < a ==> 0 <= rectangles); */
    /*@ assert (\forall integer k; 1 <= k < a ==> 0 <= a); */
    /*@ assert (\forall integer k; 1 <= k < a ==> (\forall integer l; 1 <= l <= 2 * radius ==> (a*a + l*l <= diameterSquare || a*a + l*l > diameterSquare))); */
    /*@ assert (1 <= a); */
    /*@ assert (1 <= a ==> 0 <= rectangles); */
    /*@ assert (0 <= rectangles); */
    /*@ assert (0 <= a); */
    /*@ assert (0 < a); */
    /*@ assert (0 < a); */
    /*@ assert (0 < a); */
    /*@ assert (0 < a); */
    /*@ assert (0 < a); */
    /*@ assert (0 < a); */
    /*@ assert (0 < a); */
    /*@ assert (0 < a); */
    /*@ assert (0 < a); */
    /*@ assert (0 < a); */
}

/*@ requires (\forall integer k; 1 <= k < a ==> (\forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l <= diameterSquare ==> rectangles >= 0))) && (rectangles >= 0 && a >= 1) && (rectangles == 0 || rectangles >= 0) && (rectangles <= a * (2 * radius) || 0 <= a) && (rectangles <= (a-1) * (2 * radius) || 0 <= a) && (rectangles <= (a - 1) * (2 * radius) || 0 <= a) && (diameterSquare == diameter * diameter) && (diameterSquare == 4 * radius * radius) && (diameter == 2 * radius) && (a <= 2 * radius + 1 || rectangles <= (a-1) * (2 * radius)) && (a <= 2 * radius + 1 || rectangles <= (a - 1) * (2 * radius)) && (a <= 2 * radius + 1 || 0 <= a) && (\forall integer k; 1 <= k < a ==> rectangles >= 0) && (\forall integer k; 1 <= k < a ==> diameterSquare >= 0) && (\forall integer k; 1 <= k < a ==> diameterSquare == diameter * diameter) && (\forall integer k; 1 <= k < a ==> diameterSquare == 4 * radius * radius) && (\forall integer k; 1 <= k < a ==> diameter == 2 * radius) && (\forall integer k; 1 <= k < a ==> a <= 2 * radius + 1) && (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l > diameterSquare) || (k * k + l * l <= diameterSquare)) && (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l > diameterSquare || rectangles >= 0)) && (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l > diameterSquare || k * k + l * l <= diameterSquare)) && (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l > diameterSquare || (k * k + l * l <= diameterSquare && rectangles >= 0))) && (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> (k * k + l * l <= diameterSquare ==> rectangles >= 0)) && (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> ((k * k + l * l) > diameterSquare || rectangles >= 0)) && (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> ((k * k + l * l) > diameterSquare || (k * k + l * l) <= diameterSquare)) && (\forall integer k; 1 <= k < a ==> \forall integer l; 1 <= l <= 2 * radius ==> ((k * k + l * l) <= diameterSquare ==> rectangles >= 0)) && (\forall integer k; 1 <= k < a ==> 1 <= a <= 2 * radius + 1) && (\forall integer k; 1 <= k < a ==> 0 <= rectangles) && (\forall integer k; 1 <= k < a ==> 0 <= a) && (\forall integer k; 1 <= k < a ==> (\forall integer l; 1 <= l <= 2 * radius ==> (a*a + l*l <= diameterSquare || a*a + l*l > diameterSquare))) && (1 <= a) && (1 <= a ==> 0 <= rectangles) && (0 <= rectangles) && (0 <= a) && (0 < a) && (0 < a) && (0 < a) && (0 < a) && (0 < a) && (0 < a) && (0 < a) && (0 < a) && (0 < a) && (0 < a);
    assigns \nothing;
*/
void check_B_implies_A(int a, int *diameter, int diameterSquare, int *k, int *l, int *radius, int rectangles) {
    /*@ assert (1 <= a); */
    /*@ assert (radius == \at(radius, Pre)); */
    /*@ assert (diameter == 2 * \at(radius, Pre)); */
    /*@ assert (diameterSquare == diameter * diameter); */
    /*@ assert (rectangles >= 0); */
}
