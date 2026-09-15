#include <limits.h>

/*@logic integer divcount(integer n, integer i) =
      i <= 1 ? 0 : divcount(n, i - 1) + ((n % (i - 1)) == 0 ? 1 : 0);*/

/*@ requires (1 <= i <= n + 1) && (0 <= count <= i - 1) && (count == divcount(n, i)) && (count == divcount(\at(n,Pre), i)) && (\forall integer k) && (\forall integer k) && ((i <= \at(n,Pre)) ==> (count == divcount(n, i))) && ((i <= \at(n,Pre)) ==> (0 <= count <= i - 1)) && (n == \at(n,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int count, int i, int k, int n) {
    /*@ assert (\forall integer k) && (count >= 0 && i >= 1) && (count >= 0 && count <= i) && (count == 0 || count >= 1) && (count == 0 || count >= 0) && (count == 0 || count > 0) && (count <= i) && (count <= i - 1) && (count <= i - 1 || i <= n + 1) && (count <= i - 1 || count == i) && (count <= i + 1) && (count <= i + 1 || i <= n + 1) && (count <= i && count >= 0) && (count <= i && 0 <= count) && (count < i + 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (1 <= i) && (0 <= i) && (0 <= i - count) && (0 <= count) && (0 <= count <= i - 1 || i <= n + 1); */
}

/*@ requires (\forall integer k) && (count >= 0 && i >= 1) && (count >= 0 && count <= i) && (count == 0 || count >= 1) && (count == 0 || count >= 0) && (count == 0 || count > 0) && (count <= i) && (count <= i - 1) && (count <= i - 1 || i <= n + 1) && (count <= i - 1 || count == i) && (count <= i + 1) && (count <= i + 1 || i <= n + 1) && (count <= i && count >= 0) && (count <= i && 0 <= count) && (count < i + 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (1 <= i) && (0 <= i) && (0 <= i - count) && (0 <= count) && (0 <= count <= i - 1 || i <= n + 1);
    assigns \nothing;
*/
void check_B_implies_A(int count, int i, int k, int n) {
    /*@ assert (1 <= i <= n + 1) && (0 <= count <= i - 1) && (count == divcount(n, i)) && (count == divcount(\at(n,Pre), i)) && (\forall integer k) && (\forall integer k) && ((i <= \at(n,Pre)) ==> (count == divcount(n, i))) && ((i <= \at(n,Pre)) ==> (0 <= count <= i - 1)) && (n == \at(n,Pre)); */
}
