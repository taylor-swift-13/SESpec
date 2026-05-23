#include <limits.h>

/*@ logic integer divcount(integer n, integer i) =
      i <= 1 ? 0 : divcount(n, i - 1) + ((n % (i - 1)) == 0 ? 1 : 0); */

/*@ requires (1 <= i <= n + 1) && (0 <= count <= i - 1) && (count == divcount(n, i)) && (count == divcount(\at(n,Pre), i)) && (\forall integer k; 1 <= k < i ==> ((n % k) == 0 ==> divcount(n, k + 1) == divcount(n, k) + 1)) && (\forall integer k; 1 <= k < i && (n % k) == 0 ==> count >= 1) && ((i <= \at(n,Pre)) ==> (count == divcount(n, i))) && ((i <= \at(n,Pre)) ==> (0 <= count <= i - 1)) && (n == \at(n,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int count, int i, int k, int n) {
    /*@ assert (\forall integer k; 1 <= k < i ==> (n % k == 0 ==> count <= i + 1)); */
    /*@ assert (count >= 0 && i >= 1); */
    /*@ assert (count >= 0 && count <= i); */
    /*@ assert (count == 0 || count >= 1); */
    /*@ assert (count == 0 || count >= 0); */
    /*@ assert (count == 0 || count > 0); */
    /*@ assert (count <= i); */
    /*@ assert (count <= i - 1); */
    /*@ assert (count <= i - 1 || i <= n + 1); */
    /*@ assert (count <= i - 1 || count == i); */
    /*@ assert (count <= i + 1); */
    /*@ assert (count <= i + 1 || i <= n + 1); */
    /*@ assert (count <= i && count >= 0); */
    /*@ assert (count <= i && 0 <= count); */
    /*@ assert (count < i + 1); */
    /*@ assert (\forall integer k; 1 <= k <= i ==> (n % k == 0 ==> count >= 0)); */
    /*@ assert (\forall integer k; 1 <= k <= i ==> (n % k == 0 ==> count <= i)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (n % k == 0 ==> count >= 1)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (n % k == 0 ==> count >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (n % k == 0 ==> count <= i)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (n % k != 0 || count >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (n % k != 0 || count <= i)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (n % k != 0 || count <= i + 1)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (n % k != 0 ==> count >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (n % k != 0 ==> count <= i)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> ((n % k == 0) ==> count >= 1)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> ((n % k == 0) ==> count >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> ((n % k == 0) ==> count <= i)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> ((n % k == 0) ==> count <= i + 1)); */
    /*@ assert (\exists integer k; 1 <= k <= i && (n % k == 0) ==> count >= 0); */
    /*@ assert (\exists integer k; 1 <= k < i && n % k == 0 ==> count >= 1); */
    /*@ assert (\exists integer k; 1 <= k < i && n % k == 0 ==> count >= 0); */
    /*@ assert (\exists integer k; 1 <= k < i && n % k == 0 ==> count > 0); */
    /*@ assert (1 <= i); */
    /*@ assert (0 <= i); */
    /*@ assert (0 <= i - count); */
    /*@ assert (0 <= count); */
    /*@ assert (0 <= count <= i - 1 || i <= n + 1); */
}

/*@ requires (\forall integer k; 1 <= k < i ==> (n % k == 0 ==> count <= i + 1)) && (count >= 0 && i >= 1) && (count >= 0 && count <= i) && (count == 0 || count >= 1) && (count == 0 || count >= 0) && (count == 0 || count > 0) && (count <= i) && (count <= i - 1) && (count <= i - 1 || i <= n + 1) && (count <= i - 1 || count == i) && (count <= i + 1) && (count <= i + 1 || i <= n + 1) && (count <= i && count >= 0) && (count <= i && 0 <= count) && (count < i + 1) && (\forall integer k; 1 <= k <= i ==> (n % k == 0 ==> count >= 0)) && (\forall integer k; 1 <= k <= i ==> (n % k == 0 ==> count <= i)) && (\forall integer k; 1 <= k < i ==> (n % k == 0 ==> count >= 1)) && (\forall integer k; 1 <= k < i ==> (n % k == 0 ==> count >= 0)) && (\forall integer k; 1 <= k < i ==> (n % k == 0 ==> count <= i)) && (\forall integer k; 1 <= k < i ==> (n % k != 0 || count >= 0)) && (\forall integer k; 1 <= k < i ==> (n % k != 0 || count <= i)) && (\forall integer k; 1 <= k < i ==> (n % k != 0 || count <= i + 1)) && (\forall integer k; 1 <= k < i ==> (n % k != 0 ==> count >= 0)) && (\forall integer k; 1 <= k < i ==> (n % k != 0 ==> count <= i)) && (\forall integer k; 1 <= k < i ==> ((n % k == 0) ==> count >= 1)) && (\forall integer k; 1 <= k < i ==> ((n % k == 0) ==> count >= 0)) && (\forall integer k; 1 <= k < i ==> ((n % k == 0) ==> count <= i)) && (\forall integer k; 1 <= k < i ==> ((n % k == 0) ==> count <= i + 1)) && (\exists integer k; 1 <= k <= i && (n % k == 0) ==> count >= 0) && (\exists integer k; 1 <= k < i && n % k == 0 ==> count >= 1) && (\exists integer k; 1 <= k < i && n % k == 0 ==> count >= 0) && (\exists integer k; 1 <= k < i && n % k == 0 ==> count > 0) && (1 <= i) && (0 <= i) && (0 <= i - count) && (0 <= count) && (0 <= count <= i - 1 || i <= n + 1);
    assigns \nothing;
*/
void check_B_implies_A(int count, int i, int k, int n) {
    /*@ assert (1 <= i <= n + 1); */
    /*@ assert (0 <= count <= i - 1); */
    /*@ assert (count == divcount(n, i)); */
    /*@ assert (count == divcount(\at(n,Pre), i)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> ((n % k) == 0 ==> divcount(n, k + 1) == divcount(n, k) + 1)); */
    /*@ assert (\forall integer k; 1 <= k < i && (n % k) == 0 ==> count >= 1); */
    /*@ assert ((i <= \at(n,Pre)) ==> (count == divcount(n, i))); */
    /*@ assert ((i <= \at(n,Pre)) ==> (0 <= count <= i - 1)); */
    /*@ assert (n == \at(n,Pre)); */
}
