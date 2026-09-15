#include <limits.h>

/*@logic integer common_divisor_count(integer x, integer y, integer n) =
    n <= 0 ? 0 :
    common_divisor_count(x, y, n - 1) +
    ((x % n == 0 && y % n == 0) ? 1 : 0);*/

/*@ requires (1 <= i) && (count >= 0) && (count <= i - 1) && (count == common_divisor_count(\at(x,Pre), \at(y,Pre), i - 1)) && (y == \at(y,Pre)) && (x == \at(x,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int count, int d, int i, int k, int x, int y) {
    /*@ assert (count >= 0 && count <= i - 1) && (count > 0 ==> i > 1) && (count == 0 || count >= 1) && (count == 0 || count >= 0) && (count == 0 || count > 0) && (count == 0 ==> i == 1) && (count <= i) && (count <= i - 1) && (count <= i - 1 || count == i) && (count <= i - 1 || count <= i) && (count <= i + 1) && (count <= i && count >= 0) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer d) && (\forall integer d) && (\forall integer d) && (\forall integer d) && (\forall integer d) && (\forall integer d) && (\forall integer d) && (\forall integer d) && (\forall integer d) && (\forall integer d) && (\forall integer d) && (\forall integer d) && (\forall integer d) && (\exists integer d) && (\exists integer d) && (\exists integer d) && (\exists integer d) && (1 <= i) && (0 <= i) && (0 <= count); */
}

/*@ requires (count >= 0 && count <= i - 1) && (count > 0 ==> i > 1) && (count == 0 || count >= 1) && (count == 0 || count >= 0) && (count == 0 || count > 0) && (count == 0 ==> i == 1) && (count <= i) && (count <= i - 1) && (count <= i - 1 || count == i) && (count <= i - 1 || count <= i) && (count <= i + 1) && (count <= i && count >= 0) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer d) && (\forall integer d) && (\forall integer d) && (\forall integer d) && (\forall integer d) && (\forall integer d) && (\forall integer d) && (\forall integer d) && (\forall integer d) && (\forall integer d) && (\forall integer d) && (\forall integer d) && (\forall integer d) && (\exists integer d) && (\exists integer d) && (\exists integer d) && (\exists integer d) && (1 <= i) && (0 <= i) && (0 <= count);
    assigns \nothing;
*/
void check_B_implies_A(int count, int d, int i, int k, int x, int y) {
    /*@ assert (1 <= i) && (count >= 0) && (count <= i - 1) && (count == common_divisor_count(\at(x,Pre), \at(y,Pre), i - 1)) && (y == \at(y,Pre)) && (x == \at(x,Pre)); */
}
