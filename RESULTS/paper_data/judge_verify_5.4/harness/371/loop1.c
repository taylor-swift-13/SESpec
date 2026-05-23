#include <limits.h>

/*@ requires (c >= 1) && (value < 1 || c <= value + 1) && (result == 0 || (1 <= result && result < c)) && (result == 0 || (result % p) == z) && (\forall integer i; 1 <= i < c && (i % p) == z ==> i <= result) && (value < 1 || (c <= value + 1 && (result == 0 || (1 <= result && result <= value))));
    assigns \nothing;
*/
void check_A_implies_B(int c, int i, int k, int p, int value, int z) {
    /*@ assert (result == 0 || 0 <= result); */
    /*@ assert (result == 0 || (\exists integer k; 1 <= k <= c && k % p == z && result == k)); */
    /*@ assert (result == 0 || (1 <= result <= value)); */
    /*@ assert (\forall integer k; 1 <= k < c && k % p == z ==> k <= result); */
    /*@ assert (result == 0 || result == value || (result % p) == z); */
    /*@ assert (result == 0 || result == value || ((result % p) == z)); */
    /*@ assert (result == 0 || result == c - 1 || result % p == z); */
    /*@ assert (result == 0 || result <= value); */
    /*@ assert (result == 0 || result <= c); */
    /*@ assert (result == 0 || result <= c - 1); */
    /*@ assert (result == 0 || result < c); */
    /*@ assert (result == 0 || result % p == z); */
    /*@ assert (result == 0 || \exists integer k; 1 <= k < c && (k % p) == z && result == k); */
    /*@ assert (result == 0 || 1 <= result <= value); */
    /*@ assert (result == 0 || (result <= c - 1)); */
    /*@ assert (result == 0 || (result % p) == z); */
    /*@ assert (result == 0 || (\exists integer k; 1 <= k <= c && (k % p) == z && result == k)); */
    /*@ assert (result == 0 || (\exists integer k; 1 <= k < c && (k % p) == z && result == k)); */
    /*@ assert (result == 0 || (1 <= result <= c - 1)); */
    /*@ assert (result == 0 || ((result % p) == z)); */
    /*@ assert (result <= c); */
    /*@ assert (result <= c || result <= value); */
    /*@ assert (result <= c - 1); */
    /*@ assert (result < c); */
    /*@ assert (result % p == z || result == 0); */
    /*@ assert (c == 1 || result == 0 || result % p == z); */
    /*@ assert (c <= value + 1 || result <= c); */
    /*@ assert (\forall integer k; 1 <= k < c ==> result >= 0); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (k % p) == z ==> k <= result); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (k % p) != z || k <= result); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (k % p == z ==> k <= result)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (k % p != z || k <= result)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> ((k % p) == z ==> k <= result)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> ((k % p) != z || k <= result)); */
    /*@ assert (\forall integer k; 1 <= k < c && (k % p) == z ==> k <= result); */
    /*@ assert (\forall integer k; 1 <= k < c && (k % p == z) ==> k <= result); */
    /*@ assert (\forall integer k; 1 <= k < c && ((k % p) == z) ==> k <= result); */
    /*@ assert (\exists integer k; 1 <= k < c && (k % p) == z ==> result == k); */
    /*@ assert (1 <= c); */
    /*@ assert (0 <= result); */
    /*@ assert (0 <= c); */
    /*@ assert (0 <= c || result <= value); */
    /*@ assert (0 <= c || c <= value + 1); */
    /*@ assert (0 <= c || c - 1 <= value); */
    /*@ assert (0 < c); */
}

/*@ requires (result == 0 || 0 <= result) && (result == 0 || (\exists integer k; 1 <= k <= c && k % p == z && result == k)) && (result == 0 || (1 <= result <= value)) && (\forall integer k; 1 <= k < c && k % p == z ==> k <= result) && (result == 0 || result == value || (result % p) == z) && (result == 0 || result == value || ((result % p) == z)) && (result == 0 || result == c - 1 || result % p == z) && (result == 0 || result <= value) && (result == 0 || result <= c) && (result == 0 || result <= c - 1) && (result == 0 || result < c) && (result == 0 || result % p == z) && (result == 0 || \exists integer k; 1 <= k < c && (k % p) == z && result == k) && (result == 0 || 1 <= result <= value) && (result == 0 || (result <= c - 1)) && (result == 0 || (result % p) == z) && (result == 0 || (\exists integer k; 1 <= k <= c && (k % p) == z && result == k)) && (result == 0 || (\exists integer k; 1 <= k < c && (k % p) == z && result == k)) && (result == 0 || (1 <= result <= c - 1)) && (result == 0 || ((result % p) == z)) && (result <= c) && (result <= c || result <= value) && (result <= c - 1) && (result < c) && (result % p == z || result == 0) && (c == 1 || result == 0 || result % p == z) && (c <= value + 1 || result <= c) && (\forall integer k; 1 <= k < c ==> result >= 0) && (\forall integer k; 1 <= k < c ==> (k % p) == z ==> k <= result) && (\forall integer k; 1 <= k < c ==> (k % p) != z || k <= result) && (\forall integer k; 1 <= k < c ==> (k % p == z ==> k <= result)) && (\forall integer k; 1 <= k < c ==> (k % p != z || k <= result)) && (\forall integer k; 1 <= k < c ==> ((k % p) == z ==> k <= result)) && (\forall integer k; 1 <= k < c ==> ((k % p) != z || k <= result)) && (\forall integer k; 1 <= k < c && (k % p) == z ==> k <= result) && (\forall integer k; 1 <= k < c && (k % p == z) ==> k <= result) && (\forall integer k; 1 <= k < c && ((k % p) == z) ==> k <= result) && (\exists integer k; 1 <= k < c && (k % p) == z ==> result == k) && (1 <= c) && (0 <= result) && (0 <= c) && (0 <= c || result <= value) && (0 <= c || c <= value + 1) && (0 <= c || c - 1 <= value) && (0 < c);
    assigns \nothing;
*/
void check_B_implies_A(int c, int i, int k, int p, int value, int z) {
    /*@ assert (c >= 1); */
    /*@ assert (value < 1 || c <= value + 1); */
    /*@ assert (result == 0 || (1 <= result && result < c)); */
    /*@ assert (result == 0 || (result % p) == z); */
    /*@ assert (\forall integer i; 1 <= i < c && (i % p) == z ==> i <= result); */
    /*@ assert (value < 1 || (c <= value + 1 && (result == 0 || (1 <= result && result <= value)))); */
}
