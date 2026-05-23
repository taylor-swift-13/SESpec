#include <limits.h>

/*@logic integer digit_prod(integer x, integer y) =
    x > y ? 1 : ((x % 10) * digit_prod(x + 1, y)) % 10;*/

/*@ requires (a == \at(a,Pre)) && (b == \at(b,Pre)) && (i >= \at(a,Pre) + 1) && (i <= \at(b,Pre) + 1) && (0 <= variable && variable <= 9);
    assigns \nothing;
*/
void check_A_implies_B(int a, int b, int i, int k, int variable) {
    /*@ assert (i > a ==> variable <= 9) && (\forall integer k) && (\forall integer k) && (variable == variable % 10) && (variable == 1 || variable == 0 || variable <= 9) && (variable == 1 || variable == 0 || variable < 10) && (variable == 1 || variable < 10) && (variable == 0 || variable == 1 || variable < 10) && (variable == (variable % 10)) && (variable <= 9) && (variable < 10) && (variable % 10 == variable) && (i > a + 1 ==> variable <= 9) && (i == a + 1 ==> variable == 1) && (i <= b + 1 || 1 <= variable) && (i <= b + 1 || 1 <= i - a) && (i <= b + 1 || 0 <= variable) && (i <= b + 1 ==> variable == variable % 10) && (i <= b + 1 ==> variable <= 9) && (i <= b + 1 ==> variable < 10) && (a + 1 <= i) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (1 <= variable || i <= b + 1) && (1 <= variable || a + 1 <= i) && (1 <= variable || 1 <= i - a) && (1 <= i - a) && (0 <= variable || i <= b + 1) && (0 <= variable || 1 <= i - a) && (0 <= i - a) && (0 <= i - (a + 1)) && (0 <= i - (a + 1) || i <= b + 1) && (0 <= i - (a + 1) || 1 <= variable) && (0 <= i - (a + 1) || 1 <= i - a) && (0 <= i - (a + 1) || 0 <= variable) && ((i == a + 1) ==> variable == 1); */
}

/*@ requires (i > a ==> variable <= 9) && (\forall integer k) && (\forall integer k) && (variable == variable % 10) && (variable == 1 || variable == 0 || variable <= 9) && (variable == 1 || variable == 0 || variable < 10) && (variable == 1 || variable < 10) && (variable == 0 || variable == 1 || variable < 10) && (variable == (variable % 10)) && (variable <= 9) && (variable < 10) && (variable % 10 == variable) && (i > a + 1 ==> variable <= 9) && (i == a + 1 ==> variable == 1) && (i <= b + 1 || 1 <= variable) && (i <= b + 1 || 1 <= i - a) && (i <= b + 1 || 0 <= variable) && (i <= b + 1 ==> variable == variable % 10) && (i <= b + 1 ==> variable <= 9) && (i <= b + 1 ==> variable < 10) && (a + 1 <= i) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (1 <= variable || i <= b + 1) && (1 <= variable || a + 1 <= i) && (1 <= variable || 1 <= i - a) && (1 <= i - a) && (0 <= variable || i <= b + 1) && (0 <= variable || 1 <= i - a) && (0 <= i - a) && (0 <= i - (a + 1)) && (0 <= i - (a + 1) || i <= b + 1) && (0 <= i - (a + 1) || 1 <= variable) && (0 <= i - (a + 1) || 1 <= i - a) && (0 <= i - (a + 1) || 0 <= variable) && ((i == a + 1) ==> variable == 1);
    assigns \nothing;
*/
void check_B_implies_A(int a, int b, int i, int k, int variable) {
    /*@ assert (a == \at(a,Pre)) && (b == \at(b,Pre)) && (i >= \at(a,Pre) + 1) && (i <= \at(b,Pre) + 1) && (0 <= variable && variable <= 9); */
}
