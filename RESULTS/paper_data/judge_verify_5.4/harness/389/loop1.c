#include <limits.h>

/*@ requires (n <= \at(n,Pre)) && (q == \at(q,Pre)) && ((\at(n,Pre) <= 0) ==> ((res == 0) && (n == \at(n,Pre)) && (q == \at(q,Pre)) && (p == \at(p,Pre))));
    assigns \nothing;
*/
void check_A_implies_B(int n, int p, int *q, int res) {
    /*@ assert (q == \at(q,Pre)); */
    /*@ assert (p / q == p / q); */
    /*@ assert (p % q == p % q); */
    /*@ assert (n > 0 ==> res >= 0 || res < 0); */
    /*@ assert (n > 0 ==> res == p / q || res != p / q); */
    /*@ assert (n <= p + q || n > p + q); */
    /*@ assert (n <= \at(n,Pre)); */
    /*@ assert (res >= 0 || res < 0); */
    /*@ assert (res == res); */
    /*@ assert (res == p / q || res != p / q); */
    /*@ assert (res == 0 || res >= 0 || res < 0); */
    /*@ assert (res == 0 || res != 0); */
    /*@ assert (q > 0 ==> p >= 0 || p < 0); */
    /*@ assert (q > 0 ==> p == 0 || p != 0); */
    /*@ assert (q > 0 ==> p < q || p >= q); */
    /*@ assert (q > 0 ==> p % q < q); */
    /*@ assert (q == q); */
    /*@ assert (q != 0 ==> res >= 0 || res < 0); */
    /*@ assert (q != 0 ==> res == p / q || res != p / q); */
    /*@ assert (q != 0 ==> p >= 0 || p < 0); */
    /*@ assert (q != 0 ==> p == q * (p / q) + p % q); */
    /*@ assert (q != 0 ==> p == q * (p / q) + (p % q)); */
    /*@ assert (q != 0 ==> p == p); */
    /*@ assert (q != 0 ==> p == 0 || p != 0); */
    /*@ assert (q != 0 ==> p == (p / q) * q + p % q); */
    /*@ assert (q != 0 ==> p == (p / q) * q + (p % q)); */
    /*@ assert (q != 0 ==> p / q >= 0 || p / q < 0); */
    /*@ assert (q != 0 ==> p / q == p / q); */
    /*@ assert (q != 0 ==> p / q == (p / q)); */
    /*@ assert (q != 0 ==> p - p % q == q * (p / q)); */
    /*@ assert (q != 0 ==> p - (p % q) == q * (p / q)); */
    /*@ assert (q != 0 ==> p % q == p - q * (p / q)); */
    /*@ assert (q != 0 ==> p % q < q || p % q >= q); */
    /*@ assert (q != 0 ==> 0 <= res || res < 0); */
    /*@ assert (q != 0 ==> 0 <= p % q || p % q < 0); */
    /*@ assert (q != 0 ==> (p / q) == (p / q)); */
    /*@ assert (p >= 0 || p < 0); */
    /*@ assert (p >= 0 && q > 0 ==> p < q || p >= q); */
    /*@ assert (p >= 0 && q > 0 ==> p % q < q); */
    /*@ assert (p == p); */
    /*@ assert (p == 0 || p != 0); */
    /*@ assert (p == (p / q) * q + p % q || q == 0); */
    /*@ assert (p < q || q <= p); */
    /*@ assert (p < q || p >= q); */
    /*@ assert (p % q < q || q <= 0); */
    /*@ assert (p % q < q || p % q >= q); */
    /*@ assert (n >= 0 || n < 0); */
    /*@ assert (n >= 0 ==> res >= 0 || res < 0); */
    /*@ assert (n >= 0 ==> res == p / q || res != p / q); */
    /*@ assert (n >= 0 ==> res == 0 || res != 0); */
    /*@ assert (n >= 0 ==> q == q); */
    /*@ assert (n >= 0 ==> p >= 0 || p < 0); */
    /*@ assert (n >= 0 ==> p == p); */
    /*@ assert (n >= 0 ==> p == 0 || p != 0); */
    /*@ assert (n >= 0 ==> p / q == (p / q)); */
    /*@ assert (n >= 0 ==> p % q < q || p % q >= q); */
    /*@ assert (n >= 0 ==> n == n); */
    /*@ assert (n >= 0 ==> n <= n); */
    /*@ assert (n >= 0 ==> n <= n + 1); */
    /*@ assert (n >= 0 ==> 0 <= res || res < 0); */
    /*@ assert (n >= 0 ==> 0 <= p % q || p % q < 0); */
    /*@ assert (n >= 0 && q > 0 ==> p % q < q); */
    /*@ assert (n > 0 || n <= 0); */
    /*@ assert (n > 0 ==> q == q); */
    /*@ assert (n > 0 ==> p >= 0 || p < 0); */
    /*@ assert (n > 0 ==> p == p); */
    /*@ assert (n > 0 ==> p % q < q || p % q >= q); */
    /*@ assert (n == n); */
    /*@ assert (n <= n); */
    /*@ assert (n <= n || res >= 0); */
    /*@ assert (n <= n || res == p / q); */
    /*@ assert (n <= n || q == q); */
    /*@ assert (n <= n || p >= 0); */
    /*@ assert (n <= n || p >= 0 || p < 0); */
    /*@ assert (n <= n || p == 0 || p != 0); */
    /*@ assert (n <= n || p == (p / q) * q + p % q); */
    /*@ assert (n <= n || n <= q + n); */
    /*@ assert (n <= n || n <= p + q); */
    /*@ assert (n <= n || 0 <= res); */
    /*@ assert (n <= n || 0 <= p); */
    /*@ assert (n <= n || 0 <= p % q || p % q < 0); */
    /*@ assert (n <= n || 0 <= n); */
    /*@ assert (n <= n || 0 <= n + res); */
    /*@ assert (n <= n + 1); */
    /*@ assert (n <= n && q == q); */
    /*@ assert (0 <= res || res < 0); */
    /*@ assert (0 <= res || 0 <= n); */
    /*@ assert (0 <= n || n < 0); */
    /*@ assert (0 <= n || 0 <= res); */
    /*@ assert (0 < q || n <= n); */
}

/*@ requires (q == \at(q,Pre)) && (p / q == p / q) && (p % q == p % q) && (n > 0 ==> res >= 0 || res < 0) && (n > 0 ==> res == p / q || res != p / q) && (n <= p + q || n > p + q) && (n <= \at(n,Pre)) && (res >= 0 || res < 0) && (res == res) && (res == p / q || res != p / q) && (res == 0 || res >= 0 || res < 0) && (res == 0 || res != 0) && (q > 0 ==> p >= 0 || p < 0) && (q > 0 ==> p == 0 || p != 0) && (q > 0 ==> p < q || p >= q) && (q > 0 ==> p % q < q) && (q == q) && (q != 0 ==> res >= 0 || res < 0) && (q != 0 ==> res == p / q || res != p / q) && (q != 0 ==> p >= 0 || p < 0) && (q != 0 ==> p == q * (p / q) + p % q) && (q != 0 ==> p == q * (p / q) + (p % q)) && (q != 0 ==> p == p) && (q != 0 ==> p == 0 || p != 0) && (q != 0 ==> p == (p / q) * q + p % q) && (q != 0 ==> p == (p / q) * q + (p % q)) && (q != 0 ==> p / q >= 0 || p / q < 0) && (q != 0 ==> p / q == p / q) && (q != 0 ==> p / q == (p / q)) && (q != 0 ==> p - p % q == q * (p / q)) && (q != 0 ==> p - (p % q) == q * (p / q)) && (q != 0 ==> p % q == p - q * (p / q)) && (q != 0 ==> p % q < q || p % q >= q) && (q != 0 ==> 0 <= res || res < 0) && (q != 0 ==> 0 <= p % q || p % q < 0) && (q != 0 ==> (p / q) == (p / q)) && (p >= 0 || p < 0) && (p >= 0 && q > 0 ==> p < q || p >= q) && (p >= 0 && q > 0 ==> p % q < q) && (p == p) && (p == 0 || p != 0) && (p == (p / q) * q + p % q || q == 0) && (p < q || q <= p) && (p < q || p >= q) && (p % q < q || q <= 0) && (p % q < q || p % q >= q) && (n >= 0 || n < 0) && (n >= 0 ==> res >= 0 || res < 0) && (n >= 0 ==> res == p / q || res != p / q) && (n >= 0 ==> res == 0 || res != 0) && (n >= 0 ==> q == q) && (n >= 0 ==> p >= 0 || p < 0) && (n >= 0 ==> p == p) && (n >= 0 ==> p == 0 || p != 0) && (n >= 0 ==> p / q == (p / q)) && (n >= 0 ==> p % q < q || p % q >= q) && (n >= 0 ==> n == n) && (n >= 0 ==> n <= n) && (n >= 0 ==> n <= n + 1) && (n >= 0 ==> 0 <= res || res < 0) && (n >= 0 ==> 0 <= p % q || p % q < 0) && (n >= 0 && q > 0 ==> p % q < q) && (n > 0 || n <= 0) && (n > 0 ==> q == q) && (n > 0 ==> p >= 0 || p < 0) && (n > 0 ==> p == p) && (n > 0 ==> p % q < q || p % q >= q) && (n == n) && (n <= n) && (n <= n || res >= 0) && (n <= n || res == p / q) && (n <= n || q == q) && (n <= n || p >= 0) && (n <= n || p >= 0 || p < 0) && (n <= n || p == 0 || p != 0) && (n <= n || p == (p / q) * q + p % q) && (n <= n || n <= q + n) && (n <= n || n <= p + q) && (n <= n || 0 <= res) && (n <= n || 0 <= p) && (n <= n || 0 <= p % q || p % q < 0) && (n <= n || 0 <= n) && (n <= n || 0 <= n + res) && (n <= n + 1) && (n <= n && q == q) && (0 <= res || res < 0) && (0 <= res || 0 <= n) && (0 <= n || n < 0) && (0 <= n || 0 <= res) && (0 < q || n <= n);
    assigns \nothing;
*/
void check_B_implies_A(int n, int p, int *q, int res) {
    /*@ assert (n <= \at(n,Pre)); */
    /*@ assert (q == \at(q,Pre)); */
    /*@ assert ((\at(n,Pre) <= 0) ==> ((res == 0) && (n == \at(n,Pre)) && (q == \at(q,Pre)) && (p == \at(p,Pre)))); */
}
