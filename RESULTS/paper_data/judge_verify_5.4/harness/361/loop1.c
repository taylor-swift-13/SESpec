#include <limits.h>

/*@ logic integer even_count(integer n) =
    n <= 0 ? 0 : even_count(n - 1) + ((n % 2 == 0) ? 1 : 0); */
/*@ logic integer even_sum(integer n) =
    n <= 0 ? 0 : even_sum(n - 1) + ((n % 2 == 0) ? n : 0); */

/*@ requires (0 <= j) && (average >= 0) && (total >= 0) && (average == even_sum(j - 1)) && (total == even_count(j - 1)) && (total <= j - 1) && (average >= total) && ((j == 1) || (j <= size + 1)) && ((j <= size) ==> (average >= total)) && ((j <= size) ==> (average >= 0)) && ((j <= size) ==> (total >= 0)) && ((j <= size) ==> (total <= j - 1)) && ((j <= size) ==> (average == even_sum(j - 1))) && ((j <= size) ==> (total == even_count(j - 1))) && (size == \at(size,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int average, int j, int k, int size, int *total) {
    /*@ assert (total >= 0 && average >= 0); */
    /*@ assert (total > 0 ==> average >= total); */
    /*@ assert (total > 0 ==> average >= 2 * total); */
    /*@ assert (total == j / 2 || total == (j - 1) / 2); */
    /*@ assert (total == 0 || total <= j); */
    /*@ assert (total == 0 || total <= j / 2); */
    /*@ assert (total == 0 || total * 2 <= j); */
    /*@ assert (total == 0 || j > 0); */
    /*@ assert (total == 0 || average >= total); */
    /*@ assert (total == 0 || average >= 2 * total); */
    /*@ assert (total == 0 || average >= 0); */
    /*@ assert (total == 0 || average > 0); */
    /*@ assert (total == 0 || average == 0 || average >= total); */
    /*@ assert (total == 0 || 2 * total <= j); */
    /*@ assert (total == 0 || 1 <= total); */
    /*@ assert (total == 0 ==> average == 0); */
    /*@ assert (total == (j - 1) / 2); */
    /*@ assert (total == (j - 1) / 2 || total == j / 2); */
    /*@ assert (total <= j); */
    /*@ assert (total <= j / 2); */
    /*@ assert (total <= j / 2 + 1); */
    /*@ assert (total <= j - 1); */
    /*@ assert (total <= average); */
    /*@ assert (total <= (j + 1) / 2); */
    /*@ assert (total < j); */
    /*@ assert (total * 2 <= j); */
    /*@ assert (total * 2 <= j + 1); */
    /*@ assert (total * 2 - 2 <= average); */
    /*@ assert (total % 2 == 0 || total % 2 == 1); */
    /*@ assert (j == 1 || j > 0); */
    /*@ assert (j == 1 + (j - 1)); */
    /*@ assert (j <= size + 1 || 0 <= j); */
    /*@ assert (j % 2 == 1 || j % 2 == 0); */
    /*@ assert (j % 2 == 1 ==> total == (j - 1) / 2); */
    /*@ assert (j % 2 == 1 ==> average >= total); */
    /*@ assert (j % 2 == 0 || j % 2 == 1); */
    /*@ assert (j % 2 == 0 ==> average >= total); */
    /*@ assert (average >= 0 && total >= 0); */
    /*@ assert (average == total * total + total); */
    /*@ assert (average == total * (total + 1)); */
    /*@ assert (average == total * (total + 1) || total == 0); */
    /*@ assert (average == total * (total + 1) || average >= total); */
    /*@ assert (average == total * (total + 1) || average == total * (total + 1) - total); */
    /*@ assert (average == 0 || total > 0); */
    /*@ assert (average == 0 || average >= total); */
    /*@ assert (average == 0 ==> total == 0); */
    /*@ assert (average % 2 == 0); */
    /*@ assert (average % 2 == 0 || average % 2 == 1); */
    /*@ assert (\forall integer k; 1 <= k < j ==> (k % 2 == 1 || k % 2 == 0)); */
    /*@ assert (\forall integer k; 1 <= k < j ==> (k % 2 == 1 ==> total == total)); */
    /*@ assert (\forall integer k; 1 <= k < j ==> (k % 2 == 1 ==> average >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < j ==> (k % 2 == 1 ==> average == average)); */
    /*@ assert (\forall integer k; 1 <= k < j ==> (k % 2 == 0 || k % 2 == 1)); */
    /*@ assert (\forall integer k; 1 <= k < j ==> (k % 2 == 0 ==> total >= 1)); */
    /*@ assert (\forall integer k; 1 <= k < j ==> (k % 2 == 0 ==> total >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < j ==> (k % 2 == 0 ==> average >= k)); */
    /*@ assert (\forall integer k; 1 <= k < j && k % 2 == 0 ==> total >= 1); */
    /*@ assert (\forall integer k; 1 <= k < j && k % 2 == 0 ==> total >= 0); */
    /*@ assert (\forall integer k; 1 <= k < j && k % 2 == 0 ==> average >= k); */
    /*@ assert (2 * total <= j); */
    /*@ assert (2 * total <= j + 1); */
    /*@ assert (2 * total <= average); */
    /*@ assert (1 <= j); */
    /*@ assert (0 <= total); */
    /*@ assert (0 <= j); */
    /*@ assert (0 <= j - total); */
    /*@ assert (0 <= average); */
    /*@ assert (0 < j); */
}

/*@ requires (total >= 0 && average >= 0) && (total > 0 ==> average >= total) && (total > 0 ==> average >= 2 * total) && (total == j / 2 || total == (j - 1) / 2) && (total == 0 || total <= j) && (total == 0 || total <= j / 2) && (total == 0 || total * 2 <= j) && (total == 0 || j > 0) && (total == 0 || average >= total) && (total == 0 || average >= 2 * total) && (total == 0 || average >= 0) && (total == 0 || average > 0) && (total == 0 || average == 0 || average >= total) && (total == 0 || 2 * total <= j) && (total == 0 || 1 <= total) && (total == 0 ==> average == 0) && (total == (j - 1) / 2) && (total == (j - 1) / 2 || total == j / 2) && (total <= j) && (total <= j / 2) && (total <= j / 2 + 1) && (total <= j - 1) && (total <= average) && (total <= (j + 1) / 2) && (total < j) && (total * 2 <= j) && (total * 2 <= j + 1) && (total * 2 - 2 <= average) && (total % 2 == 0 || total % 2 == 1) && (j == 1 || j > 0) && (j == 1 + (j - 1)) && (j <= size + 1 || 0 <= j) && (j % 2 == 1 || j % 2 == 0) && (j % 2 == 1 ==> total == (j - 1) / 2) && (j % 2 == 1 ==> average >= total) && (j % 2 == 0 || j % 2 == 1) && (j % 2 == 0 ==> average >= total) && (average >= 0 && total >= 0) && (average == total * total + total) && (average == total * (total + 1)) && (average == total * (total + 1) || total == 0) && (average == total * (total + 1) || average >= total) && (average == total * (total + 1) || average == total * (total + 1) - total) && (average == 0 || total > 0) && (average == 0 || average >= total) && (average == 0 ==> total == 0) && (average % 2 == 0) && (average % 2 == 0 || average % 2 == 1) && (\forall integer k; 1 <= k < j ==> (k % 2 == 1 || k % 2 == 0)) && (\forall integer k; 1 <= k < j ==> (k % 2 == 1 ==> total == total)) && (\forall integer k; 1 <= k < j ==> (k % 2 == 1 ==> average >= 0)) && (\forall integer k; 1 <= k < j ==> (k % 2 == 1 ==> average == average)) && (\forall integer k; 1 <= k < j ==> (k % 2 == 0 || k % 2 == 1)) && (\forall integer k; 1 <= k < j ==> (k % 2 == 0 ==> total >= 1)) && (\forall integer k; 1 <= k < j ==> (k % 2 == 0 ==> total >= 0)) && (\forall integer k; 1 <= k < j ==> (k % 2 == 0 ==> average >= k)) && (\forall integer k; 1 <= k < j && k % 2 == 0 ==> total >= 1) && (\forall integer k; 1 <= k < j && k % 2 == 0 ==> total >= 0) && (\forall integer k; 1 <= k < j && k % 2 == 0 ==> average >= k) && (2 * total <= j) && (2 * total <= j + 1) && (2 * total <= average) && (1 <= j) && (0 <= total) && (0 <= j) && (0 <= j - total) && (0 <= average) && (0 < j);
    assigns \nothing;
*/
void check_B_implies_A(int average, int j, int k, int size, int *total) {
    /*@ assert (0 <= j); */
    /*@ assert (average >= 0); */
    /*@ assert (total >= 0); */
    /*@ assert (average == even_sum(j - 1)); */
    /*@ assert (total == even_count(j - 1)); */
    /*@ assert (total <= j - 1); */
    /*@ assert (average >= total); */
    /*@ assert ((j == 1) || (j <= size + 1)); */
    /*@ assert ((j <= size) ==> (average >= total)); */
    /*@ assert ((j <= size) ==> (average >= 0)); */
    /*@ assert ((j <= size) ==> (total >= 0)); */
    /*@ assert ((j <= size) ==> (total <= j - 1)); */
    /*@ assert ((j <= size) ==> (average == even_sum(j - 1))); */
    /*@ assert ((j <= size) ==> (total == even_count(j - 1))); */
    /*@ assert (size == \at(size,Pre)); */
}
