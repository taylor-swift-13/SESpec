#include <limits.h>

/*@ requires (0 <= i <= m) && (res == i * n) && (0 <= n);
    assigns \nothing;
*/
void check_A_implies_B(int *i, int m, int *n, int *res, int *sign, int x, int y) {
    /*@ assert (sign == 1 || sign == -1); */
    /*@ assert (sign == ((x < 0 ? -1 : 1) * (y < 0 ? -1 : 1))); */
    /*@ assert (sign * sign == 1); */
    /*@ assert (sign * res == sign * i * n); */
    /*@ assert (sign * res == ((x < 0 ? -1 : 1) * (y < 0 ? -1 : 1)) * res); */
    /*@ assert (sign * res == ((x < 0 ? -1 : 1) * (y < 0 ? -1 : 1)) * i * n); */
    /*@ assert (res == i * n); */
    /*@ assert (res <= m * n || res <= i * n); */
    /*@ assert (res <= m * n || i * n <= res); */
    /*@ assert (res <= m * n || i * n <= res + n); */
    /*@ assert (res <= m * n || 0 <= m - i); */
    /*@ assert (res <= i * n); */
    /*@ assert (res <= i * n || i * n <= res + n); */
    /*@ assert (res <= i * n + n); */
    /*@ assert (res <= (i + 1) * n); */
    /*@ assert (res <= (i + 1) * n || res <= m * n); */
    /*@ assert (res <= (i + 1) * n || res <= i * n); */
    /*@ assert (res <= (i + 1) * n || i * n <= res); */
    /*@ assert (res <= (i + 1) * n || i * n <= res + n); */
    /*@ assert (res <= (i + 1) * n || 0 <= m - i); */
    /*@ assert (res % 1 == 0); */
    /*@ assert (m >= 0 && n >= 0); */
    /*@ assert (i <= m); */
    /*@ assert (i <= m || res <= m * n); */
    /*@ assert (i <= m || res <= i * n); */
    /*@ assert (i <= m || res <= (i + 1) * n); */
    /*@ assert (i <= m || i * n <= res); */
    /*@ assert (i <= m || i * n <= res + n); */
    /*@ assert (i <= m || 0 <= m - i); */
    /*@ assert (i * n <= res); */
    /*@ assert (i * n <= res || res <= i * n); */
    /*@ assert (i * n <= res || i * n <= res + n); */
    /*@ assert (i * n <= res || 0 <= m - i); */
    /*@ assert (i * n <= res + n); */
    /*@ assert (0 <= res); */
    /*@ assert (0 <= n); */
    /*@ assert (0 <= m); */
    /*@ assert (0 <= m - i); */
    /*@ assert (0 <= m - i || res <= i * n); */
    /*@ assert (0 <= m - i || i * n <= res + n); */
    /*@ assert (0 <= m && 0 <= n); */
    /*@ assert (0 <= i); */
    /*@ assert ((n == 0) ==> res == 0); */
    /*@ assert ((m == 0) ==> res == 0); */
    /*@ assert ((i == 0) ==> res == 0); */
}

/*@ requires (sign == 1 || sign == -1) && (sign == ((x < 0 ? -1 : 1) * (y < 0 ? -1 : 1))) && (sign * sign == 1) && (sign * res == sign * i * n) && (sign * res == ((x < 0 ? -1 : 1) * (y < 0 ? -1 : 1)) * res) && (sign * res == ((x < 0 ? -1 : 1) * (y < 0 ? -1 : 1)) * i * n) && (res == i * n) && (res <= m * n || res <= i * n) && (res <= m * n || i * n <= res) && (res <= m * n || i * n <= res + n) && (res <= m * n || 0 <= m - i) && (res <= i * n) && (res <= i * n || i * n <= res + n) && (res <= i * n + n) && (res <= (i + 1) * n) && (res <= (i + 1) * n || res <= m * n) && (res <= (i + 1) * n || res <= i * n) && (res <= (i + 1) * n || i * n <= res) && (res <= (i + 1) * n || i * n <= res + n) && (res <= (i + 1) * n || 0 <= m - i) && (res % 1 == 0) && (m >= 0 && n >= 0) && (i <= m) && (i <= m || res <= m * n) && (i <= m || res <= i * n) && (i <= m || res <= (i + 1) * n) && (i <= m || i * n <= res) && (i <= m || i * n <= res + n) && (i <= m || 0 <= m - i) && (i * n <= res) && (i * n <= res || res <= i * n) && (i * n <= res || i * n <= res + n) && (i * n <= res || 0 <= m - i) && (i * n <= res + n) && (0 <= res) && (0 <= n) && (0 <= m) && (0 <= m - i) && (0 <= m - i || res <= i * n) && (0 <= m - i || i * n <= res + n) && (0 <= m && 0 <= n) && (0 <= i) && ((n == 0) ==> res == 0) && ((m == 0) ==> res == 0) && ((i == 0) ==> res == 0);
    assigns \nothing;
*/
void check_B_implies_A(int *i, int m, int *n, int *res, int *sign, int x, int y) {
    /*@ assert (0 <= i <= m); */
    /*@ assert (res == i * n); */
    /*@ assert (0 <= n); */
}
