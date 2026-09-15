#include <limits.h>

/*@ requires (1 <= c) && (c == 1 || c <= size + 1) && (0 <= total) && (0 <= result) && (result % 2 == 0) && (result >= 2 * total) && (total <= c / 2) && (c == 1 || total <= (c - 1) / 2) && (result == 0 || result >= total) && ((c <= \at(size,Pre)) ==> (result >= 0)) && ((c <= \at(size,Pre)) ==> (total >= 0)) && (result == total * (total + 1)) && (c == 2 * total + 1 || c == 2 * total + 2) && (size == \at(size,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *c, int k, int *size, int *total) {
    /*@ assert (result == total * (total + 1) || result == total * (total + 1) / 2); */
    /*@ assert (total >= 0 && result >= 0); */
    /*@ assert (total > 0 ==> result >= total); */
    /*@ assert (total > 0 ==> result >= 2 * total); */
    /*@ assert (total > 0 ==> result / total >= 1); */
    /*@ assert (total > 0 ==> result % 2 == 0); */
    /*@ assert (total == c / 2 || total == (c - 1) / 2); */
    /*@ assert (total == 0 || total * 2 <= c); */
    /*@ assert (total == 0 || total * 2 <= c + 1); */
    /*@ assert (total == 0 || result >= total); */
    /*@ assert (total == 0 || result >= 2 * total); */
    /*@ assert (total == 0 || result >= 0); */
    /*@ assert (total == 0 || result > total); */
    /*@ assert (total == 0 || result > 0); */
    /*@ assert (total == 0 || result == total * (total + 1)); */
    /*@ assert (total == 0 || result <= total * size); */
    /*@ assert (total == 0 || result / total >= 1); */
    /*@ assert (total == 0 || result % 2 == 0); */
    /*@ assert (total == 0 || 2 * total <= result); */
    /*@ assert (total == 0 || 2 * total <= result + c); */
    /*@ assert (total == 0 || 2 * total <= c); */
    /*@ assert (total == 0 || 2 * total <= c + 1); */
    /*@ assert (total == 0 ==> result == 0); */
    /*@ assert (total == (c - 1) / 2 || total == c / 2); */
    /*@ assert (total <= result); */
    /*@ assert (total <= c); */
    /*@ assert (total <= c / 2); */
    /*@ assert (total <= c / 2 + 1); */
    /*@ assert (total <= c - 1); */
    /*@ assert (total < c / 2 + 1); */
    /*@ assert (total * 2 <= c); */
    /*@ assert (total * 2 <= c || total == 0); */
    /*@ assert (total * 2 <= c || total <= c / 2 + 1); */
    /*@ assert (total * 2 <= c || total * 2 == c + 1); */
    /*@ assert (total * 2 <= c || total * 2 <= c + 1); */
    /*@ assert (total * 2 <= c || c <= size + 1); */
    /*@ assert (total * 2 <= c || 2 * total <= c + 1); */
    /*@ assert (total * 2 <= c + 1); */
    /*@ assert (total * 2 <= c + 1 || c <= size + 1); */
    /*@ assert (total * 2 <= 2 * c); */
    /*@ assert (total * 2 < c); */
    /*@ assert (total * 2 < c + 1); */
    /*@ assert (total * (total + 1) <= result * 2); */
    /*@ assert (result >= 0 && total >= 0); */
    /*@ assert (result >= 0 && total >= 0 && c >= 1); */
    /*@ assert (result == total * total || result == total * (total + 1)); */
    /*@ assert (result == total * (total + 1)); */
    /*@ assert (result == total * (total + 1) || result == total * total); */
    /*@ assert (result == total * (total + 1) / 2 || result == total * (total + 1)); */
    /*@ assert (result == 0 || total > 0); */
    /*@ assert (result == 0 || result >= total); */
    /*@ assert (result == 0 || result >= 2 * total); */
    /*@ assert (result == 0 || result % 2 == 0); */
    /*@ assert (result == 0 ==> total == 0); */
    /*@ assert (result <= total * size); */
    /*@ assert (result <= total * size || total <= c / 2 + 1); */
    /*@ assert (result <= total * size || total * 2 <= c); */
    /*@ assert (result <= total * size || c <= size + 1); */
    /*@ assert (result <= total * size || 2 * total <= c + 1); */
    /*@ assert (result <= total * size || 0 <= c - total); */
    /*@ assert (result <= c * total); */
    /*@ assert (result <= c * total || total * 2 <= c + 1); */
    /*@ assert (result <= c * total || c <= size + 1); */
    /*@ assert (result % 2 == 0); */
    /*@ assert (result % 2 == 0 || result % 2 == 1); */
    /*@ assert (c == total + (c - total)); */
    /*@ assert (c == 1 + total + (c - total - 1)); */
    /*@ assert (c <= size + 1 || total <= c / 2 + 1); */
    /*@ assert (c <= size + 1 || 2 * total <= c + 1); */
    /*@ assert (c % 2 == 1 || c % 2 == 0); */
    /*@ assert (c % 2 == 0 || c % 2 == 1); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (k % 2 == 0 ==> result >= k)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (k % 2 != 0 || result >= k)); */
    /*@ assert (\forall integer k; 1 <= k < c && k % 2 == 0 ==> result >= k); */
    /*@ assert (\exists integer k; 1 <= k <= c && k % 2 == 0 ==> total >= 1); */
    /*@ assert (\exists integer k; 1 <= k < c && k % 2 == 0 ==> total > 0); */
    /*@ assert (\exists integer k; 0 <= k <= c ==> (k % 2 == 0 ==> total >= 1)); */
    /*@ assert (2 * total <= result); */
    /*@ assert (2 * total <= c); */
    /*@ assert (2 * total <= c || total <= c / 2 + 1); */
    /*@ assert (2 * total <= c - 1); */
    /*@ assert (2 * total <= c + 1); */
    /*@ assert (2 * total <= c + 1 || total <= c / 2 + 1); */
    /*@ assert (2 * total < c + 1); */
    /*@ assert (1 <= c); */
    /*@ assert (0 <= total); */
    /*@ assert (0 <= result); */
    /*@ assert (0 <= c); */
    /*@ assert (0 <= c - total); */
    /*@ assert (0 <= c - total || total <= c / 2 + 1); */
    /*@ assert (0 <= c - total || total * 2 <= c); */
    /*@ assert (0 <= c - total || c <= size + 1); */
    /*@ assert (0 <= c - total || 2 * total <= c + 1); */
    /*@ assert (0 < c - total); */
}

/*@ requires (result == total * (total + 1) || result == total * (total + 1) / 2) && (total >= 0 && result >= 0) && (total > 0 ==> result >= total) && (total > 0 ==> result >= 2 * total) && (total > 0 ==> result / total >= 1) && (total > 0 ==> result % 2 == 0) && (total == c / 2 || total == (c - 1) / 2) && (total == 0 || total * 2 <= c) && (total == 0 || total * 2 <= c + 1) && (total == 0 || result >= total) && (total == 0 || result >= 2 * total) && (total == 0 || result >= 0) && (total == 0 || result > total) && (total == 0 || result > 0) && (total == 0 || result == total * (total + 1)) && (total == 0 || result <= total * size) && (total == 0 || result / total >= 1) && (total == 0 || result % 2 == 0) && (total == 0 || 2 * total <= result) && (total == 0 || 2 * total <= result + c) && (total == 0 || 2 * total <= c) && (total == 0 || 2 * total <= c + 1) && (total == 0 ==> result == 0) && (total == (c - 1) / 2 || total == c / 2) && (total <= result) && (total <= c) && (total <= c / 2) && (total <= c / 2 + 1) && (total <= c - 1) && (total < c / 2 + 1) && (total * 2 <= c) && (total * 2 <= c || total == 0) && (total * 2 <= c || total <= c / 2 + 1) && (total * 2 <= c || total * 2 == c + 1) && (total * 2 <= c || total * 2 <= c + 1) && (total * 2 <= c || c <= size + 1) && (total * 2 <= c || 2 * total <= c + 1) && (total * 2 <= c + 1) && (total * 2 <= c + 1 || c <= size + 1) && (total * 2 <= 2 * c) && (total * 2 < c) && (total * 2 < c + 1) && (total * (total + 1) <= result * 2) && (result >= 0 && total >= 0) && (result >= 0 && total >= 0 && c >= 1) && (result == total * total || result == total * (total + 1)) && (result == total * (total + 1)) && (result == total * (total + 1) || result == total * total) && (result == total * (total + 1) / 2 || result == total * (total + 1)) && (result == 0 || total > 0) && (result == 0 || result >= total) && (result == 0 || result >= 2 * total) && (result == 0 || result % 2 == 0) && (result == 0 ==> total == 0) && (result <= total * size) && (result <= total * size || total <= c / 2 + 1) && (result <= total * size || total * 2 <= c) && (result <= total * size || c <= size + 1) && (result <= total * size || 2 * total <= c + 1) && (result <= total * size || 0 <= c - total) && (result <= c * total) && (result <= c * total || total * 2 <= c + 1) && (result <= c * total || c <= size + 1) && (result % 2 == 0) && (result % 2 == 0 || result % 2 == 1) && (c == total + (c - total)) && (c == 1 + total + (c - total - 1)) && (c <= size + 1 || total <= c / 2 + 1) && (c <= size + 1 || 2 * total <= c + 1) && (c % 2 == 1 || c % 2 == 0) && (c % 2 == 0 || c % 2 == 1) && (\forall integer k; 1 <= k < c ==> (k % 2 == 0 ==> result >= k)) && (\forall integer k; 1 <= k < c ==> (k % 2 != 0 || result >= k)) && (\forall integer k; 1 <= k < c && k % 2 == 0 ==> result >= k) && (\exists integer k; 1 <= k <= c && k % 2 == 0 ==> total >= 1) && (\exists integer k; 1 <= k < c && k % 2 == 0 ==> total > 0) && (\exists integer k; 0 <= k <= c ==> (k % 2 == 0 ==> total >= 1)) && (2 * total <= result) && (2 * total <= c) && (2 * total <= c || total <= c / 2 + 1) && (2 * total <= c - 1) && (2 * total <= c + 1) && (2 * total <= c + 1 || total <= c / 2 + 1) && (2 * total < c + 1) && (1 <= c) && (0 <= total) && (0 <= result) && (0 <= c) && (0 <= c - total) && (0 <= c - total || total <= c / 2 + 1) && (0 <= c - total || total * 2 <= c) && (0 <= c - total || c <= size + 1) && (0 <= c - total || 2 * total <= c + 1) && (0 < c - total);
    assigns \nothing;
*/
void check_B_implies_A(int *c, int k, int *size, int *total) {
    /*@ assert (1 <= c); */
    /*@ assert (c == 1 || c <= size + 1); */
    /*@ assert (0 <= total); */
    /*@ assert (0 <= result); */
    /*@ assert (result % 2 == 0); */
    /*@ assert (result >= 2 * total); */
    /*@ assert (total <= c / 2); */
    /*@ assert (c == 1 || total <= (c - 1) / 2); */
    /*@ assert (result == 0 || result >= total); */
    /*@ assert ((c <= \at(size,Pre)) ==> (result >= 0)); */
    /*@ assert ((c <= \at(size,Pre)) ==> (total >= 0)); */
    /*@ assert (result == total * (total + 1)); */
    /*@ assert (c == 2 * total + 1 || c == 2 * total + 2); */
    /*@ assert (size == \at(size,Pre)); */
}
