#include <limits.h>

/*@ logic integer digit_prod(integer x, integer y) =
    x > y ? 1 : ((x % 10) * digit_prod(x + 1, y)) % 10; */

/*@ requires (a == \at(a,Pre)) && (b == \at(b,Pre)) && (i >= \at(a,Pre) + 1) && (i <= \at(b,Pre) + 1) && (0 <= variable && variable <= 9);
    assigns \nothing;
*/
void check_A_implies_B(int a, int b, int i, int k, int variable) {
    /*@ assert (i > a ==> variable <= 9); */
    /*@ assert (\forall integer k; a + 1 <= k < i ==> k >= a + 1); */
    /*@ assert (\forall integer k; a + 1 <= k < i ==> k < b + 1); */
    /*@ assert (variable == variable % 10); */
    /*@ assert (variable == 1 || variable == 0 || variable <= 9); */
    /*@ assert (variable == 1 || variable == 0 || variable < 10); */
    /*@ assert (variable == 1 || variable < 10); */
    /*@ assert (variable == 0 || variable == 1 || variable < 10); */
    /*@ assert (variable == (variable % 10)); */
    /*@ assert (variable <= 9); */
    /*@ assert (variable < 10); */
    /*@ assert (variable % 10 == variable); */
    /*@ assert (i > a + 1 ==> variable <= 9); */
    /*@ assert (i == a + 1 ==> variable == 1); */
    /*@ assert (i <= b + 1 || 1 <= variable); */
    /*@ assert (i <= b + 1 || 1 <= i - a); */
    /*@ assert (i <= b + 1 || 0 <= variable); */
    /*@ assert (i <= b + 1 ==> variable == variable % 10); */
    /*@ assert (i <= b + 1 ==> variable <= 9); */
    /*@ assert (i <= b + 1 ==> variable < 10); */
    /*@ assert (a + 1 <= i); */
    /*@ assert (\forall integer k; a + 1 <= k < i ==> variable == variable % 10); */
    /*@ assert (\forall integer k; a + 1 <= k < i ==> variable == (variable % 10)); */
    /*@ assert (\forall integer k; a + 1 <= k < i ==> variable <= 9); */
    /*@ assert (\forall integer k; a + 1 <= k < i ==> variable < 10); */
    /*@ assert (\forall integer k; a + 1 <= k < i ==> variable % 10 == variable); */
    /*@ assert (\forall integer k; a + 1 <= k < i ==> k % 10 == k % 10); */
    /*@ assert (\forall integer k; a + 1 <= k < i ==> k % 10 < 10); */
    /*@ assert (\forall integer k; a + 1 <= k < i ==> (variable % 10) == variable); */
    /*@ assert (\forall integer k; a + 1 <= k < i ==> (k % 10) == k % 10); */
    /*@ assert (\forall integer k; a + 1 <= k < i ==> (k % 10) == (k % 10)); */
    /*@ assert (\forall integer k; a + 1 <= k < i ==> (k % 10) < 10); */
    /*@ assert (1 <= variable || i <= b + 1); */
    /*@ assert (1 <= variable || a + 1 <= i); */
    /*@ assert (1 <= variable || 1 <= i - a); */
    /*@ assert (1 <= i - a); */
    /*@ assert (0 <= variable || i <= b + 1); */
    /*@ assert (0 <= variable || 1 <= i - a); */
    /*@ assert (0 <= i - a); */
    /*@ assert (0 <= i - (a + 1)); */
    /*@ assert (0 <= i - (a + 1) || i <= b + 1); */
    /*@ assert (0 <= i - (a + 1) || 1 <= variable); */
    /*@ assert (0 <= i - (a + 1) || 1 <= i - a); */
    /*@ assert (0 <= i - (a + 1) || 0 <= variable); */
    /*@ assert ((i == a + 1) ==> variable == 1); */
}

/*@ requires (i > a ==> variable <= 9) && (\forall integer k; a + 1 <= k < i ==> k >= a + 1) && (\forall integer k; a + 1 <= k < i ==> k < b + 1) && (variable == variable % 10) && (variable == 1 || variable == 0 || variable <= 9) && (variable == 1 || variable == 0 || variable < 10) && (variable == 1 || variable < 10) && (variable == 0 || variable == 1 || variable < 10) && (variable == (variable % 10)) && (variable <= 9) && (variable < 10) && (variable % 10 == variable) && (i > a + 1 ==> variable <= 9) && (i == a + 1 ==> variable == 1) && (i <= b + 1 || 1 <= variable) && (i <= b + 1 || 1 <= i - a) && (i <= b + 1 || 0 <= variable) && (i <= b + 1 ==> variable == variable % 10) && (i <= b + 1 ==> variable <= 9) && (i <= b + 1 ==> variable < 10) && (a + 1 <= i) && (\forall integer k; a + 1 <= k < i ==> variable == variable % 10) && (\forall integer k; a + 1 <= k < i ==> variable == (variable % 10)) && (\forall integer k; a + 1 <= k < i ==> variable <= 9) && (\forall integer k; a + 1 <= k < i ==> variable < 10) && (\forall integer k; a + 1 <= k < i ==> variable % 10 == variable) && (\forall integer k; a + 1 <= k < i ==> k % 10 == k % 10) && (\forall integer k; a + 1 <= k < i ==> k % 10 < 10) && (\forall integer k; a + 1 <= k < i ==> (variable % 10) == variable) && (\forall integer k; a + 1 <= k < i ==> (k % 10) == k % 10) && (\forall integer k; a + 1 <= k < i ==> (k % 10) == (k % 10)) && (\forall integer k; a + 1 <= k < i ==> (k % 10) < 10) && (1 <= variable || i <= b + 1) && (1 <= variable || a + 1 <= i) && (1 <= variable || 1 <= i - a) && (1 <= i - a) && (0 <= variable || i <= b + 1) && (0 <= variable || 1 <= i - a) && (0 <= i - a) && (0 <= i - (a + 1)) && (0 <= i - (a + 1) || i <= b + 1) && (0 <= i - (a + 1) || 1 <= variable) && (0 <= i - (a + 1) || 1 <= i - a) && (0 <= i - (a + 1) || 0 <= variable) && ((i == a + 1) ==> variable == 1);
    assigns \nothing;
*/
void check_B_implies_A(int a, int b, int i, int k, int variable) {
    /*@ assert (a == \at(a,Pre)); */
    /*@ assert (b == \at(b,Pre)); */
    /*@ assert (i >= \at(a,Pre) + 1); */
    /*@ assert (i <= \at(b,Pre) + 1); */
    /*@ assert (0 <= variable && variable <= 9); */
}
