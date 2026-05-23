#include <limits.h>

/*@ logic integer ipow(integer x, integer n) =
      n <= 0 ? 1 : x * ipow(x, n - 1); */

/*@ requires (0 <= i <= n) && (res == ipow(x, i));
    assigns \nothing;
*/
void check_A_implies_B(int i, int n, int res, int x) {
    /*@ assert (x == x); */
    /*@ assert (x == 1 ==> res == 1); */
    /*@ assert (x == 0 || res != 0); */
    /*@ assert (x == 0 ==> res == 0 || i == 0); */
    /*@ assert (x == 0 ==> (i > 0 ==> res == 0)); */
    /*@ assert (x == 0 ==> (i == 0 || res == 0)); */
    /*@ assert (x != 0 ==> res != 0); */
    /*@ assert (x != 0 ==> res != 0 || i == 0); */
    /*@ assert (res == x == 0 || res != 0); */
    /*@ assert (res == 1 || x == 0 || x != 0); */
    /*@ assert (res == 1 || x == 0 || res != 0); */
    /*@ assert (res == 1 || res == x || res != 0); */
    /*@ assert (res == 1 || res == 0 || x != 0); */
    /*@ assert (res == 1 || i > 0); */
    /*@ assert (res == 0 ==> x == 0); */
    /*@ assert (res != 0 || x == 0); */
    /*@ assert (res != 0 ==> x != 0 || i == 0); */
    /*@ assert (res != 0 ==> (x != 0 || i == 0)); */
    /*@ assert (n >= 0 || i == 0); */
    /*@ assert (n >= 0 ==> res != 0 || x == 0); */
    /*@ assert (n >= 0 ==> i <= n); */
    /*@ assert (n == 0 ==> res == 1); */
    /*@ assert (i > 0 ==> res == x || res == res); */
    /*@ assert (i > 0 ==> res == x || res != 0); */
    /*@ assert (i > 0 ==> res == 0 || res != 0); */
    /*@ assert (i > 0 ==> res != 0 || x == 0); */
    /*@ assert (i == n ==> res == res); */
    /*@ assert (i == 0 ==> res == 1); */
    /*@ assert (0 <= i); */
}

/*@ requires (x == x) && (x == 1 ==> res == 1) && (x == 0 || res != 0) && (x == 0 ==> res == 0 || i == 0) && (x == 0 ==> (i > 0 ==> res == 0)) && (x == 0 ==> (i == 0 || res == 0)) && (x != 0 ==> res != 0) && (x != 0 ==> res != 0 || i == 0) && (res == x == 0 || res != 0) && (res == 1 || x == 0 || x != 0) && (res == 1 || x == 0 || res != 0) && (res == 1 || res == x || res != 0) && (res == 1 || res == 0 || x != 0) && (res == 1 || i > 0) && (res == 0 ==> x == 0) && (res != 0 || x == 0) && (res != 0 ==> x != 0 || i == 0) && (res != 0 ==> (x != 0 || i == 0)) && (n >= 0 || i == 0) && (n >= 0 ==> res != 0 || x == 0) && (n >= 0 ==> i <= n) && (n == 0 ==> res == 1) && (i > 0 ==> res == x || res == res) && (i > 0 ==> res == x || res != 0) && (i > 0 ==> res == 0 || res != 0) && (i > 0 ==> res != 0 || x == 0) && (i == n ==> res == res) && (i == 0 ==> res == 1) && (0 <= i);
    assigns \nothing;
*/
void check_B_implies_A(int i, int n, int res, int x) {
    /*@ assert (0 <= i <= n); */
    /*@ assert (res == ipow(x, i)); */
}
