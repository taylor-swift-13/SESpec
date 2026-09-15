#include <limits.h>

/*@ logic integer factorial(integer x) =
    x <= 1 ? 1 : x * factorial(x - 1); */

/*@ requires (2 <= i <= n + 1) && (fact == factorial(i - 1)) && (fact >= 1) && ((i <= n) ==> fact > 0) && ((i > n) ==> fact == factorial(n)) && (n == \at(n,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int fact, int firstDigit, int i, int k, int n) {
    /*@ assert (i - 1 <= fact); */
    /*@ assert (fact >= 0 ==> 0 <= fact % 10); */
    /*@ assert (fact > 0 || fact == 0); */
    /*@ assert (fact > 0 ==> fact >= 1); */
    /*@ assert (fact == 1 || fact >= 1); */
    /*@ assert (fact == 1 || fact > 1); */
    /*@ assert (fact == 1 || fact > 0); */
    /*@ assert (fact == 0 || fact >= 1); */
    /*@ assert (fact == 0 || fact > 0); */
    /*@ assert (fact == 0 ==> firstDigit == 0); */
    /*@ assert (fact / 10 <= fact); */
    /*@ assert (fact % 2 == 0 || fact % 2 == 1); */
    /*@ assert (fact % 10 == fact - 10 * (fact / 10)); */
    /*@ assert (fact % 10 <= 9); */
    /*@ assert (fact % 10 <= 9 || i <= n + 1); */
    /*@ assert (fact % 10 <= 9 || 0 <= fact % 10); */
    /*@ assert (fact % 1 == 0); */
    /*@ assert (\forall integer k; 2 <= k < i ==> fact >= k); */
    /*@ assert (\forall integer k; 0 <= k < i ==> fact >= k); */
    /*@ assert (\forall integer k; 0 <= k < i ==> fact >= 1); */
    /*@ assert (\forall integer k; 0 <= k < i ==> fact % 10 <= 9); */
    /*@ assert (2 <= i); */
    /*@ assert (1 <= i); */
    /*@ assert (1 <= fact); */
    /*@ assert (1 <= fact || fact == 0); */
    /*@ assert (0 <= i); */
    /*@ assert (0 <= fact); */
    /*@ assert (0 <= fact && fact % 10 <= 9); */
    /*@ assert (0 <= fact % 10); */
    /*@ assert (0 <= fact % 10 || i <= n + 1); */
    /*@ assert (0 < fact); */
}

/*@ requires (i - 1 <= fact) && (fact >= 0 ==> 0 <= fact % 10) && (fact > 0 || fact == 0) && (fact > 0 ==> fact >= 1) && (fact == 1 || fact >= 1) && (fact == 1 || fact > 1) && (fact == 1 || fact > 0) && (fact == 0 || fact >= 1) && (fact == 0 || fact > 0) && (fact == 0 ==> firstDigit == 0) && (fact / 10 <= fact) && (fact % 2 == 0 || fact % 2 == 1) && (fact % 10 == fact - 10 * (fact / 10)) && (fact % 10 <= 9) && (fact % 10 <= 9 || i <= n + 1) && (fact % 10 <= 9 || 0 <= fact % 10) && (fact % 1 == 0) && (\forall integer k; 2 <= k < i ==> fact >= k) && (\forall integer k; 0 <= k < i ==> fact >= k) && (\forall integer k; 0 <= k < i ==> fact >= 1) && (\forall integer k; 0 <= k < i ==> fact % 10 <= 9) && (2 <= i) && (1 <= i) && (1 <= fact) && (1 <= fact || fact == 0) && (0 <= i) && (0 <= fact) && (0 <= fact && fact % 10 <= 9) && (0 <= fact % 10) && (0 <= fact % 10 || i <= n + 1) && (0 < fact);
    assigns \nothing;
*/
void check_B_implies_A(int fact, int firstDigit, int i, int k, int n) {
    /*@ assert (2 <= i <= n + 1); */
    /*@ assert (fact == factorial(i - 1)); */
    /*@ assert (fact >= 1); */
    /*@ assert ((i <= n) ==> fact > 0); */
    /*@ assert ((i > n) ==> fact == factorial(n)); */
    /*@ assert (n == \at(n,Pre)); */
}
