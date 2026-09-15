#include <limits.h>

/*@logic integer nondiv_count(integer a, integer l, integer u) =
      u < l ? 0 : nondiv_count(a, l, u - 1) + ((u % a) != 0 ? 1 : 0);*/

/*@ requires (i >= l) && (count >= 0) && (count <= i - l) && (count == nondiv_count(a, l, i - 1)) && (\forall integer j) && ((i == l) ==> (count == 0)) && ((i > l) ==> (count == nondiv_count(a, l, i - 1)));
    assigns \nothing;
*/
void check_A_implies_B(int a, int count, int i, int j, int k, int l) {
    /*@ assert (l <= i) && (i - l - count <= i - l) && (i - l - count <= i - l + 1) && (count >= 0 && i >= l) && (count > 0 ==> \exists integer k) && (count == 0 || count >= 1) && (count == 0 || count > 0) && (count == 0 || count <= i - l + 1) && (count == 0 || \exists integer k) && (count == 0 ==> \forall integer k) && (count <= i - l) && (count <= i - l + 1) && (count - 1 <= i - l) && (count - (i - l) <= 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (0 <= i - l - count) && (0 <= count) && (-1 <= i - l - count); */
}

/*@ requires (l <= i) && (i - l - count <= i - l) && (i - l - count <= i - l + 1) && (count >= 0 && i >= l) && (count > 0 ==> \exists integer k) && (count == 0 || count >= 1) && (count == 0 || count > 0) && (count == 0 || count <= i - l + 1) && (count == 0 || \exists integer k) && (count == 0 ==> \forall integer k) && (count <= i - l) && (count <= i - l + 1) && (count - 1 <= i - l) && (count - (i - l) <= 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (0 <= i - l - count) && (0 <= count) && (-1 <= i - l - count);
    assigns \nothing;
*/
void check_B_implies_A(int a, int count, int i, int j, int k, int l) {
    /*@ assert (i >= l) && (count >= 0) && (count <= i - l) && (count == nondiv_count(a, l, i - 1)) && (\forall integer j) && ((i == l) ==> (count == 0)) && ((i > l) ==> (count == nondiv_count(a, l, i - 1))); */
}
