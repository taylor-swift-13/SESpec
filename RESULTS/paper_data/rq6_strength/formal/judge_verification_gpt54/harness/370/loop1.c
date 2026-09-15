#include <limits.h>

/*@ requires (result == 0 || (result <= value && (result % k) == z)) && (z == \at(z,Pre)) && (k == \at(k,Pre)) && (value == \at(value,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int c, int k, int t, int value, int z) {
    /*@ assert (result == 0 || result >= 1); */
    /*@ assert (result == 0 || result <= value); */
    /*@ assert (result == 0 || result <= value + 1); */
    /*@ assert (result == 0 || result <= c); */
    /*@ assert (result == 0 || result <= c - 1); */
    /*@ assert (result == 0 || result < c); */
    /*@ assert (result == 0 || result % k == z); */
    /*@ assert (result == 0 || \forall integer t; 1 <= t < c ==> ((t % k) == z ==> t <= result)); */
    /*@ assert (result == 0 || \forall integer t; 1 <= t < c ==> ((t % k) != z || t <= result)); */
    /*@ assert (result == 0 || \exists integer t; 1 <= t <= c && (t % k) == z && result == t); */
    /*@ assert (result == 0 || \exists integer t; 1 <= t < c && (t % k) == z && result == t); */
    /*@ assert (result == 0 || 1 <= result); */
    /*@ assert (result == 0 || 1 <= result <= value); */
    /*@ assert (result == 0 || 1 <= result <= c); */
    /*@ assert (result == 0 || 1 <= result <= c - 1); */
    /*@ assert (result == 0 || (result <= value && result >= 1)); */
    /*@ assert (result == 0 || (result % k) == z); */
    /*@ assert (result == 0 || (\exists integer t; 1 <= t <= c && (t % k) == z && result == t)); */
    /*@ assert (result == 0 || (\exists integer t; 1 <= t < c && (t % k) == z && result == t)); */
    /*@ assert (result == 0 || (1 <= result <= c)); */
    /*@ assert (result == 0 || (1 <= result && result <= value)); */
    /*@ assert (result == 0 || (1 <= result && result <= c)); */
    /*@ assert (result == 0 || (1 <= result && result <= c - 1)); */
    /*@ assert (result == 0 || (1 <= result && result < c)); */
    /*@ assert (result == 0 || ((result % k) == z)); */
    /*@ assert (result <= value || 0 <= c); */
    /*@ assert (result <= c); */
    /*@ assert (result <= c - 1); */
    /*@ assert (result <= c + 1); */
    /*@ assert (result % k == z || result == 0); */
    /*@ assert (c <= value + 1 || 0 <= c); */
    /*@ assert (\forall integer t; 1 <= t < c ==> (t % k) == z ==> t <= result); */
    /*@ assert (\forall integer t; 1 <= t < c ==> (t % k) != z || t <= result); */
    /*@ assert (\forall integer t; 1 <= t < c ==> ((t % k) == z ==> t <= result)); */
    /*@ assert (\forall integer t; 1 <= t < c ==> ((t % k) != z || t <= result)); */
    /*@ assert (\forall integer t; 1 <= t < c && (t % k) == z ==> t <= result); */
    /*@ assert (\forall integer t; 1 <= t < c && ((t % k) == z) ==> t <= result); */
    /*@ assert (\exists integer t; 1 <= t <= c && (t % k) == z ==> result == t); */
    /*@ assert (\exists integer t; 1 <= t < c && (t % k) == z ==> result >= t); */
    /*@ assert (\exists integer t; 1 <= t < c && (t % k) == z ==> result == t); */
    /*@ assert (1 <= c); */
    /*@ assert (0 <= result); */
    /*@ assert (0 <= c); */
    /*@ assert (0 < c); */
}

/*@ requires (result == 0 || result >= 1) && (result == 0 || result <= value) && (result == 0 || result <= value + 1) && (result == 0 || result <= c) && (result == 0 || result <= c - 1) && (result == 0 || result < c) && (result == 0 || result % k == z) && (result == 0 || \forall integer t; 1 <= t < c ==> ((t % k) == z ==> t <= result)) && (result == 0 || \forall integer t; 1 <= t < c ==> ((t % k) != z || t <= result)) && (result == 0 || \exists integer t; 1 <= t <= c && (t % k) == z && result == t) && (result == 0 || \exists integer t; 1 <= t < c && (t % k) == z && result == t) && (result == 0 || 1 <= result) && (result == 0 || 1 <= result <= value) && (result == 0 || 1 <= result <= c) && (result == 0 || 1 <= result <= c - 1) && (result == 0 || (result <= value && result >= 1)) && (result == 0 || (result % k) == z) && (result == 0 || (\exists integer t; 1 <= t <= c && (t % k) == z && result == t)) && (result == 0 || (\exists integer t; 1 <= t < c && (t % k) == z && result == t)) && (result == 0 || (1 <= result <= c)) && (result == 0 || (1 <= result && result <= value)) && (result == 0 || (1 <= result && result <= c)) && (result == 0 || (1 <= result && result <= c - 1)) && (result == 0 || (1 <= result && result < c)) && (result == 0 || ((result % k) == z)) && (result <= value || 0 <= c) && (result <= c) && (result <= c - 1) && (result <= c + 1) && (result % k == z || result == 0) && (c <= value + 1 || 0 <= c) && (\forall integer t; 1 <= t < c ==> (t % k) == z ==> t <= result) && (\forall integer t; 1 <= t < c ==> (t % k) != z || t <= result) && (\forall integer t; 1 <= t < c ==> ((t % k) == z ==> t <= result)) && (\forall integer t; 1 <= t < c ==> ((t % k) != z || t <= result)) && (\forall integer t; 1 <= t < c && (t % k) == z ==> t <= result) && (\forall integer t; 1 <= t < c && ((t % k) == z) ==> t <= result) && (\exists integer t; 1 <= t <= c && (t % k) == z ==> result == t) && (\exists integer t; 1 <= t < c && (t % k) == z ==> result >= t) && (\exists integer t; 1 <= t < c && (t % k) == z ==> result == t) && (1 <= c) && (0 <= result) && (0 <= c) && (0 < c);
    assigns \nothing;
*/
void check_B_implies_A(int c, int k, int t, int value, int z) {
    /*@ assert (result == 0 || (result <= value && (result % k) == z)); */
    /*@ assert (z == \at(z,Pre)); */
    /*@ assert (k == \at(k,Pre)); */
    /*@ assert (value == \at(value,Pre)); */
}
