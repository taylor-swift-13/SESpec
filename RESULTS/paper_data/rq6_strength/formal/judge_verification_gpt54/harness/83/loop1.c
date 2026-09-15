#include <limits.h>

/*@ logic integer power(integer b, integer e) =
    e <= 0 ? 1 : b * power(b, e - 1); */
/*@ logic integer geom_sum(integer b, integer e) =
    e <= 0 ? 1 : geom_sum(b, e - 1) * b + 1; */

/*@ requires (1 <= c <= k) && (y == power(z, c - 1)) && (c >= 1) && (c <= k) && (a == \at(a,Pre)) && (k == \at(k,Pre)) && (z == \at(z,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *a, int c, int k, int x, int *y, int z) {
    /*@ assert (y == z * y || y == 1); */
    /*@ assert (y == 0 || y == 1 || y == z * y); */
    /*@ assert (y == (z == 1 ? 1 : y)); */
    /*@ assert (x >= a || x <= a); */
    /*@ assert (x == a + y * a); */
    /*@ assert (x == a + (c-1)*a); */
    /*@ assert (x == a * y); */
    /*@ assert (c <= k); */
    /*@ assert (c - 1 <= k); */
    /*@ assert (1 <= c); */
    /*@ assert (0 <= c - 1); */
}

/*@ requires (y == z * y || y == 1) && (y == 0 || y == 1 || y == z * y) && (y == (z == 1 ? 1 : y)) && (x >= a || x <= a) && (x == a + y * a) && (x == a + (c-1)*a) && (x == a * y) && (c <= k) && (c - 1 <= k) && (1 <= c) && (0 <= c - 1);
    assigns \nothing;
*/
void check_B_implies_A(int *a, int c, int k, int x, int *y, int z) {
    /*@ assert (1 <= c <= k); */
    /*@ assert (y == power(z, c - 1)); */
    /*@ assert (c >= 1); */
    /*@ assert (c <= k); */
    /*@ assert (a == \at(a,Pre)); */
    /*@ assert (k == \at(k,Pre)); */
    /*@ assert (z == \at(z,Pre)); */
}
