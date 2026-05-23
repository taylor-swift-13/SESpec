#include <limits.h>


/*@
  logic integer digit_prod(integer x, integer y) =
    x > y ? 1 : ((x % 10) * digit_prod(x + 1, y)) % 10;
*/

/*@requires 0 <= a <= b;
  assigns \nothing;
  ensures a == b ==> \result == 1;
  ensures (b - a) >= 5 ==> \result == 0;
  ensures 0 <= \result && \result <= 9;*/
int stub_A(int a, int b);

/*@loop invariant i > a ==> variable <= 9;
            loop invariant \forall integer k; a + 1 <= k < i ==> k >= a + 1;
            loop invariant \forall integer k; a + 1 <= k < i ==> k < b + 1;
            loop invariant variable == variable % 10;
            loop invariant variable == 1 || variable == 0 || variable <= 9;
            loop invariant variable == 1 || variable == 0 || variable < 10;
            loop invariant variable == 1 || variable < 10;
            loop invariant variable == 0 || variable == 1 || variable < 10;
            loop invariant variable == (variable % 10);
            loop invariant variable <= 9;
            loop invariant variable < 10;
            loop invariant variable % 10 == variable;
            loop invariant i > a + 1 ==> variable <= 9;
            loop invariant i == a + 1 ==> variable == 1;
            loop invariant i <= b + 1 || 1 <= variable;
            loop invariant i <= b + 1 || 1 <= i - a;
            loop invariant i <= b + 1 || 0 <= variable;
            loop invariant i <= b + 1 ==> variable == variable % 10;
            loop invariant i <= b + 1 ==> variable <= 9;
            loop invariant i <= b + 1 ==> variable < 10;
            loop invariant a + 1 <= i;
            loop invariant \forall integer k; a + 1 <= k < i ==> variable == variable % 10;
            loop invariant \forall integer k; a + 1 <= k < i ==> variable == (variable % 10);
            loop invariant \forall integer k; a + 1 <= k < i ==> variable <= 9;
            loop invariant \forall integer k; a + 1 <= k < i ==> variable < 10;
            loop invariant \forall integer k; a + 1 <= k < i ==> variable % 10 == variable;
            loop invariant \forall integer k; a + 1 <= k < i ==> k % 10 == k % 10;
            loop invariant \forall integer k; a + 1 <= k < i ==> k % 10 < 10;
            loop invariant \forall integer k; a + 1 <= k < i ==> (variable % 10) == variable;
            loop invariant \forall integer k; a + 1 <= k < i ==> (k % 10) == k % 10;
            loop invariant \forall integer k; a + 1 <= k < i ==> (k % 10) == (k % 10);
            loop invariant \forall integer k; a + 1 <= k < i ==> (k % 10) < 10;
            loop invariant 1 <= variable || i <= b + 1;
            loop invariant 1 <= variable || a + 1 <= i;
            loop invariant 1 <= variable || 1 <= i - a;
            loop invariant 1 <= i - a;
            loop invariant 0 <= variable || i <= b + 1;
            loop invariant 0 <= variable || 1 <= i - a;
            loop invariant 0 <= i - a;
            loop invariant 0 <= i - (a + 1);
            loop invariant 0 <= i - (a + 1) || i <= b + 1;
            loop invariant 0 <= i - (a + 1) || 1 <= variable;
            loop invariant 0 <= i - (a + 1) || 1 <= i - a;
            loop invariant 0 <= i - (a + 1) || 0 <= variable;
            loop invariant (i == a + 1) ==> variable == 1;
            loop assigns variable;
            loop assigns i;*/
int stub_B(int a, int b);

/*@loop invariant i > a ==> variable <= 9;
            loop invariant \forall integer k; a + 1 <= k < i ==> k >= a + 1;
            loop invariant \forall integer k; a + 1 <= k < i ==> k < b + 1;
            loop invariant variable == variable % 10;
            loop invariant variable == 1 || variable == 0 || variable <= 9;
            loop invariant variable == 1 || variable == 0 || variable < 10;
            loop invariant variable == 1 || variable < 10;
            loop invariant variable == 0 || variable == 1 || variable < 10;
            loop invariant variable == (variable % 10);
            loop invariant variable <= 9;
            loop invariant variable < 10;
            loop invariant variable % 10 == variable;
            loop invariant i > a + 1 ==> variable <= 9;
            loop invariant i == a + 1 ==> variable == 1;
            loop invariant i <= b + 1 || 1 <= variable;
            loop invariant i <= b + 1 || 1 <= i - a;
            loop invariant i <= b + 1 || 0 <= variable;
            loop invariant i <= b + 1 ==> variable == variable % 10;
            loop invariant i <= b + 1 ==> variable <= 9;
            loop invariant i <= b + 1 ==> variable < 10;
            loop invariant a + 1 <= i;
            loop invariant \forall integer k; a + 1 <= k < i ==> variable == variable % 10;
            loop invariant \forall integer k; a + 1 <= k < i ==> variable == (variable % 10);
            loop invariant \forall integer k; a + 1 <= k < i ==> variable <= 9;
            loop invariant \forall integer k; a + 1 <= k < i ==> variable < 10;
            loop invariant \forall integer k; a + 1 <= k < i ==> variable % 10 == variable;
            loop invariant \forall integer k; a + 1 <= k < i ==> k % 10 == k % 10;
            loop invariant \forall integer k; a + 1 <= k < i ==> k % 10 < 10;
            loop invariant \forall integer k; a + 1 <= k < i ==> (variable % 10) == variable;
            loop invariant \forall integer k; a + 1 <= k < i ==> (k % 10) == k % 10;
            loop invariant \forall integer k; a + 1 <= k < i ==> (k % 10) == (k % 10);
            loop invariant \forall integer k; a + 1 <= k < i ==> (k % 10) < 10;
            loop invariant 1 <= variable || i <= b + 1;
            loop invariant 1 <= variable || a + 1 <= i;
            loop invariant 1 <= variable || 1 <= i - a;
            loop invariant 1 <= i - a;
            loop invariant 0 <= variable || i <= b + 1;
            loop invariant 0 <= variable || 1 <= i - a;
            loop invariant 0 <= i - a;
            loop invariant 0 <= i - (a + 1);
            loop invariant 0 <= i - (a + 1) || i <= b + 1;
            loop invariant 0 <= i - (a + 1) || 1 <= variable;
            loop invariant 0 <= i - (a + 1) || 1 <= i - a;
            loop invariant 0 <= i - (a + 1) || 0 <= variable;
            loop invariant (i == a + 1) ==> variable == 1;
            loop assigns variable;
            loop assigns i;*/
int check_A_implies_B(int a, int b) {
    return stub_A(a, b);
}

/*@requires 0 <= a <= b;
  assigns \nothing;
  ensures a == b ==> \result == 1;
  ensures (b - a) >= 5 ==> \result == 0;
  ensures 0 <= \result && \result <= 9;*/
int check_B_implies_A(int a, int b) {
    return stub_B(a, b);
}
