#include <limits.h>

/*@logic integer count_divisors(integer n, integer start, integer end) =
      end <= start ? 0 :
      ((n % (end - 1) == 0)
         ? count_divisors(n, start, end - 1) + 1
         : count_divisors(n, start, end - 1));*/

/*@ requires (1 <= i) && (0 <= count) && (count <= i - 1) && (n == \at(n,Pre)) && (count == count_divisors(n, 1, i)) && (\forall integer k) && (\forall integer k) && ((i <= \at(n,Pre)) ==> (count >= 0 && count <= \at(n,Pre))) && ((i <= \at(n,Pre)) ==> (count == count_divisors(n, 1, i))) && ((i > \at(n,Pre)) ==> (count == count_divisors(n, 1, \at(n,Pre) + 1)));
    assigns \nothing;
*/
void check_A_implies_B(int count, int i, int k, int n) {
    /*@ assert (i - count <= n || i - count <= i) && (i - count <= i) && (i - count <= i || i <= n + 1) && (count == 0 || count > 0) && (count <= i) && (count <= i-1) && (count <= i - 1) && (count <= i - 1 || i == 1) && (count <= i - 1 || count == i) && (count <= i + 1) && (count <= i && count >= 0) && (count - i <= 0) && (count % 2 == i % 2 || count % 2 == (i - 1) % 2) && (count % 2 == i % 2 || count % 2 == (i + 1) % 2) && (count % 2 == 0 || count % 2 == 1) && (count % 2 == (i - 1) % 2 || count % 2 == i % 2) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (1 <= i) && (1 <= i - count) && (0 <= i - count) && (0 <= i - count || i <= n + 1) && (0 <= count) && (0 < i - count); */
}

/*@ requires (i - count <= n || i - count <= i) && (i - count <= i) && (i - count <= i || i <= n + 1) && (count == 0 || count > 0) && (count <= i) && (count <= i-1) && (count <= i - 1) && (count <= i - 1 || i == 1) && (count <= i - 1 || count == i) && (count <= i + 1) && (count <= i && count >= 0) && (count - i <= 0) && (count % 2 == i % 2 || count % 2 == (i - 1) % 2) && (count % 2 == i % 2 || count % 2 == (i + 1) % 2) && (count % 2 == 0 || count % 2 == 1) && (count % 2 == (i - 1) % 2 || count % 2 == i % 2) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (1 <= i) && (1 <= i - count) && (0 <= i - count) && (0 <= i - count || i <= n + 1) && (0 <= count) && (0 < i - count);
    assigns \nothing;
*/
void check_B_implies_A(int count, int i, int k, int n) {
    /*@ assert (1 <= i) && (0 <= count) && (count <= i - 1) && (n == \at(n,Pre)) && (count == count_divisors(n, 1, i)) && (\forall integer k) && (\forall integer k) && ((i <= \at(n,Pre)) ==> (count >= 0 && count <= \at(n,Pre))) && ((i <= \at(n,Pre)) ==> (count == count_divisors(n, 1, i))) && ((i > \at(n,Pre)) ==> (count == count_divisors(n, 1, \at(n,Pre) + 1))); */
}
