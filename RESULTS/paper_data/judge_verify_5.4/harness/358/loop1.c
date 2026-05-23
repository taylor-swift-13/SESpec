#include <limits.h>

/*@ requires (1 <= index <= size + 1) && (0 <= total <= index / 2) && (0 <= average) && (average == total * total) && (total == index / 2) && ((index <= size) ==> (average == total * total)) && ((index <= size) ==> (total == index / 2)) && (size == \at(size,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int average, int *index, int k, int size, int *total) {
    /*@ assert (total >= 0 && average >= 0 && index >= 1); */
    /*@ assert (total == index / 2 || total == (index - 1) / 2); */
    /*@ assert (total <= index && 0 <= total); */
    /*@ assert (index - total == (index + 1) / 2); */
    /*@ assert (average == total * total || average == index * (index - 1) / 2); */
    /*@ assert (total >= 0 && index >= 1); */
    /*@ assert (total >= 0 && average >= 0); */
    /*@ assert (total > 0 || index == 1); */
    /*@ assert (total > 0 || index <= 1); */
    /*@ assert (total == index / 2); */
    /*@ assert (total == index / 2 || total == (index + 1) / 2); */
    /*@ assert (total == 0 || total > 0); */
    /*@ assert (total == 0 || average >= total); */
    /*@ assert (total == 0 || average > 0); */
    /*@ assert (total == (index / 2)); */
    /*@ assert (total == (index - 1) / 2 || total == index / 2); */
    /*@ assert (total == (index - 1) / 2 + ((index - 1) % 2)); */
    /*@ assert (total == (index - 1) / 2 + ((index - 1) % 2 != 0 ? 1 : 0)); */
    /*@ assert (total == (index + 1) / 2 || total == index / 2); */
    /*@ assert (total <= index); */
    /*@ assert (total <= index / 2 + 1); */
    /*@ assert (total <= index + 1); */
    /*@ assert (total <= average); */
    /*@ assert (total <= average + index); */
    /*@ assert (total <= average + 1); */
    /*@ assert (total <= average + 1 || index <= size + 1); */
    /*@ assert (total <= (index + 1) / 2); */
    /*@ assert (total <= (index + 1) / 2 || total * 2 <= index + 1); */
    /*@ assert (total <= (index + 1) / 2 || total * 2 <= average); */
    /*@ assert (total <= (index + 1) / 2 || index <= size + 1); */
    /*@ assert (total <= (index + 1) / 2 || index - total <= size); */
    /*@ assert (total <= (index + 1) / 2 || index - total <= average); */
    /*@ assert (total <= (index + 1) / 2 || 2 * total <= index + 1); */
    /*@ assert (total <= (index + 1) / 2 || 0 <= index - total); */
    /*@ assert (total < average + 1); */
    /*@ assert (total * total <= average); */
    /*@ assert (total * 2 <= index); */
    /*@ assert (total * 2 <= index || total <= average + 1); */
    /*@ assert (total * 2 <= index || index <= size + 1); */
    /*@ assert (total * 2 <= index + 1); */
    /*@ assert (total * 2 <= index + 1 || average >= total); */
    /*@ assert (total * 2 <= index + 1 || average >= index); */
    /*@ assert (total * 2 <= index + 1 || average >= 0); */
    /*@ assert (total * 2 <= index + 1 || 2 * total <= index + 1); */
    /*@ assert (total * 2 <= index + 1 || 0 <= index - total); */
    /*@ assert (total * 2 <= average || total * 2 <= index + 1); */
    /*@ assert (total * 2 <= average || index <= size + 1); */
    /*@ assert (total * 2 <= average || 2 * total <= index + 1); */
    /*@ assert (total * 2 <= average || 0 <= index - total); */
    /*@ assert (total * 2 <= average + index); */
    /*@ assert (total * 2 < index + 1); */
    /*@ assert (total % 2 == 0 || total % 2 == 1); */
    /*@ assert (index >= 1 ==> total >= 0); */
    /*@ assert (index <= size + 1 || total * 2 <= index + 1); */
    /*@ assert (index <= size + 1 || 2 * total <= index + 1); */
    /*@ assert (index <= size + 1 || 0 <= index - total); */
    /*@ assert (index - total <= size || total * 2 <= index + 1); */
    /*@ assert (index - total <= size || total * 2 <= average); */
    /*@ assert (index - total <= size || 2 * total <= index + 1); */
    /*@ assert (index - total <= size || 0 <= index - total); */
    /*@ assert (index - total <= average || total * 2 <= index + 1); */
    /*@ assert (index - total <= average || 2 * total <= index + 1); */
    /*@ assert (index - total <= average || 0 <= index - total); */
    /*@ assert (index % 2 == 1 || index % 2 == 0); */
    /*@ assert (index % 2 == 0 || index % 2 == 1); */
    /*@ assert (average >= total || total == 0); */
    /*@ assert (average >= total * total || total == 0); */
    /*@ assert (average >= total * total || average >= total); */
    /*@ assert (average >= total * total || average >= 0); */
    /*@ assert (average >= 0 && total >= 0); */
    /*@ assert (average >= 0 && total >= 0 && index >= 1); */
    /*@ assert (average == total * total); */
    /*@ assert (average == total * total || average >= total); */
    /*@ assert (average == total * total || average == total * total + index); */
    /*@ assert (average == total * total || average == 0); */
    /*@ assert (average == total * total || average <= index * (index + 1) / 2); */
    /*@ assert (average == 0 || total >= 0); */
    /*@ assert (average == 0 || total > 0); */
    /*@ assert (average == 0 || average >= total); */
    /*@ assert (average == 0 || average > 0); */
    /*@ assert (average <= index * index); */
    /*@ assert (average <= index * (index + 1) / 2); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (k % 2 == 0 || k % 2 != 0)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (k % 2 != 0 ==> total >= 1)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (k % 2 != 0 ==> average >= total)); */
    /*@ assert (\forall integer k; 1 <= k < index ==> (k % 2 != 0 ==> average >= k)); */
    /*@ assert (\forall integer k; 1 <= k < index && k % 2 != 0 ==> total >= 1); */
    /*@ assert (\forall integer k; 1 <= k < index && k % 2 != 0 ==> average >= k); */
    /*@ assert (2 * total <= index); */
    /*@ assert (2 * total <= index + 1); */
    /*@ assert (2 * total < index + 1); */
    /*@ assert (1 <= index); */
    /*@ assert (1 <= index - total); */
    /*@ assert (0 <= total); */
    /*@ assert (0 <= index); */
    /*@ assert (0 <= index - total); */
    /*@ assert (0 <= index - total || 2 * total <= index + 1); */
    /*@ assert (0 <= average); */
    /*@ assert (0 <= average - total); */
    /*@ assert (0 <= average && 0 <= total); */
    /*@ assert (0 < index - total); */
}

/*@ requires (total >= 0 && average >= 0 && index >= 1) && (total == index / 2 || total == (index - 1) / 2) && (total <= index && 0 <= total) && (index - total == (index + 1) / 2) && (average == total * total || average == index * (index - 1) / 2) && (total >= 0 && index >= 1) && (total >= 0 && average >= 0) && (total > 0 || index == 1) && (total > 0 || index <= 1) && (total == index / 2) && (total == index / 2 || total == (index + 1) / 2) && (total == 0 || total > 0) && (total == 0 || average >= total) && (total == 0 || average > 0) && (total == (index / 2)) && (total == (index - 1) / 2 || total == index / 2) && (total == (index - 1) / 2 + ((index - 1) % 2)) && (total == (index - 1) / 2 + ((index - 1) % 2 != 0 ? 1 : 0)) && (total == (index + 1) / 2 || total == index / 2) && (total <= index) && (total <= index / 2 + 1) && (total <= index + 1) && (total <= average) && (total <= average + index) && (total <= average + 1) && (total <= average + 1 || index <= size + 1) && (total <= (index + 1) / 2) && (total <= (index + 1) / 2 || total * 2 <= index + 1) && (total <= (index + 1) / 2 || total * 2 <= average) && (total <= (index + 1) / 2 || index <= size + 1) && (total <= (index + 1) / 2 || index - total <= size) && (total <= (index + 1) / 2 || index - total <= average) && (total <= (index + 1) / 2 || 2 * total <= index + 1) && (total <= (index + 1) / 2 || 0 <= index - total) && (total < average + 1) && (total * total <= average) && (total * 2 <= index) && (total * 2 <= index || total <= average + 1) && (total * 2 <= index || index <= size + 1) && (total * 2 <= index + 1) && (total * 2 <= index + 1 || average >= total) && (total * 2 <= index + 1 || average >= index) && (total * 2 <= index + 1 || average >= 0) && (total * 2 <= index + 1 || 2 * total <= index + 1) && (total * 2 <= index + 1 || 0 <= index - total) && (total * 2 <= average || total * 2 <= index + 1) && (total * 2 <= average || index <= size + 1) && (total * 2 <= average || 2 * total <= index + 1) && (total * 2 <= average || 0 <= index - total) && (total * 2 <= average + index) && (total * 2 < index + 1) && (total % 2 == 0 || total % 2 == 1) && (index >= 1 ==> total >= 0) && (index <= size + 1 || total * 2 <= index + 1) && (index <= size + 1 || 2 * total <= index + 1) && (index <= size + 1 || 0 <= index - total) && (index - total <= size || total * 2 <= index + 1) && (index - total <= size || total * 2 <= average) && (index - total <= size || 2 * total <= index + 1) && (index - total <= size || 0 <= index - total) && (index - total <= average || total * 2 <= index + 1) && (index - total <= average || 2 * total <= index + 1) && (index - total <= average || 0 <= index - total) && (index % 2 == 1 || index % 2 == 0) && (index % 2 == 0 || index % 2 == 1) && (average >= total || total == 0) && (average >= total * total || total == 0) && (average >= total * total || average >= total) && (average >= total * total || average >= 0) && (average >= 0 && total >= 0) && (average >= 0 && total >= 0 && index >= 1) && (average == total * total) && (average == total * total || average >= total) && (average == total * total || average == total * total + index) && (average == total * total || average == 0) && (average == total * total || average <= index * (index + 1) / 2) && (average == 0 || total >= 0) && (average == 0 || total > 0) && (average == 0 || average >= total) && (average == 0 || average > 0) && (average <= index * index) && (average <= index * (index + 1) / 2) && (\forall integer k; 1 <= k < index ==> (k % 2 == 0 || k % 2 != 0)) && (\forall integer k; 1 <= k < index ==> (k % 2 != 0 ==> total >= 1)) && (\forall integer k; 1 <= k < index ==> (k % 2 != 0 ==> average >= total)) && (\forall integer k; 1 <= k < index ==> (k % 2 != 0 ==> average >= k)) && (\forall integer k; 1 <= k < index && k % 2 != 0 ==> total >= 1) && (\forall integer k; 1 <= k < index && k % 2 != 0 ==> average >= k) && (2 * total <= index) && (2 * total <= index + 1) && (2 * total < index + 1) && (1 <= index) && (1 <= index - total) && (0 <= total) && (0 <= index) && (0 <= index - total) && (0 <= index - total || 2 * total <= index + 1) && (0 <= average) && (0 <= average - total) && (0 <= average && 0 <= total) && (0 < index - total);
    assigns \nothing;
*/
void check_B_implies_A(int average, int *index, int k, int size, int *total) {
    /*@ assert (1 <= index <= size + 1); */
    /*@ assert (0 <= total <= index / 2); */
    /*@ assert (0 <= average); */
    /*@ assert (average == total * total); */
    /*@ assert (total == index / 2); */
    /*@ assert ((index <= size) ==> (average == total * total)); */
    /*@ assert ((index <= size) ==> (total == index / 2)); */
    /*@ assert (size == \at(size,Pre)); */
}
