#include <limits.h>

/*@ logic integer nondiv_count(integer a, integer l, integer u) =
      u < l ? 0 : nondiv_count(a, l, u - 1) + ((u % a) != 0 ? 1 : 0); */

/*@ requires (i >= l) && (count >= 0) && (count <= i - l) && (count == nondiv_count(a, l, i - 1)) && (\forall integer j; l <= j < i ==> (j % a == 0 || j % a != 0)) && ((i == l) ==> (count == 0)) && ((i > l) ==> (count == nondiv_count(a, l, i - 1)));
    assigns \nothing;
*/
void check_A_implies_B(int a, int count, int i, int j, int k, int l) {
    /*@ assert (l <= i); */
    /*@ assert (i - l - count <= i - l); */
    /*@ assert (i - l - count <= i - l + 1); */
    /*@ assert (count >= 0 && i >= l); */
    /*@ assert (count > 0 ==> \exists integer k; l <= k < i && k % a != 0); */
    /*@ assert (count == 0 || count >= 1); */
    /*@ assert (count == 0 || count > 0); */
    /*@ assert (count == 0 || count <= i - l + 1); */
    /*@ assert (count == 0 || \exists integer k; l <= k < i && k % a != 0); */
    /*@ assert (count == 0 ==> \forall integer k; l <= k < i ==> k % a == 0); */
    /*@ assert (count <= i - l); */
    /*@ assert (count <= i - l + 1); */
    /*@ assert (count - 1 <= i - l); */
    /*@ assert (count - (i - l) <= 1); */
    /*@ assert (\forall integer k; l <= k < i ==> count >= 0); */
    /*@ assert (\forall integer k; l <= k < i ==> (k % a == 0 || k % a != 0)); */
    /*@ assert (\forall integer k; l <= k < i ==> (k % a == 0 || count >= 0)); */
    /*@ assert (\forall integer k; l <= k < i ==> (k % a == 0 || count > 0)); */
    /*@ assert (\forall integer k; l <= k < i ==> (k % a == 0 ==> count >= 0)); */
    /*@ assert (\forall integer k; l <= k < i ==> (k % a != 0 ==> count >= 1)); */
    /*@ assert (\forall integer k; l <= k < i ==> (k % a != 0 ==> count >= 0)); */
    /*@ assert (\forall integer k; l <= k < i ==> (k % a != 0 ==> count > 0)); */
    /*@ assert (\forall integer k; l <= k < i && k % a == 0 ==> count <= i - l + 1); */
    /*@ assert (\forall integer k; l <= k < i && k % a != 0 ==> count >= 1); */
    /*@ assert (0 <= i - l - count); */
    /*@ assert (0 <= count); */
    /*@ assert (-1 <= i - l - count); */
}

/*@ requires (l <= i) && (i - l - count <= i - l) && (i - l - count <= i - l + 1) && (count >= 0 && i >= l) && (count > 0 ==> \exists integer k; l <= k < i && k % a != 0) && (count == 0 || count >= 1) && (count == 0 || count > 0) && (count == 0 || count <= i - l + 1) && (count == 0 || \exists integer k; l <= k < i && k % a != 0) && (count == 0 ==> \forall integer k; l <= k < i ==> k % a == 0) && (count <= i - l) && (count <= i - l + 1) && (count - 1 <= i - l) && (count - (i - l) <= 1) && (\forall integer k; l <= k < i ==> count >= 0) && (\forall integer k; l <= k < i ==> (k % a == 0 || k % a != 0)) && (\forall integer k; l <= k < i ==> (k % a == 0 || count >= 0)) && (\forall integer k; l <= k < i ==> (k % a == 0 || count > 0)) && (\forall integer k; l <= k < i ==> (k % a == 0 ==> count >= 0)) && (\forall integer k; l <= k < i ==> (k % a != 0 ==> count >= 1)) && (\forall integer k; l <= k < i ==> (k % a != 0 ==> count >= 0)) && (\forall integer k; l <= k < i ==> (k % a != 0 ==> count > 0)) && (\forall integer k; l <= k < i && k % a == 0 ==> count <= i - l + 1) && (\forall integer k; l <= k < i && k % a != 0 ==> count >= 1) && (0 <= i - l - count) && (0 <= count) && (-1 <= i - l - count);
    assigns \nothing;
*/
void check_B_implies_A(int a, int count, int i, int j, int k, int l) {
    /*@ assert (i >= l); */
    /*@ assert (count >= 0); */
    /*@ assert (count <= i - l); */
    /*@ assert (count == nondiv_count(a, l, i - 1)); */
    /*@ assert (\forall integer j; l <= j < i ==> (j % a == 0 || j % a != 0)); */
    /*@ assert ((i == l) ==> (count == 0)); */
    /*@ assert ((i > l) ==> (count == nondiv_count(a, l, i - 1))); */
}
