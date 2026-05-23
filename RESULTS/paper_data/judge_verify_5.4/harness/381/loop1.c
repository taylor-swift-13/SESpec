#include <limits.h>

/*@ logic integer common_divisor_count(integer x, integer y, integer n) =
    n <= 0 ? 0 :
    common_divisor_count(x, y, n - 1) +
    ((x % n == 0 && y % n == 0) ? 1 : 0); */

/*@ requires (1 <= i) && (count >= 0) && (count <= i - 1) && (count == common_divisor_count(\at(x,Pre), \at(y,Pre), i - 1)) && (y == \at(y,Pre)) && (x == \at(x,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int count, int d, int i, int k, int x, int y) {
    /*@ assert (count >= 0 && count <= i - 1); */
    /*@ assert (count > 0 ==> i > 1); */
    /*@ assert (count == 0 || count >= 1); */
    /*@ assert (count == 0 || count >= 0); */
    /*@ assert (count == 0 || count > 0); */
    /*@ assert (count == 0 ==> i == 1); */
    /*@ assert (count <= i); */
    /*@ assert (count <= i - 1); */
    /*@ assert (count <= i - 1 || count == i); */
    /*@ assert (count <= i - 1 || count <= i); */
    /*@ assert (count <= i + 1); */
    /*@ assert (count <= i && count >= 0); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (x % k != 0 || y % k != 0 || count >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> ((x % k == 0 && y % k == 0) ==> count >= 1)); */
    /*@ assert (\forall integer k; 1 <= k < i && x % k == 0 && y % k == 0 ==> count >= 1); */
    /*@ assert (\forall integer d; 1 <= d < i ==> (x % d == 0 || y % d == 0 || count >= 0)); */
    /*@ assert (\forall integer d; 1 <= d < i ==> (x % d == 0 && y % d == 0 ==> count >= 1)); */
    /*@ assert (\forall integer d; 1 <= d < i ==> (x % d == 0 && y % d == 0 ==> count >= 0)); */
    /*@ assert (\forall integer d; 1 <= d < i ==> (x % d == 0 && y % d == 0 ==> count <= i)); */
    /*@ assert (\forall integer d; 1 <= d < i ==> (x % d == 0 && y % d == 0 ==> count <= i - 1)); */
    /*@ assert (\forall integer d; 1 <= d < i ==> (x % d != 0 || y % d != 0 || count >= 0)); */
    /*@ assert (\forall integer d; 1 <= d < i ==> ((x % d == 0 && y % d == 0) ==> count >= 1)); */
    /*@ assert (\forall integer d; 1 <= d < i ==> ((x % d == 0 && y % d == 0) ==> count >= 0)); */
    /*@ assert (\forall integer d; 1 <= d < i ==> ((x % d == 0 && y % d == 0) ==> count <= i)); */
    /*@ assert (\forall integer d; 1 <= d < i ==> ((x % d == 0 && y % d == 0) ==> count <= i - 1)); */
    /*@ assert (\forall integer d; 1 <= d < i ==> ((x % d != 0 || y % d != 0) || count >= 0)); */
    /*@ assert (\forall integer d; 1 <= d < i && x % d == 0 && y % d == 0 ==> count >= 1); */
    /*@ assert (\forall integer d; 1 <= d < i && x % d == 0 && y % d == 0 ==> count > 0); */
    /*@ assert (\exists integer d; 1 <= d <= i && x % d == 0 && y % d == 0); */
    /*@ assert (\exists integer d; 1 <= d < i && x % d == 0 && y % d == 0 ==> count >= 1); */
    /*@ assert (\exists integer d; 1 <= d < i && x % d == 0 && y % d == 0 ==> count >= 0); */
    /*@ assert (\exists integer d; 1 <= d < i && x % d == 0 && y % d == 0 ==> count > 0); */
    /*@ assert (1 <= i); */
    /*@ assert (0 <= i); */
    /*@ assert (0 <= count); */
}

/*@ requires (count >= 0 && count <= i - 1) && (count > 0 ==> i > 1) && (count == 0 || count >= 1) && (count == 0 || count >= 0) && (count == 0 || count > 0) && (count == 0 ==> i == 1) && (count <= i) && (count <= i - 1) && (count <= i - 1 || count == i) && (count <= i - 1 || count <= i) && (count <= i + 1) && (count <= i && count >= 0) && (\forall integer k; 1 <= k < i ==> (x % k != 0 || y % k != 0 || count >= 0)) && (\forall integer k; 1 <= k < i ==> ((x % k == 0 && y % k == 0) ==> count >= 1)) && (\forall integer k; 1 <= k < i && x % k == 0 && y % k == 0 ==> count >= 1) && (\forall integer d; 1 <= d < i ==> (x % d == 0 || y % d == 0 || count >= 0)) && (\forall integer d; 1 <= d < i ==> (x % d == 0 && y % d == 0 ==> count >= 1)) && (\forall integer d; 1 <= d < i ==> (x % d == 0 && y % d == 0 ==> count >= 0)) && (\forall integer d; 1 <= d < i ==> (x % d == 0 && y % d == 0 ==> count <= i)) && (\forall integer d; 1 <= d < i ==> (x % d == 0 && y % d == 0 ==> count <= i - 1)) && (\forall integer d; 1 <= d < i ==> (x % d != 0 || y % d != 0 || count >= 0)) && (\forall integer d; 1 <= d < i ==> ((x % d == 0 && y % d == 0) ==> count >= 1)) && (\forall integer d; 1 <= d < i ==> ((x % d == 0 && y % d == 0) ==> count >= 0)) && (\forall integer d; 1 <= d < i ==> ((x % d == 0 && y % d == 0) ==> count <= i)) && (\forall integer d; 1 <= d < i ==> ((x % d == 0 && y % d == 0) ==> count <= i - 1)) && (\forall integer d; 1 <= d < i ==> ((x % d != 0 || y % d != 0) || count >= 0)) && (\forall integer d; 1 <= d < i && x % d == 0 && y % d == 0 ==> count >= 1) && (\forall integer d; 1 <= d < i && x % d == 0 && y % d == 0 ==> count > 0) && (\exists integer d; 1 <= d <= i && x % d == 0 && y % d == 0) && (\exists integer d; 1 <= d < i && x % d == 0 && y % d == 0 ==> count >= 1) && (\exists integer d; 1 <= d < i && x % d == 0 && y % d == 0 ==> count >= 0) && (\exists integer d; 1 <= d < i && x % d == 0 && y % d == 0 ==> count > 0) && (1 <= i) && (0 <= i) && (0 <= count);
    assigns \nothing;
*/
void check_B_implies_A(int count, int d, int i, int k, int x, int y) {
    /*@ assert (1 <= i); */
    /*@ assert (count >= 0); */
    /*@ assert (count <= i - 1); */
    /*@ assert (count == common_divisor_count(\at(x,Pre), \at(y,Pre), i - 1)); */
    /*@ assert (y == \at(y,Pre)); */
    /*@ assert (x == \at(x,Pre)); */
}
