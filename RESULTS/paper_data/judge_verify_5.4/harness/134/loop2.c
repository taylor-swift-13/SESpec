#include <limits.h>

/*@ requires (0 <= j <= n) && (res == i * n + j) && (0 <= i <= m) && (0 <= n);
    assigns \nothing;
*/
void check_A_implies_B(int i, int j, int m, int *n, int res, int *sign, int x, int y) {
    /*@ assert (sign == 1 || sign == -1); */
    /*@ assert (sign == ((x < 0 ? -1 : 1) * (y < 0 ? -1 : 1))); */
    /*@ assert (sign * sign == 1); */
    /*@ assert (res == i * n + j); */
    /*@ assert (res <= i * n + n); */
    /*@ assert (res <= i * n + n || i < m); */
    /*@ assert (res <= (i + 1) * n); */
    /*@ assert (res - j == i * n); */
    /*@ assert (res % 1 == 0); */
    /*@ assert (m >= 0 && n >= 0); */
    /*@ assert (j == res - i * n); */
    /*@ assert (j <= n); */
    /*@ assert (i <= m); */
    /*@ assert (i <= m); */
    /*@ assert (i <= m); */
    /*@ assert (i <= m); */
    /*@ assert (i <= m); */
    /*@ assert (i <= m); */
    /*@ assert (i <= m); */
    /*@ assert (i <= m); */
    /*@ assert (i <= m); */
    /*@ assert (i <= m); */
    /*@ assert (i <= m); */
    /*@ assert (i <= m); */
    /*@ assert (i <= m); */
    /*@ assert (i < m); */
    /*@ assert (i < m || n == 0); */
    /*@ assert (i < m || j == 0); */
    /*@ assert (i * n <= res); */
    /*@ assert (i * n <= res || res <= i * n + n); */
    /*@ assert (i * n <= res || i < m); */
    /*@ assert (0 <= res); */
    /*@ assert (0 <= n); */
    /*@ assert (0 <= m); */
    /*@ assert (0 <= j); */
    /*@ assert (0 <= i); */
}

/*@ requires (sign == 1 || sign == -1) && (sign == ((x < 0 ? -1 : 1) * (y < 0 ? -1 : 1))) && (sign * sign == 1) && (res == i * n + j) && (res <= i * n + n) && (res <= i * n + n || i < m) && (res <= (i + 1) * n) && (res - j == i * n) && (res % 1 == 0) && (m >= 0 && n >= 0) && (j == res - i * n) && (j <= n) && (i <= m) && (i <= m) && (i <= m) && (i <= m) && (i <= m) && (i <= m) && (i <= m) && (i <= m) && (i <= m) && (i <= m) && (i <= m) && (i <= m) && (i <= m) && (i < m) && (i < m || n == 0) && (i < m || j == 0) && (i * n <= res) && (i * n <= res || res <= i * n + n) && (i * n <= res || i < m) && (0 <= res) && (0 <= n) && (0 <= m) && (0 <= j) && (0 <= i);
    assigns \nothing;
*/
void check_B_implies_A(int i, int j, int m, int *n, int res, int *sign, int x, int y) {
    /*@ assert (0 <= j <= n); */
    /*@ assert (res == i * n + j); */
    /*@ assert (0 <= i <= m); */
    /*@ assert (0 <= n); */
}
