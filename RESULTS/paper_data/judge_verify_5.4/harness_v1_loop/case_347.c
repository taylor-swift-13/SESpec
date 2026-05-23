#include <limits.h>

/*@logic integer nb_divisors(integer x, integer n) =
    n <= 0 ? 0 : nb_divisors(x, n - 1) + (x % n == 0 ? 1 : 0);*/

/*@ requires (1 <= i <= y + 1) && (0 <= count <= i - 1) && (count == nb_divisors(x, i - 1)) && (\forall integer k) && (y >= 0) && (x == \at(x,Pre)) && (y == \at(y,Pre) || y == -\at(y,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int count, int i, int k, int x, int y) {
    /*@ assert (i > 1 ==> count <= i - 1) && (i == 1 ==> count == 0) && (i <= y + 1) && (i <= y + 1 ==> count <= y) && (count > 0 ==> \exists integer k) && (count == 0 || count >= 1) && (count == 0 || count > 0) && (count == 0 ==> \forall integer k) && (count <= y) && (count <= y + 1) && (count <= i) && (count <= i - 1) && (count <= i + 1) && (count < i) && (count < i + 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (1 <= i) && (0 <= y) && (0 <= i) && (0 <= count) && (0 < i); */
}

/*@ requires (i > 1 ==> count <= i - 1) && (i == 1 ==> count == 0) && (i <= y + 1) && (i <= y + 1 ==> count <= y) && (count > 0 ==> \exists integer k) && (count == 0 || count >= 1) && (count == 0 || count > 0) && (count == 0 ==> \forall integer k) && (count <= y) && (count <= y + 1) && (count <= i) && (count <= i - 1) && (count <= i + 1) && (count < i) && (count < i + 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (1 <= i) && (0 <= y) && (0 <= i) && (0 <= count) && (0 < i);
    assigns \nothing;
*/
void check_B_implies_A(int count, int i, int k, int x, int y) {
    /*@ assert (1 <= i <= y + 1) && (0 <= count <= i - 1) && (count == nb_divisors(x, i - 1)) && (\forall integer k) && (y >= 0) && (x == \at(x,Pre)) && (y == \at(y,Pre) || y == -\at(y,Pre)); */
}
