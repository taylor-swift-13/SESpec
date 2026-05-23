#include <limits.h>

/*@ logic integer pow2(integer n) = (n <= 0 ? 1 : 2 * pow2(n - 1)); */

/*@ requires ((\at(b,Pre)!=0) ==> (b == \at(b,Pre))) && ((\at(b,Pre)!=0) ==> (a == \at(a,Pre))) && ((!(\at(b,Pre)!=0)) ==> ((z == 0)&&(y == \at(b,Pre))&&(x == \at(a,Pre))&&(b == \at(b,Pre))&&(a == \at(a,Pre)))) && (b == \at(b,Pre)) && (a == \at(a,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int a, int *b, int x, int *y, int z) {
    /*@ assert (z + x*y == a*b); */
    /*@ assert (z + x * y == a * b); */
    /*@ assert (y == 0 || y > 0); */
    /*@ assert (x * y + z == a * b); */
    /*@ assert (a <= x); */
    /*@ assert (0 <= z); */
    /*@ assert (0 <= y); */
    /*@ assert (0 <= x); */
}

/*@ requires (z + x*y == a*b) && (z + x * y == a * b) && (y == 0 || y > 0) && (x * y + z == a * b) && (a <= x) && (0 <= z) && (0 <= y) && (0 <= x);
    assigns \nothing;
*/
void check_B_implies_A(int a, int *b, int x, int *y, int z) {
    /*@ assert ((\at(b,Pre)!=0) ==> (b == \at(b,Pre))); */
    /*@ assert ((\at(b,Pre)!=0) ==> (a == \at(a,Pre))); */
    /*@ assert ((!(\at(b,Pre)!=0)) ==> ((z == 0)&&(y == \at(b,Pre))&&(x == \at(a,Pre))&&(b == \at(b,Pre))&&(a == \at(a,Pre)))); */
    /*@ assert (b == \at(b,Pre)); */
    /*@ assert (a == \at(a,Pre)); */
}
