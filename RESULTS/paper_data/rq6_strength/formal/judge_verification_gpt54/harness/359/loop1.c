#include <limits.h>

/*@ requires (1 <= c <= size + 1) && (0 <= total) && (0 <= ret) && (size == \at(size,Pre)) && (c == 2 * total || c == 2 * total + 1) && (ret == total * total);
    assigns \nothing;
*/
void check_A_implies_B(int *c, int k, int m, int *ret, int *size, int *total) {
    /*@ assert (total == c / 2 || total == (c - 1) / 2); */
    /*@ assert (total == c / 2 || total == (c + 1) / 2); */
    /*@ assert (total == 0 || ret >= total); */
    /*@ assert (total == 0 || ret >= total * (total - 1) / 2); */
    /*@ assert (total == 0 || ret > 0); */
    /*@ assert (total == 0 ==> ret == 0); */
    /*@ assert (total == (c / 2)); */
    /*@ assert (total == (c / 2) || total == (c - 1) / 2); */
    /*@ assert (total == (c - 1) / 2 || total == c / 2); */
    /*@ assert (total == (c - 1) / 2 + ((c - 1) % 2)); */
    /*@ assert (total == (c - 1) / 2 + ((c - 1) % 2 != 0 ? 1 : 0)); */
    /*@ assert (total == (c - (c % 2)) / 2); */
    /*@ assert (total == (c + 1) / 2 || total == c / 2); */
    /*@ assert (total <= size || ret <= size * size); */
    /*@ assert (total <= size || ret <= size * (size + 1) / 2); */
    /*@ assert (total <= size || 2 * total <= c + 1); */
    /*@ assert (total <= ret); */
    /*@ assert (total <= c); */
    /*@ assert (total <= c / 2 + 1); */
    /*@ assert (total <= c / 2 + 1 || ret <= c * c + c); */
    /*@ assert (total <= c / 2 + 1 || c <= size + 1); */
    /*@ assert (total <= c / 2 + 1 || 2 * total <= c); */
    /*@ assert (total <= c + 1); */
    /*@ assert (total <= 2 * ret); */
    /*@ assert (total <= (c + 1) / 2); */
    /*@ assert (total < c / 2 + 1); */
    /*@ assert (total - 1 <= c - total); */
    /*@ assert (total * total <= ret); */
    /*@ assert (total * total / 2 <= ret); */
    /*@ assert (total * 2 <= c + 1); */
    /*@ assert (total * (total - 1) / 2 <= ret); */
    /*@ assert (total * (total + 1) / 2 <= ret); */
    /*@ assert (ret >= total * total || ret == total * (total + 1) / 2); */
    /*@ assert (ret >= 0 || total == 0); */
    /*@ assert (ret >= 0 ==> total >= 0); */
    /*@ assert (ret >= 0 && total >= 0); */
    /*@ assert (ret >= 0 && total >= 0 && c >= 1); */
    /*@ assert (ret > 0 || total == 0); */
    /*@ assert (ret == total * total); */
    /*@ assert (ret == total * total || ret >= total); */
    /*@ assert (ret == total * total || ret > total); */
    /*@ assert (ret == total * total || ret == total * total + total); */
    /*@ assert (ret == total * total || ret == total * (total + 1) / 2); */
    /*@ assert (ret == total * (total + 1) / 2 || ret == total * total); */
    /*@ assert (ret == total * (total + 1) - total); */
    /*@ assert (ret == 0 || total > 0); */
    /*@ assert (ret == 0 || ret > 0); */
    /*@ assert (ret == 0 ==> total == 0); */
    /*@ assert (ret == (c / 2) * (c / 2)); */
    /*@ assert (ret <= size * size || 2 * total <= c + 1); */
    /*@ assert (ret <= c * c); */
    /*@ assert (ret <= c * c + c); */
    /*@ assert (ret <= c * c + c || 2 * total <= c); */
    /*@ assert (ret < c * c + c); */
    /*@ assert (ret % 2 == 0 || ret % 2 == 1); */
    /*@ assert (c == 1 || c <= size + 1); */
    /*@ assert (c == 1 || c % 2 == 0 || c % 2 == 1); */
    /*@ assert (c == 0 || ret >= total); */
    /*@ assert (c <= size + 1 || ret <= size * size); */
    /*@ assert (c <= size + 1 || ret <= size * (size + 1) / 2); */
    /*@ assert (c <= size + 1 || ret <= c * c + c); */
    /*@ assert (c <= size + 1 || 2 * total <= c); */
    /*@ assert (c <= size + 1 || 2 * total <= c + 1); */
    /*@ assert (c - total == (c + 1) / 2 || c - total == c / 2); */
    /*@ assert (c % 2 == 0 || c % 2 == 1); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (k % 2 == 0 || ret >= total)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (k % 2 == 0 || ret >= k)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (k % 2 == 0 ==> ret >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (k % 2 != 0 ==> total >= (k + 1) / 2)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (k % 2 != 0 ==> ret >= total)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (k % 2 != 0 ==> ret >= k)); */
    /*@ assert (\forall integer k; 1 <= k < c && k % 2 != 0 ==> ret >= k); */
    /*@ assert (\exists integer m; 0 <= m <= c ==> ret == m * total); */
    /*@ assert (\exists integer k; 0 <= k <= c-1 && total == (k + 1) / 2); */
    /*@ assert (\exists integer k; 0 <= k <= c ==> total == (k / 2)); */
    /*@ assert (\exists integer k; 0 <= k <= c - 1 && total == (k + 1) / 2); */
    /*@ assert (\exists integer k; 0 <= k <= c && total == k / 2); */
    /*@ assert (\exists integer k; 0 <= k <= c && total == (k / 2)); */
    /*@ assert (\exists integer k; 0 <= k < c ==> (k % 2 != 0 && total == (k + 1) / 2)); */
    /*@ assert (2 * total == c || 2 * total == c - 1); */
    /*@ assert (2 * total <= c); */
    /*@ assert (2 * total <= c + 1); */
    /*@ assert (2 * total <= c + 1 || ret <= size * (size + 1) / 2); */
    /*@ assert (2 * total < c + 1); */
    /*@ assert (2 * total - 1 <= ret); */
    /*@ assert (1 <= c); */
    /*@ assert (0 <= total); */
    /*@ assert (0 <= ret); */
    /*@ assert (0 <= c); */
    /*@ assert (0 <= c - total); */
}

/*@ requires (total == c / 2 || total == (c - 1) / 2) && (total == c / 2 || total == (c + 1) / 2) && (total == 0 || ret >= total) && (total == 0 || ret >= total * (total - 1) / 2) && (total == 0 || ret > 0) && (total == 0 ==> ret == 0) && (total == (c / 2)) && (total == (c / 2) || total == (c - 1) / 2) && (total == (c - 1) / 2 || total == c / 2) && (total == (c - 1) / 2 + ((c - 1) % 2)) && (total == (c - 1) / 2 + ((c - 1) % 2 != 0 ? 1 : 0)) && (total == (c - (c % 2)) / 2) && (total == (c + 1) / 2 || total == c / 2) && (total <= size || ret <= size * size) && (total <= size || ret <= size * (size + 1) / 2) && (total <= size || 2 * total <= c + 1) && (total <= ret) && (total <= c) && (total <= c / 2 + 1) && (total <= c / 2 + 1 || ret <= c * c + c) && (total <= c / 2 + 1 || c <= size + 1) && (total <= c / 2 + 1 || 2 * total <= c) && (total <= c + 1) && (total <= 2 * ret) && (total <= (c + 1) / 2) && (total < c / 2 + 1) && (total - 1 <= c - total) && (total * total <= ret) && (total * total / 2 <= ret) && (total * 2 <= c + 1) && (total * (total - 1) / 2 <= ret) && (total * (total + 1) / 2 <= ret) && (ret >= total * total || ret == total * (total + 1) / 2) && (ret >= 0 || total == 0) && (ret >= 0 ==> total >= 0) && (ret >= 0 && total >= 0) && (ret >= 0 && total >= 0 && c >= 1) && (ret > 0 || total == 0) && (ret == total * total) && (ret == total * total || ret >= total) && (ret == total * total || ret > total) && (ret == total * total || ret == total * total + total) && (ret == total * total || ret == total * (total + 1) / 2) && (ret == total * (total + 1) / 2 || ret == total * total) && (ret == total * (total + 1) - total) && (ret == 0 || total > 0) && (ret == 0 || ret > 0) && (ret == 0 ==> total == 0) && (ret == (c / 2) * (c / 2)) && (ret <= size * size || 2 * total <= c + 1) && (ret <= c * c) && (ret <= c * c + c) && (ret <= c * c + c || 2 * total <= c) && (ret < c * c + c) && (ret % 2 == 0 || ret % 2 == 1) && (c == 1 || c <= size + 1) && (c == 1 || c % 2 == 0 || c % 2 == 1) && (c == 0 || ret >= total) && (c <= size + 1 || ret <= size * size) && (c <= size + 1 || ret <= size * (size + 1) / 2) && (c <= size + 1 || ret <= c * c + c) && (c <= size + 1 || 2 * total <= c) && (c <= size + 1 || 2 * total <= c + 1) && (c - total == (c + 1) / 2 || c - total == c / 2) && (c % 2 == 0 || c % 2 == 1) && (\forall integer k; 1 <= k < c ==> (k % 2 == 0 || ret >= total)) && (\forall integer k; 1 <= k < c ==> (k % 2 == 0 || ret >= k)) && (\forall integer k; 1 <= k < c ==> (k % 2 == 0 ==> ret >= 0)) && (\forall integer k; 1 <= k < c ==> (k % 2 != 0 ==> total >= (k + 1) / 2)) && (\forall integer k; 1 <= k < c ==> (k % 2 != 0 ==> ret >= total)) && (\forall integer k; 1 <= k < c ==> (k % 2 != 0 ==> ret >= k)) && (\forall integer k; 1 <= k < c && k % 2 != 0 ==> ret >= k) && (\exists integer m; 0 <= m <= c ==> ret == m * total) && (\exists integer k; 0 <= k <= c-1 && total == (k + 1) / 2) && (\exists integer k; 0 <= k <= c ==> total == (k / 2)) && (\exists integer k; 0 <= k <= c - 1 && total == (k + 1) / 2) && (\exists integer k; 0 <= k <= c && total == k / 2) && (\exists integer k; 0 <= k <= c && total == (k / 2)) && (\exists integer k; 0 <= k < c ==> (k % 2 != 0 && total == (k + 1) / 2)) && (2 * total == c || 2 * total == c - 1) && (2 * total <= c) && (2 * total <= c + 1) && (2 * total <= c + 1 || ret <= size * (size + 1) / 2) && (2 * total < c + 1) && (2 * total - 1 <= ret) && (1 <= c) && (0 <= total) && (0 <= ret) && (0 <= c) && (0 <= c - total);
    assigns \nothing;
*/
void check_B_implies_A(int *c, int k, int m, int *ret, int *size, int *total) {
    /*@ assert (1 <= c <= size + 1); */
    /*@ assert (0 <= total); */
    /*@ assert (0 <= ret); */
    /*@ assert (size == \at(size,Pre)); */
    /*@ assert (c == 2 * total || c == 2 * total + 1); */
    /*@ assert (ret == total * total); */
}
