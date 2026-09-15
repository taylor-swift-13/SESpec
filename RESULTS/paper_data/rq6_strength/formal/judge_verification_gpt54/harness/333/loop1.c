#include <limits.h>

/*@ logic integer tenprod(integer n, integer c) =
    n >= c ? 1 : ((n % 10) * tenprod(n + 1, c)) % 10; */

/*@ requires (n == \at(n,Pre)) && (c == \at(c,Pre)) && (n < c ==> n + 1 <= var && var <= c + 1) && (c < n ==> var == n + 1);
    assigns \nothing;
*/
void check_A_implies_B(int c, int k, int n, int var) {
    /*@ assert (var <= c + 1 || result == 1); */
    /*@ assert (var > n ==> result == result % 10); */
    /*@ assert (var > n ==> result <= 9); */
    /*@ assert (var > n ==> result < 10); */
    /*@ assert (var == n + 1 || var > n); */
    /*@ assert (var == n + 1 ==> result == 1); */
    /*@ assert (var == n + 1 + (var - (n + 1))); */
    /*@ assert (var <= c + 1 || 1 <= result); */
    /*@ assert (var <= c + 1 || 0 <= result); */
    /*@ assert (var <= c + 1 ==> result == result % 10); */
    /*@ assert (var <= c + 1 ==> result <= 9); */
    /*@ assert (var <= c + 1 ==> result < 10); */
    /*@ assert (var - (n + 1) <= c - n || 1 <= result); */
    /*@ assert (var - (n + 1) <= c - n || 0 <= result); */
    /*@ assert (result == result % 10); */
    /*@ assert (result == 1 || var > n); */
    /*@ assert (result == 1 || result < 10); */
    /*@ assert (result == 1 || n + 1 <= var); */
    /*@ assert (result == (result % 10)); */
    /*@ assert (result == ((result % 10))); */
    /*@ assert (result == ((n + 1 <= var) ? result : 1)); */
    /*@ assert (result <= 9); */
    /*@ assert (result < 10); */
    /*@ assert (result % 10 == result); */
    /*@ assert (result != 0 ==> result < 10); */
    /*@ assert (n <= var); */
    /*@ assert (n < var); */
    /*@ assert (n < var || var <= c + 1); */
    /*@ assert (n < var || var - (n + 1) <= c - n); */
    /*@ assert (n < var || result == 1); */
    /*@ assert (n < var || 1 <= result); */
    /*@ assert (n < var || 0 <= result); */
    /*@ assert (n + 1 <= var); */
    /*@ assert (\forall integer k; n + 1 <= k < var ==> result == result % 10); */
    /*@ assert (\forall integer k; n + 1 <= k < var ==> result == (result % 10)); */
    /*@ assert (\forall integer k; n + 1 <= k < var ==> result <= 9); */
    /*@ assert (\forall integer k; n + 1 <= k < var ==> result < 10); */
    /*@ assert (\forall integer k; n + 1 <= k < var ==> (k % 10) != 0 ==> result % 10 == result); */
    /*@ assert (\exists integer k; n + 1 <= k <= var ==> result == (k % 10) % 10); */
    /*@ assert (1 <= result || var > n); */
    /*@ assert (1 <= result || var <= c + 1); */
    /*@ assert (0 <= var - (n + 1)); */
    /*@ assert (0 <= var - (n + 1) || var <= c); */
    /*@ assert (0 <= var - (n + 1) || var <= c + 1); */
    /*@ assert (0 <= var - (n + 1) || result == 1); */
    /*@ assert (0 <= var - (n + 1) || 1 <= result); */
    /*@ assert (0 <= result || var <= c + 1); */
    /*@ assert (0 <= result || 0 <= var - (n + 1)); */
    /*@ assert ((var == n + 1) || (var > n)); */
    /*@ assert ((var == n + 1) ==> result == 1); */
}

/*@ requires (var <= c + 1 || result == 1) && (var > n ==> result == result % 10) && (var > n ==> result <= 9) && (var > n ==> result < 10) && (var == n + 1 || var > n) && (var == n + 1 ==> result == 1) && (var == n + 1 + (var - (n + 1))) && (var <= c + 1 || 1 <= result) && (var <= c + 1 || 0 <= result) && (var <= c + 1 ==> result == result % 10) && (var <= c + 1 ==> result <= 9) && (var <= c + 1 ==> result < 10) && (var - (n + 1) <= c - n || 1 <= result) && (var - (n + 1) <= c - n || 0 <= result) && (result == result % 10) && (result == 1 || var > n) && (result == 1 || result < 10) && (result == 1 || n + 1 <= var) && (result == (result % 10)) && (result == ((result % 10))) && (result == ((n + 1 <= var) ? result : 1)) && (result <= 9) && (result < 10) && (result % 10 == result) && (result != 0 ==> result < 10) && (n <= var) && (n < var) && (n < var || var <= c + 1) && (n < var || var - (n + 1) <= c - n) && (n < var || result == 1) && (n < var || 1 <= result) && (n < var || 0 <= result) && (n + 1 <= var) && (\forall integer k; n + 1 <= k < var ==> result == result % 10) && (\forall integer k; n + 1 <= k < var ==> result == (result % 10)) && (\forall integer k; n + 1 <= k < var ==> result <= 9) && (\forall integer k; n + 1 <= k < var ==> result < 10) && (\forall integer k; n + 1 <= k < var ==> (k % 10) != 0 ==> result % 10 == result) && (\exists integer k; n + 1 <= k <= var ==> result == (k % 10) % 10) && (1 <= result || var > n) && (1 <= result || var <= c + 1) && (0 <= var - (n + 1)) && (0 <= var - (n + 1) || var <= c) && (0 <= var - (n + 1) || var <= c + 1) && (0 <= var - (n + 1) || result == 1) && (0 <= var - (n + 1) || 1 <= result) && (0 <= result || var <= c + 1) && (0 <= result || 0 <= var - (n + 1)) && ((var == n + 1) || (var > n)) && ((var == n + 1) ==> result == 1);
    assigns \nothing;
*/
void check_B_implies_A(int c, int k, int n, int var) {
    /*@ assert (n == \at(n,Pre)); */
    /*@ assert (c == \at(c,Pre)); */
    /*@ assert (n < c ==> n + 1 <= var && var <= c + 1); */
    /*@ assert (c < n ==> var == n + 1); */
}
