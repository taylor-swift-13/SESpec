#include <limits.h>

/*@ requires (1 <= c) && (0 <= result) && (result == 0 || (1 <= result && result < c)) && (result == 0 || result % p == dy) && (result == 0 || (\forall integer k; 1 <= k < c ==> k % p != dy || k <= result)) && ((\exists integer k; 1 <= k < c && k % p == dy) ==> result != 0) && ((\exists integer k; 1 <= k < c && k % p == dy) ==> result % p == dy) && (dy == \at(dy,Pre)) && (p == \at(p,Pre)) && (value == \at(value,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int c, int dy, int k, int p, int value) {
    /*@ assert (\forall integer k; 1 <= k < c ==> (k % p) == dy ==> (result == 0 || k <= result)); */
    /*@ assert (result == 0 || result >= 1); */
    /*@ assert (result == 0 || result <= value); */
    /*@ assert (result == 0 || result <= c); */
    /*@ assert (result == 0 || result <= c - 1); */
    /*@ assert (result == 0 || result < c); */
    /*@ assert (result == 0 || result < c + 1); */
    /*@ assert (result == 0 || result % p == dy); */
    /*@ assert (result == 0 || \exists integer k; 1 <= k <= value && (k % p) == dy && result == k); */
    /*@ assert (result == 0 || \exists integer k; 1 <= k <= c-1 && (k % p) == dy && result == k); */
    /*@ assert (result == 0 || \exists integer k; 1 <= k <= c && (k % p) == dy && result == k); */
    /*@ assert (result == 0 || \exists integer k; 1 <= k < c && (k % p) == dy && result == k); */
    /*@ assert (result == 0 || 1 <= result); */
    /*@ assert (result == 0 || 1 <= result <= value); */
    /*@ assert (result == 0 || 1 <= result <= c); */
    /*@ assert (result == 0 || 1 <= result <= c - 1); */
    /*@ assert (result == 0 || 1 <= result < c); */
    /*@ assert (result == 0 || (result % p) == dy); */
    /*@ assert (result == 0 || (result % p) == dy && result <= c); */
    /*@ assert (result == 0 || (\forall integer k; 1 <= k < c ==> (k % p) == dy ==> k <= result)); */
    /*@ assert (result == 0 || (\forall integer k; 1 <= k < c ==> (k % p) != dy || k <= result)); */
    /*@ assert (result == 0 || (\forall integer k; 1 <= k < c ==> ((k % p) == dy ==> k <= result))); */
    /*@ assert (result == 0 || (\forall integer k; 1 <= k < c && (k % p) == dy ==> k <= result)); */
    /*@ assert (result == 0 || (\exists integer k; 1 <= k <= value && (k % p) == dy && result == k)); */
    /*@ assert (result == 0 || (\exists integer k; 1 <= k <= c-1 && (k % p) == dy && result == k)); */
    /*@ assert (result == 0 || (\exists integer k; 1 <= k <= c && (k % p) == dy && result == k)); */
    /*@ assert (result == 0 || (\exists integer k; 1 <= k < c && (k % p) == dy && result == k)); */
    /*@ assert (result == 0 || (1 <= result <= value)); */
    /*@ assert (result == 0 || (1 <= result <= c - 1)); */
    /*@ assert (result == 0 || (1 <= result <= c - 1 && (result % p) == dy)); */
    /*@ assert (result == 0 || (1 <= result < c)); */
    /*@ assert (result == 0 || (1 <= result && result <= c-1)); */
    /*@ assert (result == 0 || (1 <= result && result <= c)); */
    /*@ assert (result == 0 || (1 <= result && result <= c - 1)); */
    /*@ assert (result == 0 || (1 <= result && result < c)); */
    /*@ assert (result == 0 || ((result % p) == dy)); */
    /*@ assert (result <= c); */
    /*@ assert (result <= c || result == 0); */
    /*@ assert (result <= c || result <= value); */
    /*@ assert (result <= c || result <= c - 1); */
    /*@ assert (result <= c - 1); */
    /*@ assert (result <= c - 1 || result == 0); */
    /*@ assert (result <= c - 1 || result <= value); */
    /*@ assert (result < c); */
    /*@ assert (c == value + 1 || result == 0 || result < c); */
    /*@ assert (c == value + 1 || result <= c); */
    /*@ assert (c == 1 || result == 0 || result < c); */
    /*@ assert (c <= value + 1 || result <= c); */
    /*@ assert (c <= value + 1 || result <= c - 1); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (k % p) == dy ==> result >= k); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (k % p) == dy ==> result == 0 || result >= k); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (k % p) == dy ==> k <= result); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (k % p) != dy || k <= result); */
    /*@ assert (\forall integer k; 1 <= k < c ==> ((k % p) == dy ==> k <= result)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> ((k % p) != dy || k <= result)); */
    /*@ assert (\forall integer k; 1 <= k < c && (k % p) == dy ==> result >= k); */
    /*@ assert (\forall integer k; 1 <= k < c && (k % p) == dy ==> result == 0 || result >= k); */
    /*@ assert (\forall integer k; 1 <= k < c && (k % p) == dy ==> result == 0 || k <= result); */
    /*@ assert (\forall integer k; 1 <= k < c && (k % p) == dy ==> result % p == dy); */
    /*@ assert (\forall integer k; 1 <= k < c && (k % p) == dy ==> k <= result); */
    /*@ assert (\forall integer k; 1 <= k < c && (k % p) == dy ==> (result == 0 || result >= k)); */
    /*@ assert (\forall integer k; 1 <= k < c && (k % p) != dy ==> result != k); */
    /*@ assert (\forall integer k; 1 <= k < c && (k % p == dy) ==> k <= result); */
    /*@ assert (\forall integer k; 1 <= k < c && ((k % p) == dy) ==> k <= result); */
    /*@ assert (\exists integer k; 1 <= k < c && (k % p) == dy && result == k || result == 0); */
    /*@ assert (\exists integer k; 0 <= k <= c && (k == result || result == 0)); */
    /*@ assert (\exists integer k; 0 <= k < c && result == k && (k == 0 || k % p == dy)); */
    /*@ assert (\exists integer k; 0 <= k < c && result == k && (k == 0 || (k % p) == dy)); */
    /*@ assert (\exists integer k; 0 <= k < c && k == result && (k == 0 || k % p == dy)); */
    /*@ assert (\exists integer k; 0 <= k < c && (result == k || result == 0)); */
    /*@ assert (\exists integer k; 0 <= k < c && (result == 0 || (k == result && (k % p) == dy))); */
    /*@ assert (\exists integer k; 0 <= k < c && (k == result || result == 0)); */
    /*@ assert (1 <= c); */
    /*@ assert (0 <= result); */
    /*@ assert (0 <= c); */
    /*@ assert ((\forall integer k; 1 <= k < c ==> (k % p) == dy ==> k <= result) || result == 0); */
}

/*@ requires (\forall integer k; 1 <= k < c ==> (k % p) == dy ==> (result == 0 || k <= result)) && (result == 0 || result >= 1) && (result == 0 || result <= value) && (result == 0 || result <= c) && (result == 0 || result <= c - 1) && (result == 0 || result < c) && (result == 0 || result < c + 1) && (result == 0 || result % p == dy) && (result == 0 || \exists integer k; 1 <= k <= value && (k % p) == dy && result == k) && (result == 0 || \exists integer k; 1 <= k <= c-1 && (k % p) == dy && result == k) && (result == 0 || \exists integer k; 1 <= k <= c && (k % p) == dy && result == k) && (result == 0 || \exists integer k; 1 <= k < c && (k % p) == dy && result == k) && (result == 0 || 1 <= result) && (result == 0 || 1 <= result <= value) && (result == 0 || 1 <= result <= c) && (result == 0 || 1 <= result <= c - 1) && (result == 0 || 1 <= result < c) && (result == 0 || (result % p) == dy) && (result == 0 || (result % p) == dy && result <= c) && (result == 0 || (\forall integer k; 1 <= k < c ==> (k % p) == dy ==> k <= result)) && (result == 0 || (\forall integer k; 1 <= k < c ==> (k % p) != dy || k <= result)) && (result == 0 || (\forall integer k; 1 <= k < c ==> ((k % p) == dy ==> k <= result))) && (result == 0 || (\forall integer k; 1 <= k < c && (k % p) == dy ==> k <= result)) && (result == 0 || (\exists integer k; 1 <= k <= value && (k % p) == dy && result == k)) && (result == 0 || (\exists integer k; 1 <= k <= c-1 && (k % p) == dy && result == k)) && (result == 0 || (\exists integer k; 1 <= k <= c && (k % p) == dy && result == k)) && (result == 0 || (\exists integer k; 1 <= k < c && (k % p) == dy && result == k)) && (result == 0 || (1 <= result <= value)) && (result == 0 || (1 <= result <= c - 1)) && (result == 0 || (1 <= result <= c - 1 && (result % p) == dy)) && (result == 0 || (1 <= result < c)) && (result == 0 || (1 <= result && result <= c-1)) && (result == 0 || (1 <= result && result <= c)) && (result == 0 || (1 <= result && result <= c - 1)) && (result == 0 || (1 <= result && result < c)) && (result == 0 || ((result % p) == dy)) && (result <= c) && (result <= c || result == 0) && (result <= c || result <= value) && (result <= c || result <= c - 1) && (result <= c - 1) && (result <= c - 1 || result == 0) && (result <= c - 1 || result <= value) && (result < c) && (c == value + 1 || result == 0 || result < c) && (c == value + 1 || result <= c) && (c == 1 || result == 0 || result < c) && (c <= value + 1 || result <= c) && (c <= value + 1 || result <= c - 1) && (\forall integer k; 1 <= k < c ==> (k % p) == dy ==> result >= k) && (\forall integer k; 1 <= k < c ==> (k % p) == dy ==> result == 0 || result >= k) && (\forall integer k; 1 <= k < c ==> (k % p) == dy ==> k <= result) && (\forall integer k; 1 <= k < c ==> (k % p) != dy || k <= result) && (\forall integer k; 1 <= k < c ==> ((k % p) == dy ==> k <= result)) && (\forall integer k; 1 <= k < c ==> ((k % p) != dy || k <= result)) && (\forall integer k; 1 <= k < c && (k % p) == dy ==> result >= k) && (\forall integer k; 1 <= k < c && (k % p) == dy ==> result == 0 || result >= k) && (\forall integer k; 1 <= k < c && (k % p) == dy ==> result == 0 || k <= result) && (\forall integer k; 1 <= k < c && (k % p) == dy ==> result % p == dy) && (\forall integer k; 1 <= k < c && (k % p) == dy ==> k <= result) && (\forall integer k; 1 <= k < c && (k % p) == dy ==> (result == 0 || result >= k)) && (\forall integer k; 1 <= k < c && (k % p) != dy ==> result != k) && (\forall integer k; 1 <= k < c && (k % p == dy) ==> k <= result) && (\forall integer k; 1 <= k < c && ((k % p) == dy) ==> k <= result) && (\exists integer k; 1 <= k < c && (k % p) == dy && result == k || result == 0) && (\exists integer k; 0 <= k <= c && (k == result || result == 0)) && (\exists integer k; 0 <= k < c && result == k && (k == 0 || k % p == dy)) && (\exists integer k; 0 <= k < c && result == k && (k == 0 || (k % p) == dy)) && (\exists integer k; 0 <= k < c && k == result && (k == 0 || k % p == dy)) && (\exists integer k; 0 <= k < c && (result == k || result == 0)) && (\exists integer k; 0 <= k < c && (result == 0 || (k == result && (k % p) == dy))) && (\exists integer k; 0 <= k < c && (k == result || result == 0)) && (1 <= c) && (0 <= result) && (0 <= c) && ((\forall integer k; 1 <= k < c ==> (k % p) == dy ==> k <= result) || result == 0);
    assigns \nothing;
*/
void check_B_implies_A(int c, int dy, int k, int p, int value) {
    /*@ assert (1 <= c); */
    /*@ assert (0 <= result); */
    /*@ assert (result == 0 || (1 <= result && result < c)); */
    /*@ assert (result == 0 || result % p == dy); */
    /*@ assert (result == 0 || (\forall integer k; 1 <= k < c ==> k % p != dy || k <= result)); */
    /*@ assert ((\exists integer k; 1 <= k < c && k % p == dy) ==> result != 0); */
    /*@ assert ((\exists integer k; 1 <= k < c && k % p == dy) ==> result % p == dy); */
    /*@ assert (dy == \at(dy,Pre)); */
    /*@ assert (p == \at(p,Pre)); */
    /*@ assert (value == \at(value,Pre)); */
}
