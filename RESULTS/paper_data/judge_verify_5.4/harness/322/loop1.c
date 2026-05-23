#include <limits.h>

/*@ requires (1 <= i) && ((i <= x + 1) || (x < 0)) && (gcd >= 1) && (gcd <= i) && (foo322 == 1) && (gcd == 1 || (x % gcd == 0 && y % gcd == 0)) && (\forall integer k; 1 <= k < i && x % k == 0 && y % k == 0 ==> k <= gcd) && (gcd == 1 || (\exists integer k; 1 <= k < i && x % k == 0 && y % k == 0 && gcd == k));
    assigns \nothing;
*/
void check_A_implies_B(int foo322, int gcd, int i, int k, int x, int y) {
    /*@ assert (\forall integer k; 1 <= k < i ==> (!(x % k == 0 && y % k == 0) || k <= gcd)); */
    /*@ assert (y > 0 ==> gcd <= y); */
    /*@ assert (y % gcd == 0); */
    /*@ assert (y % gcd == 0 || gcd == 1); */
    /*@ assert (x > 0 ==> y > 0); */
    /*@ assert (x > 0 ==> gcd >= 1); */
    /*@ assert (x > 0 ==> gcd <= x); */
    /*@ assert (x <= y); */
    /*@ assert (x <= y || y <= x); */
    /*@ assert (x % gcd == 0); */
    /*@ assert (x % gcd == 0 || y % gcd == 0); */
    /*@ assert (x % gcd == 0 || gcd == 1); */
    /*@ assert (x % gcd == 0 && y % gcd == 0); */
    /*@ assert (i <= x + 1 || 0 < gcd); */
    /*@ assert (gcd == 1 || y % gcd == 0); */
    /*@ assert (gcd == 1 || x % gcd == 0); */
    /*@ assert (gcd == 1 || x % gcd == 0 || y % gcd == 0); */
    /*@ assert (gcd == 1 || gcd >= 1); */
    /*@ assert (gcd == 1 || gcd == i - 1 || gcd <= i); */
    /*@ assert (gcd == 1 || gcd <= y); */
    /*@ assert (gcd == 1 || gcd <= x); */
    /*@ assert (gcd == 1 || gcd <= x && gcd <= y); */
    /*@ assert (gcd == 1 || gcd <= i); */
    /*@ assert (gcd == 1 || gcd <= i - 1); */
    /*@ assert (gcd == 1 || gcd % 1 == 0); */
    /*@ assert (gcd == 1 || \forall integer k; 1 <= k < i ==> (x % k == 0 && y % k == 0 ==> k <= gcd)); */
    /*@ assert (gcd == 1 || \forall integer k; 1 <= k < i ==> ((x % k == 0 && y % k == 0) ==> k <= gcd)); */
    /*@ assert (gcd == 1 || \forall integer k; 1 <= k < i ==> (!(x % k == 0 && y % k == 0) || k <= gcd)); */
    /*@ assert (gcd == 1 || \exists integer k; 1 <= k < i && x % k == 0 && y % k == 0 && gcd == k); */
    /*@ assert (gcd == 1 || 1 <= gcd); */
    /*@ assert (gcd == 1 || 1 <= gcd <= y); */
    /*@ assert (gcd == 1 || 1 <= gcd <= x); */
    /*@ assert (gcd == 1 || 1 <= gcd <= i); */
    /*@ assert (gcd == 1 || 1 <= gcd <= i - 1); */
    /*@ assert (gcd == 1 || (x % gcd == 0 && y % gcd == 0)); */
    /*@ assert (gcd == 1 || (\forall integer k; 1 <= k < i ==> (x % k == 0 && y % k == 0 ==> k <= gcd))); */
    /*@ assert (gcd == 1 || (\forall integer k; 1 <= k < i ==> ((x % k == 0 && y % k == 0) ==> k <= gcd))); */
    /*@ assert (gcd == 1 || (\forall integer k; 1 <= k < i ==> !(x % k == 0 && y % k == 0) || k <= gcd)); */
    /*@ assert (gcd == 1 || (\exists integer k; 1 <= k <= i && x % k == 0 && y % k == 0 && gcd == k)); */
    /*@ assert (gcd == 1 || (\exists integer k; 1 <= k < i && x % k == 0 && y % k == 0 && gcd == k)); */
    /*@ assert (gcd == 1 || (1 <= gcd <= x)); */
    /*@ assert (gcd == 1 || (1 <= gcd <= i)); */
    /*@ assert (gcd == 1 || (1 <= gcd <= i - 1)); */
    /*@ assert (gcd <= y || gcd == 1); */
    /*@ assert (gcd <= x || gcd == 1); */
    /*@ assert (gcd <= i); */
    /*@ assert (gcd <= i || gcd == 1); */
    /*@ assert (gcd <= i - 1 || gcd == 1); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (x % k == 0 ==> x % gcd == 0)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (x % k == 0 && y % k == 0 ==> k <= gcd)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> ((x % k == 0 && y % k == 0) ==> k <= gcd)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> !(x % k == 0 && y % k == 0) || k <= gcd); */
    /*@ assert (\forall integer k; 1 <= k < i && x % k == 0 && y % k == 0 ==> k <= gcd); */
    /*@ assert (\exists integer k; 1 <= k <= i && x % k == 0 && y % k == 0 && gcd == k); */
    /*@ assert (1 <= i); */
    /*@ assert (1 <= gcd); */
    /*@ assert (1 <= gcd <= i - 1 || gcd == 1); */
    /*@ assert (0 <= gcd); */
    /*@ assert (0 < gcd); */
    /*@ assert (0 < gcd || gcd <= x); */
}

/*@ requires (\forall integer k; 1 <= k < i ==> (!(x % k == 0 && y % k == 0) || k <= gcd)) && (y > 0 ==> gcd <= y) && (y % gcd == 0) && (y % gcd == 0 || gcd == 1) && (x > 0 ==> y > 0) && (x > 0 ==> gcd >= 1) && (x > 0 ==> gcd <= x) && (x <= y) && (x <= y || y <= x) && (x % gcd == 0) && (x % gcd == 0 || y % gcd == 0) && (x % gcd == 0 || gcd == 1) && (x % gcd == 0 && y % gcd == 0) && (i <= x + 1 || 0 < gcd) && (gcd == 1 || y % gcd == 0) && (gcd == 1 || x % gcd == 0) && (gcd == 1 || x % gcd == 0 || y % gcd == 0) && (gcd == 1 || gcd >= 1) && (gcd == 1 || gcd == i - 1 || gcd <= i) && (gcd == 1 || gcd <= y) && (gcd == 1 || gcd <= x) && (gcd == 1 || gcd <= x && gcd <= y) && (gcd == 1 || gcd <= i) && (gcd == 1 || gcd <= i - 1) && (gcd == 1 || gcd % 1 == 0) && (gcd == 1 || \forall integer k; 1 <= k < i ==> (x % k == 0 && y % k == 0 ==> k <= gcd)) && (gcd == 1 || \forall integer k; 1 <= k < i ==> ((x % k == 0 && y % k == 0) ==> k <= gcd)) && (gcd == 1 || \forall integer k; 1 <= k < i ==> (!(x % k == 0 && y % k == 0) || k <= gcd)) && (gcd == 1 || \exists integer k; 1 <= k < i && x % k == 0 && y % k == 0 && gcd == k) && (gcd == 1 || 1 <= gcd) && (gcd == 1 || 1 <= gcd <= y) && (gcd == 1 || 1 <= gcd <= x) && (gcd == 1 || 1 <= gcd <= i) && (gcd == 1 || 1 <= gcd <= i - 1) && (gcd == 1 || (x % gcd == 0 && y % gcd == 0)) && (gcd == 1 || (\forall integer k; 1 <= k < i ==> (x % k == 0 && y % k == 0 ==> k <= gcd))) && (gcd == 1 || (\forall integer k; 1 <= k < i ==> ((x % k == 0 && y % k == 0) ==> k <= gcd))) && (gcd == 1 || (\forall integer k; 1 <= k < i ==> !(x % k == 0 && y % k == 0) || k <= gcd)) && (gcd == 1 || (\exists integer k; 1 <= k <= i && x % k == 0 && y % k == 0 && gcd == k)) && (gcd == 1 || (\exists integer k; 1 <= k < i && x % k == 0 && y % k == 0 && gcd == k)) && (gcd == 1 || (1 <= gcd <= x)) && (gcd == 1 || (1 <= gcd <= i)) && (gcd == 1 || (1 <= gcd <= i - 1)) && (gcd <= y || gcd == 1) && (gcd <= x || gcd == 1) && (gcd <= i) && (gcd <= i || gcd == 1) && (gcd <= i - 1 || gcd == 1) && (\forall integer k; 1 <= k < i ==> (x % k == 0 ==> x % gcd == 0)) && (\forall integer k; 1 <= k < i ==> (x % k == 0 && y % k == 0 ==> k <= gcd)) && (\forall integer k; 1 <= k < i ==> ((x % k == 0 && y % k == 0) ==> k <= gcd)) && (\forall integer k; 1 <= k < i ==> !(x % k == 0 && y % k == 0) || k <= gcd) && (\forall integer k; 1 <= k < i && x % k == 0 && y % k == 0 ==> k <= gcd) && (\exists integer k; 1 <= k <= i && x % k == 0 && y % k == 0 && gcd == k) && (1 <= i) && (1 <= gcd) && (1 <= gcd <= i - 1 || gcd == 1) && (0 <= gcd) && (0 < gcd) && (0 < gcd || gcd <= x);
    assigns \nothing;
*/
void check_B_implies_A(int foo322, int gcd, int i, int k, int x, int y) {
    /*@ assert (1 <= i); */
    /*@ assert ((i <= x + 1) || (x < 0)); */
    /*@ assert (gcd >= 1); */
    /*@ assert (gcd <= i); */
    /*@ assert (foo322 == 1); */
    /*@ assert (gcd == 1 || (x % gcd == 0 && y % gcd == 0)); */
    /*@ assert (\forall integer k; 1 <= k < i && x % k == 0 && y % k == 0 ==> k <= gcd); */
    /*@ assert (gcd == 1 || (\exists integer k; 1 <= k < i && x % k == 0 && y % k == 0 && gcd == k)); */
}
