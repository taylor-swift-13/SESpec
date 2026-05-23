#include <limits.h>

/*@ logic integer prod10(integer a, integer b) =
      b < a ? 1 : (prod10(a, b - 1) * (b % 10)) % 10; */

/*@ requires (c == \at(c,Pre)) && (num == \at(num,Pre)) && (var == num + 1 || (num + 1 <= var <= c + 1)) && ((var <= c) ==> (num + 1 <= var <= c + 1)) && (loop_assigns: \true);
    assigns \nothing;
*/
void check_A_implies_B(int c, int k, int loop_assigns, int num, int var) {
    /*@ assert (var == num + 1 ==> result == 1); */
    /*@ assert (var <= c + 1 || result == 1); */
    /*@ assert (var <= c + 1 || 0 <= result); */
    /*@ assert (var <= c + 1 ==> result == result % 10); */
    /*@ assert (var <= c + 1 ==> result <= 9); */
    /*@ assert (var <= c + 1 ==> result < 10); */
    /*@ assert (var <= c + 1 ==> result % 10 == result); */
    /*@ assert (result == result % 10); */
    /*@ assert (result == 1 || result == 0 || result <= 9); */
    /*@ assert (result == 1 || result == 0 || result < 10); */
    /*@ assert (result == 1 || result <= 9); */
    /*@ assert (result == 1 || result < 10); */
    /*@ assert (result == 0 || result == 1 || result <= 9); */
    /*@ assert (result == 0 || result == 1 || result < 10); */
    /*@ assert (result == 0 || result <= 9); */
    /*@ assert (result == 0 || result < 10); */
    /*@ assert (result == (result % 10)); */
    /*@ assert (result == ((result % 10))); */
    /*@ assert (result <= 9); */
    /*@ assert (result < 10); */
    /*@ assert (result % 10 == result); */
    /*@ assert (num <= var); */
    /*@ assert (num < var); */
    /*@ assert (num < var || var <= c + 1); */
    /*@ assert (num < var || result == 1); */
    /*@ assert (num < var || result < 10); */
    /*@ assert (num < var || 1 <= result); */
    /*@ assert (num < var || 0 <= var); */
    /*@ assert (num < var || 0 <= result); */
    /*@ assert (num < var ==> result <= 9); */
    /*@ assert (num < var ==> result < 10); */
    /*@ assert (num < var ==> result % 10 == result); */
    /*@ assert (num + 1 <= var); */
    /*@ assert (\forall integer k; num + 1 <= k < var ==> result <= 9); */
    /*@ assert (\forall integer k; num + 1 <= k < var ==> result < 10); */
    /*@ assert (\forall integer k; num + 1 <= k < var ==> result % 10 == result); */
    /*@ assert (\forall integer k; num + 1 <= k < var ==> k <= c); */
    /*@ assert (\forall integer k; num + 1 <= k < var ==> k < c + 1); */
    /*@ assert (\forall integer k; num + 1 <= k < var ==> 0 <= k - num); */
    /*@ assert (1 <= var - num); */
    /*@ assert (1 <= var - num || var == num + 1); */
    /*@ assert (1 <= result || var > num + 1); */
    /*@ assert (1 <= result || var <= c + 1); */
    /*@ assert (0 <= var - num); */
    /*@ assert (0 <= var - (num + 1)); */
    /*@ assert (0 <= result || var <= c + 1); */
}

/*@ requires (var == num + 1 ==> result == 1) && (var <= c + 1 || result == 1) && (var <= c + 1 || 0 <= result) && (var <= c + 1 ==> result == result % 10) && (var <= c + 1 ==> result <= 9) && (var <= c + 1 ==> result < 10) && (var <= c + 1 ==> result % 10 == result) && (result == result % 10) && (result == 1 || result == 0 || result <= 9) && (result == 1 || result == 0 || result < 10) && (result == 1 || result <= 9) && (result == 1 || result < 10) && (result == 0 || result == 1 || result <= 9) && (result == 0 || result == 1 || result < 10) && (result == 0 || result <= 9) && (result == 0 || result < 10) && (result == (result % 10)) && (result == ((result % 10))) && (result <= 9) && (result < 10) && (result % 10 == result) && (num <= var) && (num < var) && (num < var || var <= c + 1) && (num < var || result == 1) && (num < var || result < 10) && (num < var || 1 <= result) && (num < var || 0 <= var) && (num < var || 0 <= result) && (num < var ==> result <= 9) && (num < var ==> result < 10) && (num < var ==> result % 10 == result) && (num + 1 <= var) && (\forall integer k; num + 1 <= k < var ==> result <= 9) && (\forall integer k; num + 1 <= k < var ==> result < 10) && (\forall integer k; num + 1 <= k < var ==> result % 10 == result) && (\forall integer k; num + 1 <= k < var ==> k <= c) && (\forall integer k; num + 1 <= k < var ==> k < c + 1) && (\forall integer k; num + 1 <= k < var ==> 0 <= k - num) && (1 <= var - num) && (1 <= var - num || var == num + 1) && (1 <= result || var > num + 1) && (1 <= result || var <= c + 1) && (0 <= var - num) && (0 <= var - (num + 1)) && (0 <= result || var <= c + 1);
    assigns \nothing;
*/
void check_B_implies_A(int c, int k, int loop_assigns, int num, int var) {
    /*@ assert (c == \at(c,Pre)); */
    /*@ assert (num == \at(num,Pre)); */
    /*@ assert (var == num + 1 || (num + 1 <= var <= c + 1)); */
    /*@ assert ((var <= c) ==> (num + 1 <= var <= c + 1)); */
    /*@ assert (loop_assigns: \true); */
}
